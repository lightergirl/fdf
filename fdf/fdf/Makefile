# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eignatye <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/17 22:11:59 by eignatye          #+#    #+#              #
#    Updated: 2016/03/17 14:19:34 by eignatye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC_DIR = sources

FLAGS = -Wall -Wextra -Werror -o

SRC =	$(SRC_DIR)/main.c \
		$(SRC_DIR)/errors.c \
		$(SRC_DIR)/reader.c \
		$(SRC_DIR)/get_next_line.c \
		$(SRC_DIR)/draw_map.c \
		$(SRC_DIR)/init.c \
		$(SRC_DIR)/key_hooks.c \
		$(SRC_DIR)/modifiers.c

OBJ = $(SRC:.c=.o)

LIB_DIR = ./libft

SIERRA_MLX = ./minilibx_macos/libmlx.a

all: $(NAME)

$(NAME): $(OBJ)
		make -C $(LIB_DIR)
		gcc $(FLAGS) $(NAME) $(OBJ) $(LIB_DIR)/libft.a $(SIERRA_MLX) -framework OpenGL -framework AppKit


%.o: %.c
		gcc -c $(FLAGS) $@ $<

clean:
		rm -f $(OBJ)
		make clean -C $(LIB_DIR)

fclean: clean
		rm -f $(NAME)
		rm -f $(OBJ)
		make fclean -C $(LIB_DIR)

re:     fclean all
