/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesainte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:11:48 by hesainte          #+#    #+#             */
/*   Updated: 2026/01/27 19:16:58 by hesainte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_element(t_game *g, int x, int y)
{
	char	c;

	c = g->map.grid[y][x];
	mlx_put_image_to_window(g->mlx, g->win, g->img.floor, x * 64, y * 64);
	if (c == '1')
		mlx_put_image_to_window(g->mlx, g->win,
			g->img.wall[(x + y) % 3], x * 64, y * 64);
	else if (c == 'P')
		mlx_put_image_to_window(g->mlx, g->win,
			g->img.player[g->player.player_frame], x * 64, y * 64);
	else if (c == 'C')
		mlx_put_image_to_window(g->mlx, g->win,
			g->img.collect[g->img.collect_frame], x * 64, y * 64);
	else if (c == 'E')
		mlx_put_image_to_window(g->mlx, g->win,
			g->img.exit, x * 64, y * 64);
	else if (c == 'X')
		mlx_put_image_to_window(g->mlx, g->win,
			g->img.enemy[get_enemy_frame_at(g, x, y)], x * 64, y * 64);
}

void	load_images(t_game *game)
{
	game->img.floor = mlx_xpm_file_to_image(game->mlx,
			"img/wooden_floor.xpm", &game->img_w, &game->img_h);
	game->img.wall[0] = mlx_xpm_file_to_image(game->mlx,
			"img/1_wall.xpm", &game->img_w, &game->img_h);
	game->img.enemy[0] = mlx_xpm_file_to_image(game->mlx,
			"img/1_enemy.xpm", &game->img_w, &game->img_h);
	game->img.player[0] = mlx_xpm_file_to_image(game->mlx,
			"img/empty_player.xpm", &game->img_w, &game->img_h);
	game->img.collect[0] = mlx_xpm_file_to_image(game->mlx,
			"img/small_tapioca_collect.xpm", &game->img_w, &game->img_h);
	game->img.exit = mlx_xpm_file_to_image(game->mlx,
			"img/exit.xpm", &game->img_w, &game->img_h);
	game->img.victory = mlx_xpm_file_to_image(game->mlx,
			"img/victory.xpm", &game->img_w, &game->img_h);
	game->img.defeat = mlx_xpm_file_to_image(game->mlx,
			"img/defeat.xpm", &game->img_w, &game->img_h);
}

void	load_images_bonus(t_game *game)
{
	game->img.wall[1] = mlx_xpm_file_to_image(game->mlx,
			"img/2_wall.xpm", &game->img_w, &game->img_h);
	game->img.wall[2] = mlx_xpm_file_to_image(game->mlx,
			"img/3_wall.xpm", &game->img_w, &game->img_h);
	game->img.enemy[1] = mlx_xpm_file_to_image(game->mlx,
			"img/2_enemy.xpm", &game->img_w, &game->img_h);
	game->img.enemy[2] = mlx_xpm_file_to_image(game->mlx,
			"img/loose_enemy.xpm", &game->img_w, &game->img_h);
	game->img.player[1] = mlx_xpm_file_to_image(game->mlx,
			"img/1_pearl_player.xpm", &game->img_w, &game->img_h);
	game->img.player[2] = mlx_xpm_file_to_image(game->mlx,
			"img/2_pearl_player.xpm", &game->img_w, &game->img_h);
	game->img.player[3] = mlx_xpm_file_to_image(game->mlx,
			"img/3_pearl_player.xpm", &game->img_w, &game->img_h);
	game->img.player[4] = mlx_xpm_file_to_image(game->mlx,
			"img/4_pearl_player.xpm", &game->img_w, &game->img_h);
	game->img.player[5] = mlx_xpm_file_to_image(game->mlx,
			"img/5_pearl_player.xpm", &game->img_w, &game->img_h);
	game->img.player[6] = mlx_xpm_file_to_image(game->mlx,
			"img/win_player.xpm", &game->img_w, &game->img_h);
	game->img.collect[1] = mlx_xpm_file_to_image(game->mlx,
			"img/big_tapioca_collect.xpm", &game->img_w, &game->img_h);
}

void	render_map(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (++y < game->map.row)
	{
		x = -1;
		while (++x < game->map.col)
			draw_element(game, x, y);
	}
	draw_moves(game);
}

void	render_end_screen(t_game *game)
{
	int		x;
	int		y;
	void	*img;

	if (game->game_lost)
		img = game->img.defeat;
	else
		img = game->img.victory;
	y = 0;
	while (y < game->map.row * 64)
	{
		x = 0;
		while (x < game->map.col * 64)
		{
			mlx_put_image_to_window(game->mlx, game->win, img, x, y);
			x += 256;
		}
		y += 256;
	}
}
