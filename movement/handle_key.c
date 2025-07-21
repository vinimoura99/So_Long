/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 13:11:04 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/06/27 12:17:36 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

static int	is_collision(t_game *g, int nx, int ny)
{
	int	i;

	if (g->map[ny][nx] == '1')
		return (1);
	if (g->map[ny][nx] == 'T')
	{
		ft_printf("\e[31mYou fell into a trap! Game Over.\e[0m\n");
		close_game(g);
	}
	i = 0;
	while (i < g->enemy_count)
	{
		if (g->enemies[i].x == nx && g->enemies[i].y == ny)
		{
			ft_printf("\e[31mYou were hit by an enemy! Game Over.\e[0m\n");
			close_game(g);
		}
		i++;
	}
	return (0);
}

static void	handle_tile_effects(t_game *g, int nx, int ny)
{
	if (g->map[ny][nx] == 'C')
	{
		g->collected++;
		g->map[ny][nx] = '0';
	}
	if (g->map[ny][nx] == 'E')
	{
		if (g->collected == g->total_collectibles)
		{
			ft_printf("\e[32mYou won! Congratulations!\e[0m\n");
			close_game(g);
		}
	}
}

static void	set_direction(int keycode, int *dx, int *dy, t_game *g)
{
	if (keycode == 119 || keycode == 65362)
	{
		*dy = -1;
		g->player_dir = DIR_UP;
	}
	else if (keycode == 115 || keycode == 65364)
	{
		*dy = 1;
		g->player_dir = DIR_DOWN;
	}
	else if (keycode == 97 || keycode == 65361)
	{
		*dx = -1;
		g->player_dir = DIR_LEFT;
	}
	else if (keycode == 100 || keycode == 65363)
	{
		*dx = 1;
		g->player_dir = DIR_RIGHT;
	}
}

int	handle_key(int keycode, t_game *g)
{
	int	dx;
	int	dy;
	int	nx;
	int	ny;

	if (keycode == 65307)
		close_game(g);
	dx = 0;
	dy = 0;
	set_direction(keycode, &dx, &dy, g);
	nx = g->player_x + dx;
	ny = g->player_y + dy;
	if (is_collision(g, nx, ny))
		return (0);
	handle_tile_effects(g, nx, ny);
	g->player_x = nx;
	g->player_y = ny;
	g->moves++;
	ft_printf("Moves: %d\n", g->moves);
	render_map(g);
	return (0);
}
