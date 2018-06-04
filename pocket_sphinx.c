/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 02:23:48 by tadey             #+#    #+#             */
/*   Updated: 2018/05/31 19:08:10 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 **  ====================================================================
 **	Copyright (c) 1999-2010 Carnegie Mellon University.  All rights
 **	reserved.
 **
 **	Redistribution and use in source and binary forms, with or without
 **	modification, are permitted provided that the following conditions
 **	are met:
 **
 **	1.	Redistributions of source code must retain the above copyright
 **		notice, this list of conditions and the following disclaimer.
 **
 **	2.	Redistributions in binary form must reproduce the above copyright
 **		notice, this list of conditions and the following disclaimer in
 **		the documentation and/or other materials provided with the
 **		distribution.
 **
 **	This work was supported in part by funding from the Defense Advanced
 **	Research Projects Agency and the National Science Foundation of the
 **	United States of America, and the CMU Sphinx Speech Consortium.
 **
 **	THIS SOFTWARE IS PROVIDED BY CARNEGIE MELLON UNIVERSITY ``AS IS'' AND
 **	ANY EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 **	THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 **	PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL CARNEGIE MELLON UNIVERSITY
 **	NOR ITS EMPLOYEES BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 **	SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 **	LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 **	DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 **	THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 **	(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 **	OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 **
 **	====================================================================
 */

#include "kift.h"

void	error(char *str)
{
	ft_putstr(str);
	exit(0);
}

/*
 ***CLEAN_UP***
 1)	close the file
 2)	ps_free cleans up the decoder struct
 3)	cmd_ln_free_r cleans up the config struct
 */

void	clean_up()
{
	ps_free(g_ps);
	cmd_ln_free_r(g_config);
}

/*
 ***DECODER***
 1)	live audio input is platform based, hence just
 worrying abt decoding audio files.
 2)	the main pocketsphinx use case is to read audio data
 in blocks of memory from a source and feed it to
 the decoder
 */

int	init_decoder()
{
	if ((g_ps = ps_init(g_config)) == NULL)
	{
		cmd_ln_free_r(g_config);
		return (1);
	}
	return (0);
}

/*
 ***CREATE CONFIGURATION***
 1)	create a config object
 2)	takes a var number of null-terminated string args
 3)	second arg is array of arg definition.
 4)	standard set can be obtained by calling ps_args()
 5)	third arg is TRUE which means that duplicate args or
 unknown args will cause the parsing process to fail
 6)	MODELDIR macros is defined on the gcc command-line by
 using the pkg-config to obtain the modeldir var
 from PocketSphinx configuration.
 */

int	create_config()
{
	if ((g_config = cmd_ln_init(NULL, ps_args(), TRUE,
					"-hmm", MODELDIR "/en-us/en-us",
					"-lm", "./model/acoustic_model.lm",
					"-dict", "./model/acoustic_model.dict", NULL)) == NULL)
		return (1);
	return (0);
}

static void	print_word_times(t_config *config_struct)
{
	config_struct->frame_rate = cmd_ln_int32_r(g_config, "-frate");
	config_struct->iter = ps_seg_iter(g_ps);
	while (config_struct->iter != NULL)
	{
		ps_seg_frames(config_struct->iter, &config_struct->sf,
				&config_struct->ef);
		config_struct->pprob = ps_seg_prob(config_struct->iter, NULL,
				NULL, NULL);
		config_struct->conf = logmath_exp(ps_get_logmath(g_ps),
				config_struct->pprob);
		printf("%s %.3f %.3f %f\n", ps_seg_word(config_struct->iter),
				((float)config_struct->sf / config_struct->frame_rate),
				((float)config_struct->ef / config_struct->frame_rate),
				config_struct->conf);
		config_struct->iter = ps_seg_next(config_struct->iter);
	}
}

