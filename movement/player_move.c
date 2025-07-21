/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 13:09:37 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/06/27 09:40:02 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

void	move_player(t_game *g, int dx, int dy, int dir)
{
	int	nx;
	int	ny;

	nx = g->player_x + dx;
	ny = g->player_y + dy;
	if (g->map[ny][nx] == '1')
		return ;
	if (g->map[ny][nx] == 'C')
	{
		g->collected++;
		g->map[ny][nx] = '0';
	}
	if (g->map[ny][nx] == 'E' && g->collected == g->total_collectibles)
	{
		mlx_clear_window(g->mlx, g->win);
		g->game_over = 1;
		return ;
	}
	g->player_x = nx;
	g->player_y = ny;
	g->player_dir = dir;
	g->moves++;
	render_map(g);
}
