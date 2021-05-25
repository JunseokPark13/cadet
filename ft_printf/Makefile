# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/17 11:27:55 by jupark            #+#    #+#              #
#    Updated: 2021/05/25 12:00:58 by jupark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT = libft
LIBFT_A = libft.a

SRCS = ft_printf.c ft_printf_utils.c ft_writenum.c \
	   ft_writechar.c ft_writestr.c \
	   ft_nbr_to_base.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	make all -C $(LIBFT)
	cp $(LIBFT)/$(LIBFT_A) $(NAME)
	ar rc $@ $(OBJS)

clean : 
	rm -f $(OBJS)
	make clean -C $(LIBFT)

fclean : clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

re : clean all

.PHONY : all clean fclean re
