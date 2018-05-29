/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 02:23:48 by tadey             #+#    #+#             */
/*   Updated: 2018/05/29 02:23:50 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "kift.h"

		/***EXIT FUNCT***/

void	error(char *str)
{
	ft_putstr(str);
	exit(0);
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

int	create_config(cmd_ln_t **config)
{
	if ((*config = cmd_ln_init(NULL, ps_args(), TRUE,
	"-hmm", MODELDIR "/en-us/en-us",
	"-lm", MODELDIR "/en-us/en-us.lm.bin",
	"-dict", MODELDIR "/en-us/cmudict-en-us.dict",
	NULL)) == NULL)
		return (1);
	return (0);
}

		/***INIT STRUCT***/

void	init(t_config *config_stuct)
{
	config_stuct->read_voice = 0;
	config_stuct->score = 0;
	config_stuct->hypths = NULL;
	config_stuct->nsamp = 0;
	config_stuct->file = NULL;
}


/*
		***DECODER***
	1)	live audio input is platform based, hence just
			worrying abt decoding audio files.
	2)	the main pocketsphinx use case is to read audio data
			in blocks of memory from a source and feed it to
				the decoder
*/

int	init_decoder(ps_decoder_t **decoder, cmd_ln_t *config)
{
	if ((*decoder = ps_init(config)) == NULL)
		return (1);
	return (0);
}

/*
		***OPEN FILE***
	1)	opens the file
	2)	passing "rb" since opening a binary so that
			newline-translation doesn't mess data.
*/

int	open_parse(t_config *config_struct)
{
	if ((config_struct->file = fopen("goforward.raw", "rb")) == NULL)
		return (1);
	return (0);
}

/*
		***START & END OF DECODING***
	1)	first open the file and then start decoding the speech
			using ps_start_utt()
	2)	reading 512 bytes at a time from the file
	3)	then pass it to the the decoder ps_process_raw()
	4)	then we mark the end of the speech using ps_end_utt()
*/

void	start_end_decode(t_config *config_struct, ps_decoder_t *decoder,
	int16 *buff)
{
	config_struct->read_voice = ps_start_utt(decoder);
	while (!feof(config_struct->file))
	{
		config_struct->nsamp = fread(buff, 2, 512, config_struct->file);
		config_struct->read_voice = ps_process_raw(decoder, buff,
		config_struct->nsamp, FALSE, FALSE);
	}
	config_struct->read_voice = ps_end_utt(decoder);
}

/*
		***RESULT***
	1)	retreive the hypothesis to get our recognition result
	2)	print the string out
*/

void	retreive_and_print(t_config *config_struct, ps_decoder_t *decoder)
{
	config_struct->hypths = ps_get_hyp(decoder, &(config_struct->score));
	printf("Recognized: %s\n", config_struct->hypths);
}

/*
		***CLEAN_UP***
	1)	close the file
	2)	ps_free cleans up the decoder struct
	3)	cmd_ln_free_r cleans up the config struct
*/

void	clean_up(t_config *config_struct, cmd_ln_t *config,
	ps_decoder_t *decoder)
{
	fclose(config_struct->file);
	ps_free(decoder);
	cmd_ln_free_r(config);
}

int	main(int argc, char **argv)
{
	cmd_ln_t		*config;
	ps_decoder_t	*decoder;
	int16			buff[512];
	t_config		*config_struct;

	config = NULL;
	decoder = NULL;

	argc = 0;
	argv = NULL;
	config_struct = (t_config*)malloc(sizeof(t_config));
	init(config_struct);
	if (create_config(&config) == 1)
		error("Failed to create config objects.\n");
	if (init_decoder(&decoder, config) == 1)
		error("Failed to initialize the decoder.\n");
	if (open_parse(config_struct) == 1)
		error("Failed to open file.\n");
	start_end_decode(config_struct, decoder, buff);
	retreive_and_print(config_struct, decoder);
	clean_up(config_struct, config, decoder);
	return (0);
}
