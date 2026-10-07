/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesainte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:11:48 by hesainte          #+#    #+#             */
/*   Updated: 2026/01/28 11:19:11 by hesainte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_enemy(t_enemy *enemy)
{
	enemy->enemy_x = -1;
	enemy->enemy_y = -1;
	enemy->enemy_frame = 0;
	enemy->next = NULL;
}

t_enemy	*new_enemy(int x, int y)
{
	t_enemy	*enemy;

	enemy = malloc(sizeof(t_enemy));
	if (!enemy)
		return (NULL);
	enemy->enemy_x = x;
	enemy->enemy_y = y;
	enemy->enemy_frame = 0;
	enemy->next = NULL;
	return (enemy);
}

void	enemy_add_back(t_enemy **lst, t_enemy *new)
{
	t_enemy	*tmp;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

int	get_enemy_frame_at(t_game *game, int x, int y)
{
	t_enemy	*tmp;

	tmp = game->enemies;
	while (tmp)
	{
		if (tmp->enemy_x == x && tmp->enemy_y == y)
			return (tmp->enemy_frame);
		tmp = tmp->next;
	}
	return (0);
}

void	free_enemies(t_enemy *enemy)
{
	t_enemy	*tmp;

	while (enemy)
	{
		tmp = enemy->next;
		free(enemy);
		enemy = tmp;
	}
}
