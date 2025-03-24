/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_scheme_0_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 15:31:08 by gbodur            #+#    #+#             */
/*   Updated: 2025/03/24 12:58:55 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

int	pastel_range_1(double ratio)
{
	int	r;
	int	g;
	int	b;

	r = (int)(180 + ratio * 4 * 40);
	g = (int)(200 - ratio * 4 * 20);
	b = (int)(255);
	return ((r << 16) | (g << 8) | b);
}

int	pastel_range_2(double ratio)
{
	int	r;
	int	g;
	int	b;

	ratio = (ratio - 0.25) * 4;
	r = (int)(220 + ratio * 35);
	g = (int)(180 - ratio * 30);
	b = (int)(255 - ratio * 50);
	return ((r << 16) | (g << 8) | b);
}

int	pastel_range_3(double ratio)
{
	int	r;
	int	g;
	int	b;

	ratio = (ratio - 0.5) * 4;
	r = (int)(255 - ratio * 130);
	g = (int)(150 + ratio * 105);
	b = (int)(205 - ratio * 105);
	return ((r << 16) | (g << 8) | b);
}

int	pastel_range_4(double ratio)
{
	int	r;
	int	g;
	int	b;

	ratio = (ratio - 0.75) * 4;
	r = (int)(125 - ratio * 25);
	g = (int)(255 - ratio * 55);
	b = (int)(100 + ratio * 155);
	return ((r << 16) | (g << 8) | b);
}
