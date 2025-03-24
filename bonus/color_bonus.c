/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 13:00:00 by gbodur            #+#    #+#             */
/*   Updated: 2025/03/24 13:59:33 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

int	get_color_bonus(int iter, int max_iter, int scheme)
{
	double	ratio;

	if (iter == max_iter)
		return (0x000000);
	ratio = (double)iter / (double)max_iter;
	if (scheme == 0)
		return (color_scheme_0_bonus(ratio));
	else if (scheme == 1)
		return (color_scheme_1_bonus(ratio));
	else if (scheme == 2)
		return (color_scheme_2_bonus(ratio));
	else if (scheme == 3)
		return (color_scheme_3_bonus(ratio));
	else
		return (color_scheme_4_bonus(ratio));
}

void	cycle_color_scheme_bonus(t_fractal *fract)
{
	fract->color_scheme = (fract->color_scheme + 1) % 5;
	render_fractal_bonus(fract);
}

void	cycle_fractal_type_bonus(t_fractal *fract)
{
	fract->type = (fract->type + 1) % 3;
	if (fract->type == TYPE_JULIA)
	{
		fract->julia_c.real = -0.7;
		fract->julia_c.imag = 0.27015;
	}
	reset_view_bonus(fract);
}
