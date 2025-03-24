/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_scheme_4_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 15:40:30 by gbodur            #+#    #+#             */
/*   Updated: 2025/03/24 13:00:19 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

int	galaxy_range_1(double ratio)
{
	int	r;
	int	g;
	int	b;

	r = (int)(ratio * 5 * 80);
	g = (int)(0);
	b = (int)(ratio * 5 * 140);
	return ((r << 16) | (g << 8) | b);
}

int	galaxy_range_2(double ratio)
{
	int	r;
	int	g;
	int	b;

	ratio = (ratio - 0.2) * 5;
	r = (int)(80 + ratio * 175);
	g = (int)(0 + ratio * 20);
	b = (int)(140 + ratio * 50);
	return ((r << 16) | (g << 8) | b);
}

int	galaxy_range_3(double ratio)
{
	int	r;
	int	g;
	int	b;

	ratio = (ratio - 0.4) * 5;
	r = (int)(255 - ratio * 200);
	g = (int)(20 + ratio * 130);
	b = (int)(190 + ratio * 65);
	return ((r << 16) | (g << 8) | b);
}

int	galaxy_range_4(double ratio)
{
	int	r;
	int	g;
	int	b;

	ratio = (ratio - 0.6) * 5;
	r = (int)(55 - ratio * 55);
	g = (int)(150 + ratio * 105);
	b = (int)(255 - ratio * 125);
	return ((r << 16) | (g << 8) | b);
}

int	galaxy_range_5(double ratio)
{
	int	r;
	int	g;
	int	b;

	ratio = (ratio - 0.8) * 5;
	r = (int)(0 + ratio * 30);
	g = (int)(255 - ratio * 55);
	b = (int)(130 + ratio * 125);
	return ((r << 16) | (g << 8) | b);
}
