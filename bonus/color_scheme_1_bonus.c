/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_scheme_1_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 15:39:53 by gbodur            #+#    #+#             */
/*   Updated: 2025/03/24 12:59:05 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

int	sunset_range_1(double ratio)
{
	int	r;
	int	g;
	int	b;

	r = (int)(10 + ratio * 5 * 200);
	g = (int)(10 + ratio * 5 * 30);
	b = (int)(50 + ratio * 5 * 70);
	return ((r << 16) | (g << 8) | b);
}

int	sunset_range_2(double ratio)
{
	int	r;
	int	g;
	int	b;

	ratio = (ratio - 0.2) * 5;
	r = (int)(210 + ratio * 45);
	g = (int)(40 + ratio * 20);
	b = (int)(120 - ratio * 20);
	return ((r << 16) | (g << 8) | b);
}

int	sunset_range_3(double ratio)
{
	int	r;
	int	g;
	int	b;

	ratio = (ratio - 0.4) * 5;
	r = (int)(255);
	g = (int)(60 + ratio * 60);
	b = (int)(100 - ratio * 80);
	return ((r << 16) | (g << 8) | b);
}

int	sunset_range_4(double ratio)
{
	int	r;
	int	g;
	int	b;

	ratio = (ratio - 0.6) * 5;
	r = (int)(255);
	g = (int)(120 + ratio * 100);
	b = (int)(20 + ratio * 40);
	return ((r << 16) | (g << 8) | b);
}

int	sunset_range_5(double ratio)
{
	int	r;
	int	g;
	int	b;

	ratio = (ratio - 0.8) * 5;
	r = (int)(255);
	g = (int)(220 + ratio * 35);
	b = (int)(60 + ratio * 120);
	return ((r << 16) | (g << 8) | b);
}
