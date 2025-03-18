/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 03:34:09 by gbodur            #+#    #+#             */
/*   Updated: 2025/03/18 21:42:55 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	compute_mandelbrot(double x, double y, int limit)
{
	double	real;
	double	imag;
	double	temp_real;
	double	temp_imag;
	int		count_iter;

	real = 0.0;
	imag = 0.0;
	count_iter = 0;
	while (count_iter < limit)
	{
		if ((real * real + imag * imag) > 4.0)
			break ;
		temp_imag = imag;
		temp_real = real;
		real = temp_real * temp_real - temp_imag * temp_imag + x;
		imag = 2 * temp_real * temp_imag + y;
		count_iter++;
	}
	return (count_iter);
}
