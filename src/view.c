/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 14:26:41 by gbodur            #+#    #+#             */
/*   Updated: 2025/03/24 13:17:55 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	zoom_view(t_fractal *fract, int x, int y, double factor)
{
	double	old_zoom;

	(void)x;
	(void)y;
	old_zoom = fract->zoom;
	fract->zoom *= factor;
	fract->offset_x = fract->offset_x * old_zoom / fract->zoom;
	fract->offset_y = fract->offset_y * old_zoom / fract->zoom;
	render_fractal(fract);
}
