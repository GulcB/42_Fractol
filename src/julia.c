/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 03:33:40 by gbodur            #+#    #+#             */
/*   Updated: 2025/03/18 21:42:51 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	compute_julia(t_julia *julia)
{
	double	real;
	double	imag;
	double	temp_real;
	int		count_iter;

	real = julia->x;
	imag = julia->y;
	count_iter = 0;
	while (count_iter < julia->limit)
	{
		if ((real * real + imag * imag) > 4.0)
			break ;
		temp_real = real;
		real = real * real - imag * imag + julia->cr;
		imag = 2 * temp_real * imag + julia->ci;
		count_iter++;
	}
	return (count_iter);
}
