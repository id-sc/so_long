/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesainte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 15:01:41 by hesainte          #+#    #+#             */
/*   Updated: 2026/01/28 12:54:19 by hesainte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	toggle_frame(t_game *game)
{
	t_enemy	*enemy;

	game->img.collect_frame = (game->img.collect_frame + 1) % 2;
	enemy = game->enemies;
	while (enemy)
	{
		enemy->enemy_frame = (enemy->enemy_frame + 1) % 2;
		enemy = enemy->next;
	}
}

int	game_loop(t_game *game)
{
	static int	frames = 0;

	if (game->end_timer > 0)
	{
		frames++;
		if (frames > 30000)
			render_end_screen(game);
		if (frames > 40000)
			close_game(game);
	}
	return (0);
}
