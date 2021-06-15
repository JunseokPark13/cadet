# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/13 16:04:02 by jupark            #+#    #+#              #
#    Updated: 2021/06/15 15:20:27 by jupark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME_S = server
NAME_C = client

SRCS_S = server.c minitalk_util.c
SRCS_SB = server_bonus.c minitalk_util_bonus.c
SRCS_C = client.c minitalk_util.c
SRCS_CB = client_bonus.c minitalk_util_bonus.c

OBJS_S = $(SRCS_S:.c=.o)
OBJS_C = $(SRCS_C:.c=.o)
OBJS_SB = $(SRCS_SB:.c=.o)
OBJS_CB = $(SRCS_CB:.c=.o)


ifdef WITH_BONUS
	OBJS_SS = $(OBJS_SB)
	OBJS_CC = $(OBJS_CB)
else
	OBJS_SS = $(OBJS_S)
	OBJS_CC = $(OBJS_C)
endif

all : $(NAME_S) $(NAME_C)

$(NAME_S) : $(OBJS_SS)
	$(CC) $(CFLAGS) -o $@ $^

$(NAME_C) : $(OBJS_CC)
	$(CC) $(CFLAGS) -o $@ $^

bonus :
	make WITH_BONUS=1 all

clean : 
	rm -f $(OBJS_S) $(OBJS_C) $(OBJS_SB) $(OBJS_CB)

fclean : clean
	rm -f $(NAME_S) $(NAME_C)

re : clean all

.PHONY : all clean fclean re bonus
