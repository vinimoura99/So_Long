/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 13:41:56 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/06/26 15:25:52 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

static int	count_enemies(t_game *g)
{
	int	count;
	int	x;
	int	y;

	count = 0;
	y = 0;
	while (y < g->height)
	{
		x = 0;
		while (x < g->width)
		{
			if (g->map[y][x] == 'X')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

static void	assign_entity(t_game *g, int x, int y, int *enemy_idx)
{
	if (g->map[y][x] == 'P')
	{
		g->player_x = x;
		g->player_y = y;
	}
	else if (g->map[y][x] == 'X')
	{
		g->enemies[*enemy_idx].x = x;
		g->enemies[*enemy_idx].y = y;
		g->enemies[*enemy_idx].direction = DIR_DOWN;
		(*enemy_idx)++;
	}
}

static void	init_entities_positions(t_game *g)
{
	int	x;
	int	y;
	int	enemy_idx;

	enemy_idx = 0;
	y = 0;
	while (y < g->height)
	{
		x = 0;
		while (x < g->width)
		{
			assign_entity(g, x, y, &enemy_idx);
			x++;
		}
		y++;
	}
}

void	parse_map_entities(t_game *g)
{
	g->enemy_count = count_enemies(g);
	if (g->enemy_count > 0)
	{
		g->enemies = malloc(sizeof(t_enemy) * g->enemy_count);
		if (!g->enemies)
		{
			free_map(g->map);
			ft_printf("\e[31mMemory allocation error for enemies\e[0m\n");
		}
	}
	init_entities_positions(g);
}

void	valid_map(char **map, t_game *game)
{
	int	i;

	if (game->height == 0)
	{
		ft_printf("\e[31mError: The map is empty.\e[0m\n");
		free_map(map);
		exit(1);
	}
	game->width = strlen(map[0]);
	i = 1;
	while (i < game->height)
	{
		if (strlen(map[i]) != (size_t)game->width)
		{
			ft_printf("\e[31mError: The map is not rectangular.\e[0m\n");
			free_map(map);
			exit(1);
		}
		i++;
	}
}
