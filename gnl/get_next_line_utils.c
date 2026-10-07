/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesainte <hesainte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:26:39 by hesainte          #+#    #+#             */
/*   Updated: 2026/10/07 10:08:10 by hesainte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = '\0';
		i++;
	}
}

void	ft_reset(char **buf)
{
	if (*buf)
	{
		free(*buf);
		*buf = NULL;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*array;

	if (!nmemb || !size)
	{
		array = malloc(1);
		if (!array)
			return (NULL);
		return (array);
	}
	if ((nmemb * size / nmemb) != size)
		return (NULL);
	array = malloc(nmemb * size);
	if (!array)
		return (NULL);
	ft_bzero(array, nmemb * size);
	return (array);
}

int	ft_strlen(const char *str)
{
	int	counter;

	counter = 0;
	while (str[counter])
		counter++;
	return (counter);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_s;
	int		i;
	int		j;

	if (!s2)
		return (NULL);
	if (!s1)
	{
		s1 = ft_calloc(sizeof(char), 1);
		if (!s1)
			return (NULL);
	}
	j = 0;
	i = -1;
	new_s = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!new_s)
		return (NULL);
	while (s1[++i])
		new_s[j++] = s1[i];
	i = -1;
	while (s2[++i])
		new_s[j++] = s2[i];
	new_s[j] = '\0';
	return (new_s);
}
