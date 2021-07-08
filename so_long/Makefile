# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/13 16:04:02 by jupark            #+#    #+#              #
#    Updated: 2021/07/08 16:28:48 by jupark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MLX_DIR = ./minilibx_opengl_20191021

GCM = cc -L $(MLX_DIR) -lmlx -framework OpenGL -framework Appkit

NAME = solong

SRCS = main.c util.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(GCM) $^ -o $@


clean : 
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : clean all

.PHONY : all clean fclean re bonus
