/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesainte <hesainte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:10:44 by hesainte          #+#    #+#             */
/*   Updated: 2026/10/07 10:05:55 by hesainte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid(char c)
{
	int		i;
	char	*valid_char;

	i = 0;
	valid_char = "01CEPX";
	while (valid_char[i])
	{
		if (valid_char[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	check_enclosed(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.col)
	{
		if (game->map.grid[0][i] != '1'
			|| game->map.grid[game->map.row - 1][i] != '1')
			error_exit("Map is not enclosed", game, 0);
		i++;
	}
	i = 0;
	while (i < game->map.row)
	{
		if (game->map.grid[i][0] != '1'
			|| game->map.grid[i][game->map.col - 1] != '1')
			error_exit("Map is not enclosed", game, 0);
		i++;
	}
}

void	check_map_elements(t_game *game)
{
	if (game->map.exits > 1)
		error_exit("Map has more than one reachable exit", game, 0);
	if (game->map.exits < 1)
		error_exit("Map has less than one reachable exit", game, 0);
	if (game->check_map.exits > 1)
		error_exit("Map has more than one exit", game, 0);
	if (game->map.players > 1)
		error_exit("Map has more than one player", game, 0);
	if (game->map.collect < 1)
		error_exit("Map has less than one reachable collectible", game, 0);
	if (game->check_map.collect != game->map.collect)
		error_exit("Not all elements are reachable", game, 0);
}

void	check_characters(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->map.row)
	{
		j = 0;
		while (j < game->map.col)
		{
			if (!is_valid(game->map.grid[i][j]))
				error_exit("Map element is not valid", game, 0);
			j++;
		}
		i++;
	}
}

void	check_ber_extention(t_game *game, char *file)
{
	int	len;

	len = str_len(file);
	if (len < 4)
		error_exit("Map extention incorrect", game, 0);
	if (strcmp(file + len - 4, ".ber") != 0)
		error_exit("Map must be in a .ber format", game, 0);

}