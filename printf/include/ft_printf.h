/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsun <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 14:56:13 by jsun              #+#    #+#             */
/*   Updated: 2025/12/02 18:40:06 by hesainte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stddef.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_putchar(char c);
int		ft_checkformat(const char *s);
int		ft_iftype(va_list params, const char *s, int i);
int		ft_printf(const char *s, ...);
int		ft_putstr(char *s);
char	*ft_strchr(const char *str, int c);
int		ft_putnbr(int nb);
int		ft_unsputnbr(unsigned long nb);
int		ft_puthexa(unsigned long nb);
int		ft_puthexaup(unsigned long nb);
int		ft_putptr(unsigned long ptr);
#endif
