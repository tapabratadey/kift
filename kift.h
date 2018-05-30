/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kift.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 04:23:21 by tadey             #+#    #+#             */
/*   Updated: 2018/05/29 04:23:23 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef KIFT_H
# define KIFT_H
#include "libft/libft.h"
#include <assert.h>
#include <sys/select.h>
#include <sphinxbase/err.h>
#include <sphinxbase/ad.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/socket.h>
# include <sys/types.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <sys/param.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
#include "pocketsphinx.h"

typedef struct s_config
{
	const char	*hyp;
	int16		adbuf[2048];
	int32		k;
	uint8		utt_started;
	uint8		in_speech;
	int32		print_times;
	float		conf;
	int			frame_rate;
	ps_seg_t	*iter;
	int32		sf;
	int32		ef;
	int32		pprob;
}				t_config;

typedef struct		s_server
{
	int		server_socket;
	int		port;
	int		ret_recv;
	char	*pwd;
	char	*if_ls;
	char	*read_buff;
	off_t	file_len;
	off_t	bytes_read;
	char	reply[4096];
	int		size_of_reply;
}					t_server;

static ps_decoder_t *g_ps;
static cmd_ln_t *g_config;
static FILE *g_rawfd;

int	pocket_sphinx(t_server *server);
void	error(char *str);

#endif
