/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 18:32:20 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/06/27 12:43:11 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

static int	can_move_to(t_game *g, int x, int y)
{
	char	c;

	c = g->map[y][x];
	if (c == '1' || c == 'T' || c == 'C' || c == 'E')
		return (0);
	return (1);
}

static void	move_enemy(t_game *g, int i)
{
	int	nx;
	int	ny;

	nx = g->enemies[i].x;
	ny = g->enemies[i].y;
	if (g->enemies[i].direction == DIR_UP)
		ny--;
	else if (g->enemies[i].direction == DIR_DOWN)
		ny++;
	else if (g->enemies[i].direction == DIR_LEFT)
		nx--;
	else if (g->enemies[i].direction == DIR_RIGHT)
		nx++;
	if (can_move_to(g, nx, ny))
	{
		g->enemies[i].x = nx;
		g->enemies[i].y = ny;
	}
	else
	{
		g->enemies[i].direction = rand() % 4;
	}
}

static int	check_collision_with_player(t_game *g, int i)
{
	if (g->enemies[i].x == g->player_x && g->enemies[i].y == g->player_y)
	{
		ft_printf("\033[31mYou were hit by an enemy! Game Over.\n\033[0m");
		close_game(g);
	}
	return (0);
}

static void	move_enemies_recursive(t_game *g, int i)
{
	if (i >= g->enemy_count)
		return ;
	move_enemy(g, i);
	check_collision_with_player(g, i);
	move_enemies_recursive(g, i + 1);
}

int	move_enemies(void *param)
{
	static int	frame_count = 0;
	t_game		*g;

	g = (t_game *)param;
	frame_count++;
	if (frame_count % 10000 != 0)
		return (0);
	move_enemies_recursive(g, 0);
	render_map(g);
	return (0);
}
