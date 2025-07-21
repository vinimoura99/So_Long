/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:36:54 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/06/26 16:43:28 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

void	render_tile(t_game *g, int x, int y)
{
	draw_tile(g, g->img_floor, x, y);
	if (g->map[y][x] == '1')
		draw_tile(g, g->img_wall, x, y);
	else if (g->map[y][x] == 'C')
		draw_tile(g, g->img_chest, x, y);
	else if (g->map[y][x] == 'E')
	{
		if (g->collected == g->total_collectibles)
			draw_tile(g, g->img_door_open, x, y);
		else
			draw_tile(g, g->img_door_closed, x, y);
	}
	else if (g->map[y][x] == 'T')
		draw_tile(g, g->img_trap, x, y);
}

void	render_enemies_and_player(t_game *g)
{
	int	i;

	i = 0;
	while (i < g->enemy_count)
	{
		draw_tile(g, g->img_enemy[g->enemies[i].direction],
			g->enemies[i].x, g->enemies[i].y);
		i++;
	}
	draw_tile(g, g->img_player[g->player_dir], g->player_x, g->player_y);
}

void	render_moves_counter(t_game *g)
{
	char	*num_str;
	char	*moves_str;

	num_str = ft_itoa(g->moves);
	if (!num_str)
		return ;
	moves_str = ft_strjoin("Moves: ", num_str);
	free(num_str);
	if (!moves_str)
		return ;
	mlx_string_put(g->mlx, g->win, 10, 20, 0xFFFFFF, moves_str);
	free(moves_str);
}
