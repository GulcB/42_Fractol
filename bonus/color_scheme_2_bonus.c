/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_scheme_2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 15:40:03 by gbodur            #+#    #+#             */
/*   Updated: 2025/03/24 12:59:38 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

int	ocean_range_1(double ratio)
{
	int	r;
	int	g;
	int	b;

	r = (int)(0);
	g = (int)(0 + ratio * 3 * 80);
	b = (int)(70 + ratio * 3 * 95);
	return ((r << 16) | (g << 8) | b);
}

int	ocean_range_2(double ratio)
{
	int	r;
	int	g;
	int	b;

	ratio = (ratio - 0.33) * 3;
	r = (int)(0 + ratio * 30);
	g = (int)(80 + ratio * 100);
	b = (int)(165 + ratio * 15);
	return ((r << 16) | (g << 8) | b);
}

int	ocean_range_3(double ratio)
{
	int	r;
	int	g;
	int	b;

	ratio = (ratio - 0.66) * 3;
	r = (int)(30 + ratio * 30);
	g = (int)(180 - ratio * 60);
	b = (int)(180 - ratio * 115);
	return ((r << 16) | (g << 8) | b);
}
