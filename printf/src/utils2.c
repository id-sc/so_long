/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesainte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:18:27 by hesainte          #+#    #+#             */
/*   Updated: 2025/12/02 18:59:50 by hesainte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	long	nbr;
	int		count;

	nbr = nb;
	count = 0;
	if (nbr < 0)
	{
		nbr = nbr * -1;
		ft_putchar('-');
		count++;
	}
	if (nbr > 9)
		count += ft_putnbr(nbr / 10);
	ft_putchar(nbr % 10 + '0');
	count++;
	return (count);
}

int	ft_unsputnbr(unsigned long nb)
{
	int	count;

	count = 0;
	if (nb > 9)
		count += ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
	count++;
	return (count);
}

int	ft_puthexa(unsigned long nb)
{
	int		count;
	char	*hexa;

	count = 0;
	hexa = "0123456789abcdef";
	if (nb > 15)
		count += ft_puthexa(nb / 16);
	ft_putchar(hexa[nb % 16]);
	count++;
	return (count);
}

int	ft_puthexaup(unsigned long nb)
{
	int		count;
	char	*hexa;

	count = 0;
	hexa = "0123456789ABCDEF";
	if (nb > 15)
		count += ft_puthexaup(nb / 16);
	ft_putchar(hexa[nb % 16]);
	count++;
	return (count);
}

int	ft_putptr(unsigned long ptr)
{
	int		count;
	char	*hexa;

	if (!ptr)
		return (0);
	count = 0;
	hexa = "0123456789abcdef";
	if (ptr > 15)
		count += ft_puthexa(ptr / 16);
	ft_putchar(hexa[ptr % 16]);
	count++;
	return (count);
}
