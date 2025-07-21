/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 18:27:18 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/06/27 12:12:44 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	close_game(t_game *g)
{
	if (!g)
		exit(0);
	destroy_images(g);
	if (g->win)
		mlx_destroy_window(g->mlx, g->win);
	if (g->mlx)
	{
		mlx_destroy_display(g->mlx);
		free(g->mlx);
	}
	if (g->map)
	{
		free_map(g->map);
		g->map = NULL;
	}
	if (g->enemies)
	{
		free(g->enemies);
		g->enemies = NULL;
	}
	exit(0);
}

int	main(int argc, char **argv)
{
	const char	*filepath;
	const char	*basename;

	if (!check_args(argc))
		return (1);
	filepath = argv[1];
	basename = get_basename(filepath);
	if (!validate_filename(basename))
		return (1);
	return (start_game(filepath));
}
