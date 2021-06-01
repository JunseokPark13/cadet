# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sangcpar <sangcpar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/28 05:56:53 by sangcpar          #+#    #+#              #
#    Updated: 2021/05/28 05:56:55 by sangcpar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME2 = checker
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
LIB = ./libft/libft.a
LIB_PATH = ./libft
INCLUDES = -I ./libft -I ./includes
SRC_PATH = ./src
OBJ_PATH = ./obj

SRC_NAME =	push_swap.c	find_num.c	resolve.c swap_tool1.c \
			rotate_stack.c move_stack.c short_resolve.c rotate_stack2.c \
			args_chk.c

SRC_NAME2 =	checker.c	find_num.c	resolve.c swap_tool1.c \
			rotate_stack.c move_stack.c short_resolve.c rotate_stack2.c \
			args_chk.c

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_NAME2 = $(SRC_NAME2:.c=.o)
SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))
SRC2 = $(addprefix $(SRC_PATH)/, $(SRC_NAME2))
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))
OBJ2 = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME2))

all: $(NAME) $(NAME2)

$(NAME): $(OBJ)
	@make -C $(LIB_PATH)
	@$(CC) $(CFLAGS) $(OBJ) $(INCLUDES) $(LIB) -o $(NAME)
	@echo "[push_swap COMPILED]"

$(NAME2): $(OBJ2)
	@make -C $(LIB_PATH)
	@$(CC) $(CFLAGS) $(OBJ2) $(INCLUDES) $(LIB) -o $(NAME2)
	@echo "[checker COMPILED]"

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

clean:
	@make clean -C $(LIB_PATH)
	@rm -rf $(OBJ)
	@rm -rf $(OBJ2)
	@echo "all $(NAME) and $(NAME2) .o files are removed"

fclean: clean
	@make fclean -C $(LIB_PATH)
	@rm -f $(NAME) $(NAME2)
	@echo "$(NAME) and $(NAME2) is deleted"

re: fclean all

.PHONY: all, clean, fclean, re
