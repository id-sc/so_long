/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesainte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:11:48 by hesainte          #+#    #+#             */
/*   Updated: 2026/01/28 12:46:07 by hesainte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	enemy_is_walkable(t_game *g, int x, int y)
{
	if (x < 0 || y < 0 || x >= g->map.col || y >= g->map.row)
		return (0);
	return (g->map.grid[y][x] == '0' || g->map.grid[y][x] == 'P');
}

static void	update_enemy(t_game *g, t_enemy *e, int nx, int ny)
{
	g->map.grid[e->enemy_y][e->enemy_x] = '0';
	e->enemy_x = nx;
	e->enemy_y = ny;
	g->map.grid[ny][nx] = 'X';
	if (player_hits_enemy(g, g->player.player_x, g->player.player_y))
	{
		e->enemy_frame = 2;
		g->game_lost = 1;
		g->end_timer = 1;
		render_map(g);
		ft_printf("Ohoh ! Tu t'es fait attraper !\n");
	}
}

void	move_enemy(t_game *g)
{
	t_enemy	*e;
	int		d[2];
	int		n[2];

	e = g->enemies;
	while (e && !g->end_timer)
	{
		d[0] = (rand() % 2) * (rand() % 2 * 2 - 1);
		d[1] = (d[0] == 0) * (rand() % 2 * 2 - 1);
		n[0] = e->enemy_x + d[0];
		n[1] = e->enemy_y + d[1];
		if (n[0] < 0 || n[1] < 0 || n[0] >= g->map.col || n[1] >= g->map.row
			|| (g->map.grid[n[1]][n[0]] != '0'
			&& g->map.grid[n[1]][n[0]] != 'P'))
		{
			n[0] = e->enemy_x - d[0];
			n[1] = e->enemy_y - d[1];
		}
		if (enemy_is_walkable(g, n[0], n[1]))
			update_enemy(g, e, n[0], n[1]);
		e = e->next;
	}
}

int	player_hits_enemy(t_game *game, int x, int y)
{
	t_enemy	*enemy;

	enemy = game->enemies;
	while (enemy)
	{
		if (enemy->enemy_x == x && enemy->enemy_y == y)
		{
			enemy->enemy_frame = 2;
			return (1);
		}
		enemy = enemy->next;
	}
	return (0);
}
