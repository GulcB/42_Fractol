/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 16:38:06 by gbodur            #+#    #+#             */
/*   Updated: 2024/11/08 14:10:42 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_type_check(char type, va_list arg)
{
	int				count;
	unsigned long	ptr;

	count = 0;
	if (type == 'x')
		count += ft_print_hex(va_arg(arg, unsigned int), 0);
	else if (type == 'X')
		count += ft_print_hex(va_arg(arg, unsigned int), 1);
	else if (type == 'p')
	{
		ptr = va_arg(arg, unsigned long);
		if (ptr == 0)
			count += ft_putstr("(nil)");
		else
		{
			count += ft_putstr("0x");
			count += ft_print_hex(ptr, 0);
		}
	}
	return (count);
}

static int	ft_type_check2(char type, va_list arg)
{
	int	count;

	count = 0;
	if (type == '%')
		count += ft_putchar('%');
	else if (type == 'c')
		count += ft_putchar(va_arg(arg, int));
	else if (type == 's')
		count += ft_putstr(va_arg(arg, char *));
	else if (type == 'd' || type == 'i')
		count += ft_putnbr(va_arg(arg, int));
	else if (type == 'u')
		count += ft_uns(va_arg(arg, unsigned int));
	else if (type == 'x' || type == 'X' || type == 'p')
		count += ft_type_check(type, arg);
	else
		return (0);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	arg;

	va_start(arg, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '\0')
				return (count);
			count += ft_type_check2(str[i], arg);
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(arg);
	return (count);
}
