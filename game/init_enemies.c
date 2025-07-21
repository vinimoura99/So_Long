/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_enemies.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 13:23:10 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/06/27 12:14:21 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

static void	assign_enemy(t_game *g, int x, int y, int *i)
{
	if (g->map[y][x] == 'I')
	{
		g->enemies[*i].x = x;
		g->enemies[*i].y = y;
		g->enemies[*i].direction = DIR_DOWN;
		(*i)++;
	}
}

void	init_enemies(t_game *g)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	y = 0;
	if (g->enemy_count == 0)
		return ;
	g->enemies = malloc(sizeof(t_enemy) * g->enemy_count);
	if (!g->enemies)
	{
		ft_printf("\033Malloc error for enemies.\n\033[0m");
		return ;
	}
	while (y < g->height)
	{
		x = 0;
		while (x < g->width)
		{
			assign_enemy(g, x, y, &i);
			x++;
		}
		y++;
	}
}
