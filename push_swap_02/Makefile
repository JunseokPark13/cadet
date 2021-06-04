# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/17 11:27:55 by jupark            #+#    #+#              #
#    Updated: 2021/06/04 20:10:32 by jupark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror


SRCS = push_main.c push_swap.c util.c list.c list2.c \
	   quick_sort.c temp_print.c tester.c\
	   ft_swap.c ft_push.c ft_rotate.c ft_rrotate.c \
	   sorting_two.c sorting_three.c sorting_three02.c sorting_three03.c \
	   sorting_five.c optimize.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean : 
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : clean all

.PHONY : all clean fclean re
