/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 18:31:53 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/06/27 14:40:06 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

void	init_game(t_game *game, const char *map_path)
{
	init_vars(game);
	init_graphics(game, map_path);
	init_player_and_enemy_count(game);
	init_enemies(game);
	load_images(game);
	render_map(game);
}

void	init_vars(t_game *g)
{
	int	i;

	g->mlx = NULL;
	g->win = NULL;
	g->map = NULL;
	g->enemies = NULL;
	g->img_wall = NULL;
	g->img_floor = NULL;
	g->img_chest = NULL;
	g->img_trap = NULL;
	g->img_door_closed = NULL;
	g->img_door_open = NULL;
	g->img_victory = NULL;
	i = 0;
	while (i < 4)
	{
		g->img_player[i] = NULL;
		g->img_enemy[i] = NULL;
		i++;
	}
	g->moves = 0;
	g->collected = 0;
	g->game_over = 0;
	g->enemy_count = 0;
}

void	init_graphics(t_game *game, const char *map_path)
{
	game->mlx = mlx_init();
	game->map = read_map(map_path, game);
	if (!game->map)
	{
		close_game(game);
	}
	game->total_collectibles = count_collectibles(game->map);
	game->win = mlx_new_window(game->mlx, game->width * TILE, game->height
			* TILE, "So long");
	validate_map(game);
}

void	init_player_and_enemy_count(t_game *g)
{
	int	x;
	int	y;

	y = 0;
	while (y < g->height)
	{
		x = 0;
		while (x < g->width)
		{
			if (g->map[y][x] == 'P')
			{
				g->player_x = x;
				g->player_y = y;
			}
			else if (g->map[y][x] == 'I')
				g->enemy_count++;
			x++;
		}
		y++;
	}
}
