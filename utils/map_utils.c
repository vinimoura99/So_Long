/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 18:31:53 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/06/27 14:35:11 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	count_map_elements(t_game *g, int *p, int *c, int *e)
{
	int		y;
	int		x;
	char	ch;

	y = 0;
	while (y < g->height)
	{
		x = 0;
		while (x < g->width)
		{
			ch = g->map[y][x];
			if (!is_valid_map_char(ch))
			{
				ft_printf("\e[31mError: Map contains"
					" invalid characters.\e[0m\n");
				close_game(g);
			}
			increment_counts(ch, p, c, e);
			x++;
		}
		y++;
	}
}

void	verify_counts(int player_count, int collectible_count, int exit_count,
		t_game *g)
{
	if (player_count != 1)
	{
		ft_printf("\e[31mError: The map must contain exactly"
			" one player ('P').\e[0m\n");
		close_game(g);
	}
	if (collectible_count < 1)
	{
		ft_printf("\e[31mError: The map must contain at least"
			" one collectible ('C').\e[0m\n");
		close_game(g);
	}
	if (exit_count < 1)
	{
		ft_printf("\e[31mError: The map must contain at least"
			" one exit ('E').\e[0m\n");
		close_game(g);
	}
}

void	find_player_position(char **map, int *px, int *py)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				*px = x;
				*py = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

int	**allocate_visited(int width, int height)
{
	int	**visited;
	int	y;

	visited = malloc(sizeof(int *) * height);
	if (!visited)
		return (NULL);
	y = 0;
	while (y < height)
	{
		visited[y] = ft_calloc(width, sizeof(int));
		if (!visited[y])
		{
			while (--y >= 0)
				free(visited[y]);
			free(visited);
			return (NULL);
		}
		y++;
	}
	return (visited);
}

void	validate_paths(t_game *g)
{
	int	px;
	int	py;
	int	**visited;

	px = -1;
	py = -1;
	find_player_position(g->map, &px, &py);
	if (px == -1)
	{
		ft_printf("\033[31mError: Player 'P' not found"
			" on the map.\n\033[0m");
		close_game(g);
	}
	visited = allocate_visited(g->width, g->height);
	dfs(g, visited, px, py);
	check_all_paths(g, visited);
	free_visited(visited, g->height);
}
