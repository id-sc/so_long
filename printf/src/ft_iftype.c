/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iftype.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesainte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 11:25:28 by hesainte          #+#    #+#             */
/*   Updated: 2025/12/02 18:38:39 by hesainte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_iftype(va_list params, const char *s, int i)
{
	unsigned long	arg;

	if (s[i] == 'c')
		return (ft_putchar(va_arg(params, int)));
	if (s[i] == 's')
		return (ft_putstr(va_arg(params, char *)));
	if (s[i] == 'p')
	{
		arg = (unsigned long)va_arg(params, void *);
		if (!arg)
			return (ft_putstr("(nil)"));
		ft_putstr("0x");
		return (2 + ft_putptr(arg));
	}
	if (s[i] == 'd' || s[i] == 'i')
		return (ft_putnbr(va_arg(params, int)));
	if (s[i] == 'u')
		return (ft_unsputnbr(va_arg(params, unsigned int)));
	if (s[i] == 'x')
		return (ft_puthexa(va_arg(params, unsigned int)));
	if (s[i] == 'X')
		return (ft_puthexaup(va_arg(params, unsigned int)));
	if (s[i] == '%')
		return (ft_putchar('%'));
	return (0);
}
