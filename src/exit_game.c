/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesainte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 16:08:13 by hesainte          #+#    #+#             */
/*   Updated: 2026/01/28 12:53:38 by hesainte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_exit(char *context, t_game *game, int is_system_error)
{
	if (is_system_error)
		ft_printf("Error\n%s: %s\n", context, strerror(errno));
	else
		ft_printf("%s", context);
	if (game->mlx)
		close_game(game);
	exit(1);
}

char	**free_tab(char **tab, int i)
{
	while (i >= 0)
		free(tab[i--]);
	free(tab);
	return (NULL);
}

char	**free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
	return (NULL);
}

void	cleanup_images(t_game *game)
{
	int	i;

	i = 0;
	if (!game)
		return ;
	while (i < 7)
	{
		if (game->img.player[i])
			mlx_destroy_image(game->mlx, game->img.player[i]);
		if (i < 3 && game->img.wall[i])
			mlx_destroy_image(game->mlx, game->img.wall[i]);
		if (i < 3 && game->img.enemy[i])
			mlx_destroy_image(game->mlx, game->img.enemy[i]);
		if (i < 2 && game->img.collect[i])
			mlx_destroy_image(game->mlx, game->img.collect[i]);
		i++;
	}
}

int	close_game(t_game *game)
{
	if (!game)
		return (0);
	cleanup_images(game);
	free_enemies(game->enemies);
	if (game->img.exit)
		mlx_destroy_image(game->mlx, game->img.exit);
	if (game->img.victory)
		mlx_destroy_image(game->mlx, game->img.victory);
	if (game->img.defeat)
		mlx_destroy_image(game->mlx, game->img.defeat);
	if (game->img.floor)
		mlx_destroy_image(game->mlx, game->img.floor);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->map.grid)
		free_map(game->map.grid);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	init_img(&game->img);
	exit(0);
	return (0);
}
