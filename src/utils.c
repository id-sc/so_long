/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesainte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 16:06:35 by hesainte          #+#    #+#             */
/*   Updated: 2026/01/28 13:00:40 by hesainte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_counti(long n)
{
	long	nbr;
	int		i;

	nbr = n;
	i = 0;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		i++;
	}
	nbr = n;
	if (nbr < 0)
	{
		i++;
		nbr *= -1;
	}
	return (i);
}

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*new_s;
	int		i;

	i = 0;
	new_s = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!new_s)
		return (NULL);
	while (s[i])
	{
		new_s[i] = s[i];
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}

char	**copy_grid(t_game *game)
{
	char	**grid_copy;
	int		i;

	grid_copy = malloc(sizeof(char *) * (game->map.row + 1));
	i = 0;
	while (i < game->map.row)
	{
		grid_copy[i] = ft_strdup(game->map.grid[i]);
		if (!grid_copy[i])
		{
			grid_copy = free_tab(grid_copy, i);
			error_exit("Malloc failed while copying grid", game, 1);
		}
		i++;
	}
	grid_copy[i] = NULL;
	return (grid_copy);
}

char	*ft_itoa(int n)
{
	char	*res;
	long	nbr;
	int		i;

	nbr = n;
	if (nbr == 0)
		return (ft_strdup("0"));
	i = ft_counti(nbr);
	if (nbr < 0)
		nbr *= -1;
	res = malloc(sizeof(char) * i + 1);
	if (!res)
		return (NULL);
	res[i] = '\0';
	while (nbr != 0)
	{
		res[--i] = nbr % 10 + 48;
		nbr = nbr / 10;
	}
	if (n < 0)
		res[0] = '-';
	return (res);
}
