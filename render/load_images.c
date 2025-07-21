/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:27:55 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/06/27 11:03:10 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

void	*load_single_texture(t_game *game, char *path)
{
	void	*img;
	int		width;
	int		height;

	img = mlx_xpm_file_to_image(game->mlx, path, &width, &height);
	if (!img)
	{
		ft_printf("\e[31mError: Failed to load texture.\e[0m\n");
		write(2, path, ft_strlen(path));
		write(2, "\n", 1);
		close_game(game);
	}
	return (img);
}

static void	load_player_images(t_game *game)
{
	game->img_player[DIR_DOWN] = load_single_texture(game,
			"assets/player_down.xpm");
	if (!game->img_player[DIR_DOWN])
		close_game(game);
	game->img_player[DIR_UP] = load_single_texture(game,
			"assets/player_up.xpm");
	if (!game->img_player[DIR_UP])
		close_game(game);
	game->img_player[DIR_LEFT] = load_single_texture(game,
			"assets/player_left.xpm");
	if (!game->img_player[DIR_LEFT])
		close_game(game);
	game->img_player[DIR_RIGHT] = load_single_texture(game,
			"assets/player_right.xpm");
	if (!game->img_player[DIR_RIGHT])
		close_game(game);
}

static void	load_enemy_images(t_game *game)
{
	game->img_enemy[DIR_DOWN] = load_single_texture(game,
			"assets/enemy_down.xpm");
	if (!game->img_enemy[DIR_DOWN])
		close_game(game);
	game->img_enemy[DIR_UP] = load_single_texture(game, "assets/enemy_up.xpm");
	if (!game->img_enemy[DIR_UP])
		close_game(game);
	game->img_enemy[DIR_LEFT] = load_single_texture(game,
			"assets/enemy_left.xpm");
	if (!game->img_enemy[DIR_LEFT])
		close_game(game);
	game->img_enemy[DIR_RIGHT] = load_single_texture(game,
			"assets/enemy_right.xpm");
	if (!game->img_enemy[DIR_RIGHT])
		close_game(game);
}

static void	load_static_images(t_game *game)
{
	game->img_wall = load_single_texture(game, "assets/wall.xpm");
	if (!game->img_wall)
		close_game(game);
	game->img_floor = load_single_texture(game, "assets/floor.xpm");
	if (!game->img_floor)
		close_game(game);
	game->img_chest = load_single_texture(game, "assets/chest.xpm");
	if (!game->img_chest)
		close_game(game);
	game->img_trap = load_single_texture(game, "assets/trap.xpm");
	if (!game->img_trap)
		close_game(game);
	game->img_door_closed = load_single_texture(game, "assets/door_closed.xpm");
	if (!game->img_door_closed)
		close_game(game);
	game->img_door_open = load_single_texture(game, "assets/door_open.xpm");
	if (!game->img_door_open)
		close_game(game);
}

void	load_images(t_game *game)
{
	load_player_images(game);
	load_enemy_images(game);
	load_static_images(game);
	game->player_dir = DIR_DOWN;
}
