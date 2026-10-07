/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkformat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesainte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 11:55:13 by hesainte          #+#    #+#             */
/*   Updated: 2025/12/02 18:39:05 by hesainte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_checkformat(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i + 1])
	{
		if (s[i] == '%')
		{
			if (!ft_strchr("cspdiuxX%", s[i + 1]))
				return (0);
			i++;
		}
		i++;
	}
	return (1);
}
