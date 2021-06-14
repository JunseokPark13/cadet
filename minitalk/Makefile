# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/13 16:04:02 by jupark            #+#    #+#              #
#    Updated: 2021/06/14 22:35:07 by jupark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_S = server
NAME_C = client

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS_S = server.c
SRCS_C = client.c

OBJS_S = $(SRCS_S:.c=.o)
OBJS_C = $(SRCS_C:.c=.o)

all : $(NAME_S) $(NAME_C)

$(NAME_S) : $(OBJS_S)
	$(CC) $(CFLAGS) -o $@ $^

$(NAME_C) : $(OBJS_C)
	$(CC) $(CFLAGS) -o $@ $^

clean : 
	rm -f $(OBJS_S) $(OBJS_C)

fclean : clean
	rm -f $(NAME_S) $(NAME_C)

re : clean all
