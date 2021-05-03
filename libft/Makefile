# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/03 15:27:37 by jupark            #+#    #+#              #
#    Updated: 2021/05/03 20:07:27 by jupark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_bzero.c ft_memset.c ft_strlen.c ft_memcpy.c \
	   ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
	   ft_strlcpy.c ft_strlcat.c

OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	ar rcs $(TARGET) $^

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: clean all

