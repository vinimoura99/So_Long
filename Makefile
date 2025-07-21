# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/25 14:43:59 by vmoura-d          #+#    #+#              #
#    Updated: 2025/06/27 11:31:05 by vmoura-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC =	main.c  \
		utils/utils.c utils/map_utils.c utils/functions_utils.c \
		movement/enemy_move.c movement/handle_key.c movement/player_move.c \
		game/game.c game/init_enemies.c \
		map/map_parse.c map/map.c map/map_reader.c map/validate_map.c \
		render/render.c render/load_images.c render/render_utils.c \
		utils/path_utils.c \
		utils/move_utils.c utils/main_utils.c 

OBJ = $(SRC:.c=.o)

MLX_DIR = mlx
MLX_LIB = $(MLX_DIR)/libmlx.a
INCLUDES = -I$(MLX_DIR) -Iutils -Imovement -Igame -Imap -Irender
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11

all: $(MLX_LIB) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(MLX_FLAGS)

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR) all

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(MLX_DIR) clean || true

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

