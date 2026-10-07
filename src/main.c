/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesainte <hesainte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 16:51:48 by hesainte          #+#    #+#             */
/*   Updated: 2026/10/07 10:18:18 by hesainte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	handle_keypress(int keysym, t_game *game)
{
	if (keysym == 119)
		move_player(game, 0, -1);
	if (keysym == 97)
		move_player(game, -1, 0);
	if (keysym == 115)
		move_player(game, 0, 1);
	if (keysym == 100)
		move_player(game, 1, 0);
	if (keysym == 65307)
		close_game(game);
	if (keysym == 65362)
		move_player(game, 0, -1);
	if (keysym == 65361)
		move_player(game, -1, 0);
	if (keysym == 65364)
		move_player(game, 0, 1);
	if (keysym == 65363)
		move_player(game, 1, 0);
	return (0);
}

void	validate_map(t_game *game, char *file)
{
	char	**map;

	init_game(game);
	check_ber_extention(game, file);
	get_map_size(game, file);
	get_grid(game, file);
	if (!find_player(game))
		error_exit("Player not found", game, 0);
	map = copy_grid(game);
	get_map_elements(map, game, game->player.player_y, game->player.player_x);
	free_map(map);
	count_map_elements(game);
	check_enclosed(game);
	check_characters(game);
	check_map_elements(game);
}

void	start_graphics(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return ;
	game->win = mlx_new_window(game->mlx, game->map.col * 64,
			game->map.row * 64, "so_long");
	mlx_hook(game->win, 17, 0, close_game, game);
	load_images(game);
	load_images_bonus(game);
	srand(time(NULL));
	render_map(game);
	mlx_hook(game->win, 2, 1L << 0, handle_keypress, game);
	mlx_loop_hook(game->mlx, game_loop, game);
	mlx_loop(game->mlx);
}

int	main(int argc, char *argv[])
{
	t_game	game;
	char	*file;

	(void)argc;
	file = "maps/level0.ber";
	if (argv[1])
		file = argv[1];
	validate_map(&game, file);
	start_graphics(&game);
}
