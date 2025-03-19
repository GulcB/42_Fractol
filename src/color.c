/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 17:22:37 by gbodur            #+#    #+#             */
/*   Updated: 2025/03/19 17:27:12 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int     get_color(int iter, int max_iter, int color_scheme)
{
	double	ratio;

	if (iter == max_iter)
		return (0x000000);
	ratio = (double)iter / (double)max_iter;
	if (color_scheme == 0)
		return (color_scheme_0(ratio));
	else if (color_scheme == 1)
		return(color_scheme_1(ratio));
	else if (color_scheme == 2)
		return (color_scheme_2(iter));
	else if (color_scheme == 3)
		return (color_scheme_3(ratio));
	else
		return (color_scheme_4(ratio));
}

void    cycle_color_scheme(t_fractal *fract)
{
	fract->color_scheme = (fract->color_scheme + 1) % 5;
	render_fractal(fract);
}

void    cycle_fractal_type(t_fractal *fract)
{
	fract->type = (fract->type + 1) % 3;
	reset_view(fract);
}
