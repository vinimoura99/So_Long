/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:09:14 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/06/27 12:42:39 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

static ssize_t	read_file_to_buffer(const char *file, char *buffer,
		size_t bufsize)
{
	int		fd;
	ssize_t	size;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	size = read(fd, buffer, bufsize - 1);
	close(fd);
	if (size <= 0)
		return (-1);
	buffer[size] = '\0';
	return (size);
}

static char	**buffer_to_map(char *buffer, int *out_height)
{
	char	**map;
	char	*line_start;
	char	*line_end;
	int		i;

	line_start = buffer;
	i = 0;
	map = malloc(sizeof(char *) * 1000);
	if (!map)
		return (NULL);
	line_end = ft_strchr(line_start, '\n');
	while (line_end)
	{
		*line_end = '\0';
		map[i++] = ft_strdup(line_start);
		line_start = line_end + 1;
		line_end = ft_strchr(line_start, '\n');
	}
	if (*line_start)
		map[i++] = ft_strdup(line_start);
	map[i] = NULL;
	*out_height = i;
	return (map);
}

static int	check_map_is_rectangular(t_game *game)
{
	int	i;

	game->width = ft_strlen(game->map[0]);
	i = 1;
	while (i < game->height)
	{
		if ((int)ft_strlen(game->map[i]) != game->width)
		{
			ft_printf("\e[31mError: The map is not rectangular.\e[0m\n");
			free_map(game->map);
			return (0);
		}
		i++;
	}
	return (1);
}

char	**read_map(const char *file, t_game *game)
{
	char	buffer[10000];
	ssize_t	size;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_printf("Error: Can't open map.\n"), NULL);
	size = read_file_to_buffer(file, buffer, sizeof(buffer));
	close(fd);
	if (size == -1)
		return (ft_printf("Error: Can't read map or it's empty.\n"), NULL);
	game->map = buffer_to_map(buffer, &game->height);
	if (!game->map)
		return (ft_printf("Error: Allocation failed.\n"), NULL);
	if (game->height <= 0)
		return (ft_printf("Error: Map is empty.\n"), free_map(game->map), NULL);
	if (!check_map_is_rectangular(game))
		return (NULL);
	return (game->map);
}
