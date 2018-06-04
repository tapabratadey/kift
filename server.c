/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tadey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 15:30:27 by tadey             #+#    #+#             */
/*   Updated: 2018/05/28 13:54:10 by tadey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "kift.h"

void	error(char *str)
{
	ft_putstr(str);
	exit(0);
}

void	recv_from_client(int fd, t_server *server, char *buff)
{
	while ((server->ret_recv = recv(fd, buff, 4096, 0)) <= 0)
		;
	printf("Bytes received: %d\n", server->ret_recv);
	buff[server->ret_recv] = '\0';
	printf("Client command: %s\n", buff);
}

void	get_from_client(t_server *server, int fd)
{
	char	buff[4096];
	int		i;
	int		ret;

	i = 0;
	recv_from_client(fd, server, buff);
	if ((fd = open("pocketsphinx.wav",  O_CREAT |
	O_RDWR, S_IRUSR | S_IWUSR | S_IXUSR)) <= 0)
	{
		send(fd, "ERROR", ft_strlen("ERROR"), 0);
		return ;
	}
	recv(fd, &server->file_len, sizeof(off_t), 0);
	while (server->bytes_read < server->file_len)
	{
		if ((ret = recv(fd, buff, sizeof(buff), 0)) <= 0)
		{
			ft_putstr("fucking error\n");
			break ;
		}
		write(fd, buff, ret);
		server->bytes_read += ret;
	}
	pocket_sphinx(server);
}

void	server_loop(t_server *server)
{
	int					cli_fd;
	struct sockaddr_in	cli_addr;
	socklen_t			addr_len;
	int					in_client;

	listen(server->server_socket, 10);
	in_client = 1;
	addr_len = sizeof(cli_addr);
	while (1)
	{
		if ((cli_fd = accept(server->server_socket,
		(struct sockaddr *)&cli_addr, &addr_len)) < 0)
			error("Couldn't accept connection.\n");
		printf("Connection accepted.\n\n");
		// if (fork() == 0)
		// {
		// 	ft_putendl("Forking for client");
			while (in_client)
				get_from_client(server, cli_fd);
		// }
	}
}

void	create_client_server(t_server *server)
{
	struct sockaddr_in serv_addr;

	if ((server->server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		error("Couldn't create a socket.\n");
	printf("Server socket is created...\n");
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(server->port);
	if (bind(server->server_socket, (struct sockaddr *)&serv_addr,
	sizeof(serv_addr)) == -1)
	{
		printf("%s", strerror(errno));
		error("Couldn't bind to port.\n");
	}
	printf("Connected to port...\n");
	server_loop(server);
}

int		main(int argc, char **argv)
{
	t_server *server;
	(void)argc;
	server = (t_server *)malloc(sizeof(t_server));
	// if (argc != 2)
	// 	error("Usage: ./server <port>\n");
	server->port = ft_atoi(argv[1]);
	create_client_server(server);
	close(server->server_socket);
	return (0);
}
