# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/17 11:27:55 by jupark            #+#    #+#              #
#    Updated: 2021/05/21 17:49:23 by jupark           ###   ########.fr        #
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

lib : 
	make all -C $(LIBFT)
	cp $(LIBFT)/$(LIBFT_A) $(NAME)
	make fclean -C $(LIBFT)

$(NAME) : lib $(OBJS)
	ar rc $@ $(OBJS)

clean : 
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : clean all

.PHONY : all clean fclean re
