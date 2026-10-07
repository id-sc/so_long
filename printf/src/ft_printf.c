/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesainte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 11:50:46 by hesainte          #+#    #+#             */
/*   Updated: 2025/12/16 17:48:50 by hesainte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	int		count;
	int		i;
	va_list	params;

	count = 0;
	i = 0;
	if (!s || !ft_checkformat(s))
		return (-1);
	va_start(params, s);
	while (s[i])
	{
		if (s[i] != '%')
			count += write(1, &s[i], 1);
		else if (s[i + 1])
		{
			count += ft_iftype(params, s, i + 1);
			i++;
		}
		i++;
	}
	va_end(params);
	return (count);
}
/*
#include <stdio.h>
int main(void)
{
	void    *p;
	p = "test";
    
	ft_printf("pointer: %p\n", p);
	ft_printf("NULL %s NULL \n", NULL);
    ft_printf("Hello\n");
    ft_printf("character: %c\n", 'A');
    ft_printf("characters: %c%c%%\n", 'F', 'H');
    ft_printf("digit, percentage, string: %d%% of %s\n", 45, "success");
    ft_printf("small hexa: %x\n", -2);
    ft_printf("big hexa: %X\n", -2);
    printf("invalid syntax returns: %d\n", ft_printf("%%%\n"));
    printf("invalid specifier returns: %d\n", ft_printf("%e\n"));
}*/
