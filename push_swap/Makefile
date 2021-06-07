# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/17 11:27:55 by jupark            #+#    #+#              #
#    Updated: 2021/06/07 20:30:14 by jupark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_P = push_swap
NAME_C = checker

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS_P = srcs_pushswap/push_main.c \
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
	   srcs_pushswap/ft_rrotate.c \
	   srcs_pushswap/ft_split.c \
	   srcs_pushswap/ft_strchr.c \
	   srcs_pushswap/input_parse.c

SRCS_C = srcs_checker/checker_main.c \
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
	   srcs_pushswap/ft_rrotate.c \
	   srcs_pushswap/ft_split.c \
	   srcs_pushswap/ft_strchr.c \
	   srcs_pushswap/input_parse.c   

OBJS_P = $(SRCS_P:.c=.o)
OBJS_C = $(SRCS_C:.c=.o)

all : $(NAME_P) $(NAME_C)

$(NAME_P) : $(OBJS_P)
	$(CC) $(CFLAGS) -o $@ $^

$(NAME_C) : $(OBJS_C)
	$(CC) $(CFLAGS) -o $@ $^

clean : 
	rm -f $(OBJS_P) $(OBJS_C)

fclean : clean
	rm -f $(NAME_P) $(NAME_C)

re : clean all

.PHONY : all clean fclean re
