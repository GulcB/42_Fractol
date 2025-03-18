/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 23:33:31 by gbodur            #+#    #+#             */
/*   Updated: 2025/03/18 21:42:09 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	compute_burning_ship(double x, double y, int limit)
{
	double	real;
	double	imag;
	double	temp_real;
	int		count_iter;

	real = 0.0;
	imag = 0.0;
	count_iter = 0;
	while (count_iter < limit)
	{
		if ((real * real + imag * imag) > 4.0)
			break ;
		temp_real = real;
		real = real * real - imag * imag + x;
		imag = 2 * fabs(temp_real * imag) + y;
		count_iter++;
	}
	return (count_iter);
}
