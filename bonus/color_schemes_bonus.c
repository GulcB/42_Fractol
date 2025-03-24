/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_schemes_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:58:13 by gbodur            #+#    #+#             */
/*   Updated: 2025/03/24 13:12:56 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

int	color_scheme_0_bonus(double ratio)
{
	if (ratio < 0.25)
		return (pastel_range_1(ratio));
	else if (ratio < 0.5)
		return (pastel_range_2(ratio));
	else if (ratio < 0.75)
		return (pastel_range_3(ratio));
	else
		return (pastel_range_4(ratio));
}

int	color_scheme_1_bonus(double ratio)
{
	if (ratio < 0.2)
		return (sunset_range_1(ratio));
	else if (ratio < 0.4)
		return (sunset_range_2(ratio));
	else if (ratio < 0.6)
		return (sunset_range_3(ratio));
	else if (ratio < 0.8)
		return (sunset_range_4(ratio));
	else
		return (sunset_range_5(ratio));
}

int	color_scheme_2_bonus(double ratio)
{
	if (ratio < 0.33)
		return (ocean_range_1(ratio));
	else if (ratio < 0.66)
		return (ocean_range_2(ratio));
	else
		return (ocean_range_3(ratio));
}

int	color_scheme_3_bonus(double ratio)
{
	if (ratio < 0.2)
		return (fire_range_1(ratio));
	else if (ratio < 0.4)
		return (fire_range_2(ratio));
	else if (ratio < 0.6)
		return (fire_range_3(ratio));
	else if (ratio < 0.8)
		return (fire_range_4(ratio));
	else
		return (fire_range_5(ratio));
}

int	color_scheme_4_bonus(double ratio)
{
	if (ratio < 0.2)
		return (galaxy_range_1(ratio));
	else if (ratio < 0.4)
		return (galaxy_range_2(ratio));
	else if (ratio < 0.6)
		return (galaxy_range_3(ratio));
	else if (ratio < 0.8)
		return (galaxy_range_4(ratio));
	else
		return (galaxy_range_5(ratio));
}
