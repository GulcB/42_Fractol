/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_scheme.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 17:07:24 by gbodur            #+#    #+#             */
/*   Updated: 2025/03/19 17:10:38 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	color_scheme_0(double ratio)
{
	int	r;
	int	g;
	int	b;

	r = (int)(9 * (1 - ratio) * ratio * ratio * ratio * 255);
	g = (int)(15 * (1 - ratio) * (1 - ratio) * ratio * ratio * 255);
	b = (int)(8.5 * (1 - ratio) * (1 - ratio) * (1 - ratio) * ratio * 255);
	return ((r << 16) | (g << 8) | b);
}

int	color_scheme_1(double ratio)
{
	int	r;
	int	g;
	int	b;

	r = (int)(255 * ratio);
	g = (int)(128 * ratio * ratio);
	b = (int)(50 * ratio * ratio * ratio);
	return ((r << 16) | (g << 8) | b);
}

int	color_scheme_2(int iter)
{
	int	r;
	int	g;
	int	b;

	r = (int)(sin(0.3 * iter + 0) * 127 + 128);
	g = (int)(sin(0.3 * iter + 2) * 127 + 128);
	b = (int)(sin(0.3 * iter + 4) * 127 + 128);
	return ((r << 16) | (g << 8) | b);
}

int	color_scheme_3(double ratio)
{
	int	r;
	int	g;
	int	b;

	r = (int)(ratio * 255);
	g = (int)(ratio * 255);
	b = (int)(ratio * 255);
	return ((r << 16) | (g << 8) | b);
}

int	color_scheme_4(double ratio)
{
	int	r;
	int	g;
	int	b;

	r = (int)(ratio * ratio * 255);
	g = (int)(ratio * 255);
	b = (int)(255 - ratio * 255);
	return ((r << 16) | (g << 8) | b);
}
