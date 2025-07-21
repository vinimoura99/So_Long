/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 18:32:10 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/06/26 16:45:28 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"
#include <stdio.h>

void	render_map(t_game *g)
{
	int	x;
	int	y;

	y = 0;
	while (g->map[y])
	{
		x = 0;
		while (g->map[y][x])
		{
			render_tile(g, x, y);
			x++;
		}
		y++;
	}
	render_enemies_and_player(g);
	render_moves_counter(g);
}

void	draw_tile(t_game *g, void *img, int x, int y)
{
	mlx_put_image_to_window(g->mlx, g->win, img, x * TILE, y * TILE);
}

static void	destroy_images_array(t_game *g, int i)
{
	if (i >= 4)
		return ;
	if (g->img_player[i])
		mlx_destroy_image(g->mlx, g->img_player[i]);
	if (g->img_enemy[i])
		mlx_destroy_image(g->mlx, g->img_enemy[i]);
	destroy_images_array(g, i + 1);
}

void	destroy_images(t_game *g)
{
	destroy_images_array(g, 0);
	if (g->img_wall)
		mlx_destroy_image(g->mlx, g->img_wall);
	if (g->img_floor)
		mlx_destroy_image(g->mlx, g->img_floor);
	if (g->img_chest)
		mlx_destroy_image(g->mlx, g->img_chest);
	if (g->img_trap)
		mlx_destroy_image(g->mlx, g->img_trap);
	if (g->img_door_closed)
		mlx_destroy_image(g->mlx, g->img_door_closed);
	if (g->img_door_open)
		mlx_destroy_image(g->mlx, g->img_door_open);
}
