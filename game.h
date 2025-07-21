/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 18:27:31 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/06/27 14:34:57 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "mlx/mlx.h"
# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define TILE 32
# define DIR_DOWN 0
# define DIR_UP 1
# define DIR_LEFT 2
# define DIR_RIGHT 3

typedef struct s_enemy
{
	int		x;
	int		y;
	int		direction;
}			t_enemy;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		collected;
	int		total_collectibles;
	int		moves;
	int		game_over;
	void	*img_wall;
	void	*img_wall_top;
	void	*img_wall_bottom;
	void	*img_wall_left;
	void	*img_wall_right;
	void	*img_trap;
	void	*img_floor;
	void	*img_player[4];
	void	*img_chest;
	void	*img_door_closed;
	void	*img_door_open;
	void	*img_victory;

	int		player_dir;
	int		enemy_count;
	t_enemy	*enemies;
	void	*img_enemy[4];
}			t_game;

// Game functions
void		init_game(t_game *game, const char *map_path);
void		init_vars(t_game *game);
void		init_graphics(t_game *game, const char *map_path);
void		init_player_and_enemy_count(t_game *game);

// Init_Enemies functions
void		init_enemies(t_game *game);

// Utils functions
int			is_valid_char(char c);
int			ft_putnbr(int n);
int			ft_printf(const char *format, ...);
int			ft_putchar(char c);
int			ft_putstr(char *s);

// Main_utils functions
int			check_args(int argc);
const char	*get_basename(const char *filepath);
int			validate_filename(const char *basename);
int			start_game(const char *filepath);
void		*ft_calloc(size_t count, size_t size);

// Map_Utils functions
void		count_map_elements(t_game *game, int *player_count,
				int *collectible_count, int *exit_count);
void		verify_counts(int player_count, int collectible_count,
				int exit_count, t_game *g);
void		find_player_position(char **map, int *px, int *py);
int			**allocate_visited(int width, int height);
void		validate_paths(t_game *game);

// Validate_Map functions
void		dfs(t_game *g, int **visited, int x, int y);
void		validate_map(t_game *game);

// Player_Move functions
void		move_player(t_game *g, int dx, int dy, int dir);

// Enemy_Move functions
int			move_enemies(void *param);

// Handle_Key functions
int			handle_key(int keycode, t_game *g);

// Map_parse functions
void		parse_map_entities(t_game *g);
void		valid_map(char **map, t_game *game);

// Map_reader functions
char		**read_map(const char *file, t_game *game);

// Load_images functions
void		load_images(t_game *game);
void		*load_single_texture(t_game *game, char *path);

// Render functions
void		draw_tile(t_game *game, void *img, int x, int y);
void		render_map(t_game *game);
void		destroy_images(t_game *g);

// Render_utils functions
void		render_tile(t_game *g, int x, int y);
void		render_enemies_and_player(t_game *g);
void		render_moves_counter(t_game *g);

// Main  functions
int			close_game(t_game *game);

// Map functions
void		free_map(char **map);
int			count_collectibles(char **map);

// Functions_utils functions
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strrchr(const char *s, int c);
char		*ft_strdup(const char *s);
char		*ft_strchr(const char *s, int c);
int			handle_format(char format, va_list *args);

// Path_utils functions
void		free_visited(int **visited, int height);
void		check_all_paths(t_game *g, int **visited);
int			is_valid_map_char(char ch);
void		increment_counts(char ch, int *p, int *c, int *e);

// Move_utils functions
size_t		ft_strlen(const char *s);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_itoa(int n);

#endif