/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 11:29:07 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/06/27 14:33:43 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

// check_args.c
int	check_args(int argc)
{
	if (argc != 2)
	{
		ft_printf("Uso: ./so_long <mapa.ber>\n");
		return (0);
	}
	return (1);
}

// get_basename.c
const char	*get_basename(const char *filepath)
{
	const char	*basename;

	basename = ft_strrchr(filepath, '/');
	if (basename)
		return (basename + 1);
	else
		return (filepath);
}

// validate_filename.c
int	validate_filename(const char *basename)
{
	const char	*dot;
	int			i;

	dot = ft_strrchr(basename, '.');
	if (!dot || dot == basename || ft_strcmp(dot, ".ber") != 0)
	{
		ft_printf("Erro: o arquivo deve ter a extensão .ber e nome válido.\n");
		return (0);
	}
	i = 0;
	while (&basename[i] != dot)
	{
		if (basename[i] == '.')
		{
			ft_printf("Erro: nome de arquivo inválido.\n");
			return (0);
		}
		i++;
	}
	return (1);
}

// start_game.c
int	start_game(const char *filepath)
{
	t_game	game;

	init_game(&game, filepath);
	mlx_loop_hook(game.mlx, move_enemies, &game);
	mlx_hook(game.win, 2, 1L << 0, handle_key, &game);
	mlx_hook(game.win, 17, 0L, close_game, &game);
	mlx_loop(game.mlx);
	return (0);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t			total_size;
	size_t			i;
	unsigned char	*ptr;

	total_size = count * size;
	ptr = (unsigned char *)malloc(total_size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < total_size)
	{
		ptr[i] = 0;
		i++;
	}
	return ((void *)ptr);
}