static void	recognize_get_speech(t_server *server, t_config *config_struct)
{
	ps_process_raw(g_ps, config_struct->adbuf, config_struct->k, FALSE, FALSE);
	config_struct->in_speech = ps_get_in_speech(g_ps);
	if (config_struct->in_speech && !(config_struct->utt_started))
		config_struct->utt_started = TRUE;
	if (!(config_struct->in_speech) && config_struct->utt_started)
	{
		ps_end_utt(g_ps);
		config_struct->hyp = ps_get_hyp(g_ps, NULL);
		if (config_struct->hyp != NULL)
		{
			printf("%s\n", config_struct->hyp);
			server->size_of_reply = strlen(config_struct->hyp);
			strncpy(server->reply, config_struct->hyp,
					server->size_of_reply);
		}
		if (config_struct->print_times)
			print_word_times(config_struct);
		fflush(stdout);
		ps_start_utt(g_ps);
		config_struct->utt_started = FALSE;
	}
}

static void	recognize_start_decoding(t_server *server, t_config *config_struct)
{
	config_struct->utt_started = FALSE;
	while ((config_struct->k = fread(config_struct->adbuf, sizeof(int16),
					2048, g_rawfd)) > 0)
		recognize_get_speech(server, config_struct);
}

static int check_wav_header(char *header, int expected_sr)
{
	int sr;
	if (header[34] != 0x10) {
		E_ERROR("Input audio file has [%d] bits per sample instead of 16\n", header[34]);
		return 0;
	}
	if (header[20] != 0x1) {
		E_ERROR("Input audio file has compression [%d] and not required PCM\n", header[20]);
		return 0;
	}
	if (header[22] != 0x1) {
		E_ERROR("Input audio file has [%d] channels, expected single channel mono\n", header[22]);
		return 0;
	}
	sr = ((header[24] & 0xFF) | ((header[25] & 0xFF) << 8) | ((header[26] & 0xFF) << 16) | ((header[27] & 0xFF) << 24));
	if (sr != expected_sr) {
		E_ERROR("Input audio file has sample rate [%d], but decoder expects [%d]\n", sr, expected_sr);
		return 0;
	}
	return 1;
}

static void	recognize_file_parse(const char *fname)
{
	char	waveheader[44];

	if ((g_rawfd = fopen(fname, "rb")) == NULL)
		E_FATAL_SYSTEM("Failed to open file '%s' for reading", fname);
	if (strlen(fname) > 4 && strcmp(fname + strlen(fname) - 4, ".wav") == 0)
	{
		fread(waveheader, 1, 44, g_rawfd);
		if (!check_wav_header(waveheader,
					(int)cmd_ln_float32_r(g_config, "-samprate")))
			E_FATAL("Failed to process file '%s' due to format mismatch.\n", fname);
	}
	if (strlen(fname) > 4 && strcmp(fname + strlen(fname) - 4, ".mp3") == 0)
		E_FATAL("Can not decode mp3 files, convert input file to WAV 16kHz 16-bit mono before decoding.\n");
}

static void	recognize_from_file(const char *fname, t_server *server)
{
	t_config		*config_struct;

	config_struct = (t_config*)malloc(sizeof(t_config));
	config_struct->print_times = cmd_ln_boolean_r(g_config, "-time");
	recognize_file_parse(fname);
	ps_start_utt(g_ps);
	recognize_start_decoding(server, config_struct);
	ps_end_utt(g_ps);
	if (config_struct->utt_started)
	{
		config_struct->hyp = ps_get_hyp(g_ps, NULL);
		if (config_struct->hyp != NULL)
		{
			printf("%s\n", config_struct->hyp);
			server->size_of_reply = strlen(config_struct->hyp);
			strncpy(server->reply, config_struct->hyp, server->size_of_reply);
			if (config_struct->print_times)
				print_word_times(config_struct);
		}
	}
	fclose(g_rawfd);
}

int	main(int argc, char **argv)
{
	t_server *server;

	server = (t_server*)malloc(sizeof(t_server));
	if (create_config() == 1)
		error("Failed to create config objects.\n");
	if (init_decoder() == 1)
		error("Failed to initialize the decoder.\n");
	if(argc == 2)
	{
		recognize_from_file(argv[1], server);
		printf("server->reply: %s\n", server->reply);
	}
	clean_up();
	return (0);
}
