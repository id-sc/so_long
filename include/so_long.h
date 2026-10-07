/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesainte <hesainte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 16:29:10 by hesainte          #+#    #+#             */
/*   Updated: 2026/10/07 10:19:04 by hesainte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <string.h>				//for strerror
# include <errno.h> 				//for errno
# include "../lib/mlx_linux/mlx.h"   	//for mlx linux
//#include "../minilibx/mlx.h"  	//for mlx mac
# include <time.h>
# include "get_next_line.h"
# include "../printf/include/ft_printf.h"

typedef struct s_check
{
	int	collect;
	int	exits;
	int	enemies;
}	t_check;

typedef struct s_map
{
	char	**grid;
	int		col;
	int		row;
	int		collect;
	int		exits;
	int		exit_x;
	int		exit_y;
	int		enemies;
	int		players;
}	t_map;

typedef struct s_player
{
	int	player_x;
	int	player_y;
	int	player_frame;
}	t_player;

typedef struct s_enemy
{
	int				enemy_x;
	int				enemy_y;
	int				enemy_frame;
	struct s_enemy	*next;
}	t_enemy;

typedef struct s_img
{
	void	*enemy[3];
	void	*wall[3];
	void	*player[7];
	void	*collect[2];
	void	*exit;
	void	*floor;
	void	*victory;
	void	*defeat;
	int		collect_frame;
}	t_img;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			end_timer;
	t_map		map;
	t_player	player;
	t_check		check_map;
	t_img		img;
	t_enemy		*enemies;
	int			game_lost;
	int			img_w;
	int			img_h;
	int			moves;
}	t_game;

//main.c
void	validate_map(t_game *game, char *file);
void	start_graphics(t_game *game);
int		handle_keypress(int keysym, t_game *game);

//enemies.c
void	init_enemy(t_enemy *enemy);
t_enemy	*new_enemy(int x, int y);
void	enemy_add_back(t_enemy **lst, t_enemy *new);
int		get_enemy_frame_at(t_game *game, int x, int y);
void	free_enemies(t_enemy *enemy);

//sprite.c
void	toggle_frame(t_game *game);
int		game_loop(t_game *game);

//move_player.c
void	move_player(t_game *g, int x, int y);
void	draw_moves(t_game *game);

//move_enemy.c
void	move_enemy(t_game *g);
int		player_hits_enemy(t_game *game, int x, int y);

//draw_images.c .
void	load_images(t_game *game);
void	load_images_bonus(t_game *game);
void	render_map(t_game *game);
void	render_end_screen(t_game *game);

//init_game.c
void	init_img(t_img *img);
void	init_player(t_player *player);
void	init_check(t_check *check);
void	init_map(t_map *map);
void	init_game(t_game *game);

// exit_game.c
void	error_exit(char *context, t_game *game, int is_system_error);
char	**free_tab(char **tab, int i);
char	**free_map(char **map);
int		close_game(t_game *game);
void	cleanup_images(t_game *game);

// get_map_elements.c
void	get_map_size(t_game *game, char *file);
void	get_grid(t_game *game, char *file);
int		find_player(t_game *game);
void	count_map_elements(t_game *game);
void	get_map_elements(char **map, t_game *game, int x, int y);

// check_errors.c
int		is_valid(char c);
void	check_enclosed(t_game *game);
void	check_map_elements(t_game *game);
void	check_characters(t_game *game);
void	check_ber_extention(t_game *game, char *file);

// utils.c
int		str_len(char *str);
char	*ft_strdup(const char *s);
char	**copy_grid(t_game *game);
char	*ft_itoa(int n);

#endif
