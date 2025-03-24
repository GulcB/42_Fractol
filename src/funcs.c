/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 14:26:37 by gbodur            #+#    #+#             */
/*   Updated: 2025/03/24 13:14:18 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	check_first_part(char *str, int *i, int *digit_before_dot)
{
	if (str[*i] == '-' || str[*i] == '+')
		(*i)++;
	if (str[*i] == '.')
		return (0);
	while (str[*i] && str[*i] != '.')
	{
		if (str[*i] >= '0' && str[*i] <= '9')
			*digit_before_dot = 1;
		else
			return (0);
		(*i)++;
	}
	return (1);
}

static int	check_second_part(char *str, int *i)
{
	int	has_digit_after_dot;

	has_digit_after_dot = 0;
	if (str[*i] == '.')
	{
		(*i)++;
		while (str[*i])
		{
			if (str[*i] >= '0' && str[*i] <= '9')
				has_digit_after_dot = 1;
			else
				return (0);
			(*i)++;
		}
	}
	return (has_digit_after_dot || str[*i - 1] != '.');
}

int	is_number(char *str)
{
	int	i;
	int	digit_before_dot;

	i = 0;
	digit_before_dot = 0;
	if (!check_first_part(str, &i, &digit_before_dot))
		return (0);
	if (str[i] == '.' && !digit_before_dot)
		return (0);
	if (str[i] == '.' && !check_second_part(str, &i))
		return (0);
	return (digit_before_dot || str[i - 1] != '.');
}

static double	parse_decimal(const char *str, int *i)
{
	double	decimal;
	double	power;

	decimal = 0.0;
	power = 10.0;
	if (str[*i] == '.')
	{
		(*i)++;
		while (str[*i] >= '0' && str[*i] <= '9')
		{
			decimal = decimal + (str[*i] - '0') / power;
			power *= 10.0;
			(*i)++;
		}
	}
	return (decimal);
}

double	ft_atof(const char *str)
{
	double	result;
	double	decimal;
	int		sign;
	int		i;

	result = 0.0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10.0 + (str[i] - '0');
		i++;
	}
	decimal = parse_decimal(str, &i);
	return (sign * (result + decimal));
}
