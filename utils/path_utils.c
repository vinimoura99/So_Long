/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:52:08 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/06/27 12:20:37 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

void	free_visited(int **visited, int height)
{
	int	y;

	y = 0;
	while (y < height)
	{
		free(visited[y]);
		y++;
	}
	free(visited);
}

void	check_all_paths(t_game *g, int **visited)
{
	int	x;
	int	y;

	y = 0;
	while (y < g->height)
	{
		x = 0;
		while (x < g->width)
		{
			if ((g->map[y][x] == 'C' || g->map[y][x] == 'E') && !visited[y][x])
			{
				ft_printf("\e[31mError: Player cannot"
					" reach all collectibles/exit.\e[0m\n");
				free_visited(visited, g->height);
				close_game(g);
			}
			x++;
		}
		y++;
	}
}

int	is_valid_map_char(char ch)
{
	if (ch == '0' || ch == '1' || ch == 'P' || ch == 'C' || ch == 'E'
		|| ch == 'I' || ch == 'T')
		return (1);
	return (0);
}

void	increment_counts(char ch, int *p, int *c, int *e)
{
	if (ch == 'P')
		(*p)++;
	else if (ch == 'C')
		(*c)++;
	else if (ch == 'E')
		(*e)++;
}
