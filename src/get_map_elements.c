/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_elements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesainte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 16:07:11 by hesainte          #+#    #+#             */
/*   Updated: 2026/02/09 11:11:05 by hesainte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_map_size(t_game *game, char *file)
{
	int		fd;
	char	*line;
	int		len;

	len = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		error_exit("Could not open map file", game, 1);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		len = str_len(line);
		if (line[len - 1] == '\n')
			len--;
		if (game->map.col == 0)
			game->map.col = len;
		if (!(len == game->map.col))
			(free(line), get_next_line(-1), close(fd),
				error_exit("Map not rectangular\n", game, 0));
		game->map.row++;
		free(line);
	}
	close(fd);
}

void	get_grid(t_game *game, char *file)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		error_exit("Could not open map file", game, 1);
	game->map.grid = malloc(sizeof(char *) * (game->map.row + 1));
	if (!game->map.grid)
	{
		close(fd);
		error_exit("Malloc failed for map grid", game, 1);
	}
	while (i < game->map.row)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		game->map.grid[i] = line;
		i++;
	}
	game->map.grid[i] = NULL;
	close(fd);
}

int	find_player(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.row)
	{
		j = 0;
		while (j < game->map.col)
		{
			if (game->map.grid[i][j] == 'P')
			{
				game->player.player_x = j;
				game->player.player_y = i;
				game->map.players++;
			}
			j++;
		}
		i++;
	}
	if (game->map.players > 0)
		return (1);
	return (0);
}

void	count_map_elements(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.row)
	{
		j = 0;
		while (j < game->map.col)
		{
			if (game->map.grid[i][j] == 'C')
				game->check_map.collect++;
			if (game->map.grid[i][j] == 'E')
				game->check_map.exits++;
			if (game->map.grid[i][j] == 'X')
				game->check_map.enemies++;
			j++;
		}
		i++;
	}
}

void	get_map_elements(char **map, t_game *game, int i, int j)
{
	if (i < 0 || j < 0 || i >= game->map.row || j >= game->map.col
		|| map[i][j] == '1' || map[i][j] == 'F')
		return ;
	if (map[i][j] == 'C')
		game->map.collect++;
	if (map[i][j] == 'X')
	{
		game->map.enemies++;
		enemy_add_back(&game->enemies, new_enemy(j, i));
	}
	if (map[i][j] == 'E')
	{
		if (game->map.exit_x != j && game->map.exit_y != i)
		{
			game->map.exits++;
			game->map.exit_x = j;
			game->map.exit_y = i;
		}
		return ;
	}
	map[i][j] = 'F';
	get_map_elements(map, game, i + 1, j);
	get_map_elements(map, game, i - 1, j);
	get_map_elements(map, game, i, j + 1);
	get_map_elements(map, game, i, j - 1);
}
