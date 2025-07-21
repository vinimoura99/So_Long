/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 18:31:53 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/06/27 12:16:38 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void	check_walls(t_game *g);

void	dfs(t_game *g, int **visited, int x, int y)
{
	if (x < 0 || x >= g->width || y < 0 || y >= g->height)
		return ;
	if (visited[y][x] || g->map[y][x] == '1' || g->map[y][x] == 'T')
		return ;
	visited[y][x] = 1;
	dfs(g, visited, x + 1, y);
	dfs(g, visited, x - 1, y);
	dfs(g, visited, x, y + 1);
	dfs(g, visited, x, y - 1);
}

void	validate_map(t_game *g)
{
	int	player_count;
	int	collectible_count;
	int	exit_count;

	player_count = 0;
	collectible_count = 0;
	exit_count = 0;
	count_map_elements(g, &player_count, &collectible_count, &exit_count);
	verify_counts(player_count, collectible_count, exit_count, g);
	check_walls(g);
	validate_paths(g);
}

static void	check_walls(t_game *g)
{
	int	x;
	int	y;

	x = 0;
	while (x < g->width)
	{
		if (g->map[0][x] != '1' || g->map[g->height - 1][x] != '1')
		{
			ft_printf("\e[31mError: The map must be"
				" surrounded by walls.\e[0m\n");
			close_game(g);
		}
		x++;
	}
	y = 0;
	while (y < g->height)
	{
		if (g->map[y][0] != '1' || g->map[y][g->width - 1] != '1')
		{
			ft_printf("\e[31mError: The map must"
				" be surrounded by walls.\e[0m\n");
			close_game(g);
		}
		y++;
	}
}
