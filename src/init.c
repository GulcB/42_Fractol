/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 23:33:49 by gbodur            #+#    #+#             */
/*   Updated: 2025/03/16 23:44:03 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void init_fractal(t_fractal *fract, int type)
{
    fract->type = type;
    fract->max_iter = 50;
    fract->color_scheme = 0;
    fract->is_dragging = 0;
    fract->drag_start_x = 0;
    fract->drag_start_y = 0;
    fract->param_real = -0.7;
    fract->param_imag = 0.27015;
    
    setup_window(fract);
    setup_canvas(fract);
    reset_view(fract);
}

void setup_window(t_fractal *fract)
{
	fract->mlx = mlx_init();
    if (!fract->mlx)
	{
		
	}
}