# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tadey <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/29 03:41:17 by tadey             #+#    #+#              #
#    Updated: 2018/05/29 03:41:18 by tadey            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = easy
CC = gcc
LIBFT = -L libft/ -lft
SRC = pocket_sphinx.c
FLAGS = -Wall -Wextra -Werror

all:
	$(CC) $(FLAGS) $(LIBFT) $(SRC) -o $(NAME) \
	-DMODELDIR=\"`pkg-config --variable=modeldir pocketsphinx`\" \
	`pkg-config --cflags --libs pocketsphinx sphinxbase` \

fclean:
	rm -rf $(NAME)

re: fclean all
