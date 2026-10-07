/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesainte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:11:48 by hesainte          #+#    #+#             */
/*   Updated: 2026/01/28 12:52:12 by hesainte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_img(t_img *img)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		img->player[i] = NULL;
		if (i < 3)
		{
			img->wall[i] = NULL;
			img->enemy[i] = NULL;
		}
		if (i < 2)
			img->collect[i] = NULL;
		i++;
	}
	img->floor = NULL;
	img->exit = NULL;
	img->victory = NULL;
	img->defeat = NULL;
	img->collect_frame = 0;
}

void	init_player(t_player *player)
{
	player->player_x = -1;
	player->player_y = -1;
	player->player_frame = 0;
}

void	init_check(t_check *check)
{
	check->collect = 0;
	check->exits = 0;
	check->enemies = 0;
}

void	init_map(t_map *map)
{
	map->grid = NULL;
	map->col = 0;
	map->row = 0;
	map->collect = 0;
	map->exits = 0;
	map->exit_x = -1;
	map->exit_y = -1;
	map->enemies = 0;
	map->players = 0;
}

void	init_game(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->moves = 0;
	game->end_timer = 0;
	init_map(&game->map);
	init_player(&game->player);
	init_check(&game->check_map);
	init_img(&game->img);
	game->enemies = NULL;
	game->game_lost = 0;
}
