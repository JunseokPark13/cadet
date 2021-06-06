# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/17 11:27:55 by jupark            #+#    #+#              #
#    Updated: 2021/06/06 22:21:21 by jupark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = srcs_pushswap/push_main.c \
	   srcs_pushswap/ps_a_to_b.c \
	   srcs_pushswap/ps_b_to_a.c \
	   srcs_pushswap/util.c \
	   srcs_pushswap/list_init.c \
	   srcs_pushswap/list_clear.c \
	   srcs_pushswap/list_util.c \
	   srcs_pushswap/quick_sort.c \
	   srcs_pushswap/sorting_two.c \
	   srcs_pushswap/sorting_three.c \
	   srcs_pushswap/sorting_three02.c \
	   srcs_pushswap/sorting_three03.c \
	   srcs_pushswap/sorting_five.c \
	   srcs_pushswap/optimize.c \
	   srcs_pushswap/temp_print.c \
	   srcs_pushswap/tester.c \
	   srcs_pushswap/ft_swap.c \
	   srcs_pushswap/ft_push.c \
	   srcs_pushswap/ft_rotate.c \
	   srcs_pushswap/ft_rrotate.c
	   
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
