/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_scheme_3_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 15:40:27 by gbodur            #+#    #+#             */
/*   Updated: 2025/03/24 13:00:03 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

int	fire_range_1(double ratio)
{
	int	r;
	int	g;
	int	b;

	r = (int)(ratio * 5 * 128);
	g = (int)(0);
	b = (int)(0);
	return ((r << 16) | (g << 8) | b);
}

int	fire_range_2(double ratio)
{
	int	r;
	int	g;
	int	b;

	ratio = (ratio - 0.2) * 5;
	r = (int)(128 + ratio * 127);
	g = (int)(0 + ratio * 30);
	b = (int)(0);
	return ((r << 16) | (g << 8) | b);
}

int	fire_range_3(double ratio)
{
	int	r;
	int	g;
	int	b;

	ratio = (ratio - 0.4) * 5;
	r = (int)(255);
	g = (int)(30 + ratio * 70);
	b = (int)(0);
	return ((r << 16) | (g << 8) | b);
}

int	fire_range_4(double ratio)
{
	int	r;
	int	g;
	int	b;

	ratio = (ratio - 0.6) * 5;
	r = (int)(255);
	g = (int)(100 + ratio * 80);
	b = (int)(0 + ratio * 30);
	return ((r << 16) | (g << 8) | b);
}

int	fire_range_5(double ratio)
{
	int	r;
	int	g;
	int	b;

	ratio = (ratio - 0.8) * 5;
	r = (int)(255);
	g = (int)(180 + ratio * 75);
	b = (int)(30 + ratio * 50);
	return ((r << 16) | (g << 8) | b);
}
