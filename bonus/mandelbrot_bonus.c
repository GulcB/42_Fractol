/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:11:51 by gbodur            #+#    #+#             */
/*   Updated: 2025/03/23 16:12:27 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

int	compute_mandelbrot_bonus(double real, double imag, int max_iter)
{
	t_complex	z;
	t_complex	c;
	double		tmp;
	int			iter;

	z.real = 0.0;
	z.imag = 0.0;
	c.real = real;
	c.imag = imag;
	iter = 0;
	while (iter < max_iter)
	{
		if ((z.real * z.real + z.imag * z.imag) > 4.0)
			break ;
		tmp = z.real * z.real - z.imag * z.imag + c.real;
		z.imag = 2.0 * z.real * z.imag + c.imag;
		z.real = tmp;
		iter++;
	}
	return (iter);
}
