/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_funcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 16:38:56 by gbodur            #+#    #+#             */
/*   Updated: 2024/11/12 03:39:12 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int nb)
{
	int	i;

	i = 0;
	if (nb >= 0 && nb <= 9)
		i += ft_putchar(nb + '0');
	else if (nb == -2147483648)
	{
		write (1, "-2147483648", 11);
		return (11);
	}
	else if (nb < 0)
	{
		i += ft_putchar('-');
		i += ft_putnbr(nb * (-1));
	}
	else
	{
		i += ft_putnbr(nb / 10);
		i += ft_putnbr(nb % 10);
	}
	return (i);
}

int	ft_print_hex(unsigned long num, int is_uppercase)
{
	int		count;
	char	*base;

	count = 0;
	if (is_uppercase)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (num >= 16)
		count += ft_print_hex(num / 16, is_uppercase);
	count += ft_putchar(base[num % 16]);
	return (count);
}

int	ft_uns(unsigned int u)
{
	char	buffer[10];
	int		i;
	int		count;

	if (u == 0)
		return (ft_putchar('0'));
	i = 0;
	while (u > 0)
	{
		buffer[i++] = (u % 10) + '0';
		u /= 10;
	}
	count = i;
	while (--i >= 0)
		ft_putchar(buffer[i]);
	return (count);
}
