/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesainte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:11:48 by hesainte          #+#    #+#             */
/*   Updated: 2026/01/28 12:48:07 by hesainte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_collectible(t_game *g, int x, int y)
{
	if (g->map.grid[y][x] == 'C')
	{
		g->check_map.collect--;
		if (g->player.player_frame < 5)
			g->player.player_frame = (g->map.collect - g->check_map.collect)
				* 5 / g->map.collect;
	}
}

static void	handle_win(t_game *g, int nx, int ny)
{
	g->map.grid[ny][nx] = 'P';
	g->player.player_frame = 6;
	g->game_lost = 0;
	g->end_timer = 1;
	render_map(g);
	ft_printf("Bravo ! Le Bubble Tea est pret !\n");
}

static void	handle_loss(t_game *g, int nx, int ny)
{
	g->map.grid[ny][nx] = 'X';
	g->game_lost = 1;
	g->end_timer = 1;
	g->moves++;
	render_map(g);
	ft_printf("Oups ! Tu as fonce sur le chat !\n");
}

void	move_player(t_game *g, int x, int y)
{
	int	nx;
	int	ny;

	nx = g->player.player_x + x;
	ny = g->player.player_y + y;
	if (g->end_timer || g->map.grid[ny][nx] == '1'
		|| (g->check_map.collect > 0 && g->map.grid[ny][nx] == 'E'))
		return ;
	check_collectible(g, nx, ny);
	g->moves++;
	ft_printf("moves: %d\n", g->moves);
	g->map.grid[g->player.player_y][g->player.player_x] = '0';
	if (g->map.grid[ny][nx] == 'E' && g->check_map.collect == 0)
		return (handle_win(g, nx, ny));
	if (player_hits_enemy(g, nx, ny))
		return (handle_loss(g, nx, ny));
	g->map.grid[ny][nx] = 'P';
	g->player.player_x = nx;
	g->player.player_y = ny;
	toggle_frame(g);
	move_enemy(g);
	render_map(g);
}

void	draw_moves(t_game *game)
{
	char	*str;

	str = ft_itoa(game->moves);
	if (!str)
		return ;
	mlx_string_put(game->mlx, game->win, 10, 15, 0xFFFFFF, "Moves:");
	mlx_string_put(game->mlx, game->win, 80, 15, 0xFFFFFF, str);
	free(str);
}
