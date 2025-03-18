/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 23:33:49 by gbodur            #+#    #+#             */
/*   Updated: 2025/03/18 21:42:48 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	init_fractal(t_fractal *fract, int type)
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

void	setup_window(t_fractal *fract)
{
	fract->mlx = mlx_init();
	if (!fract->mlx)
	{
		write(2, "Error: Could not initialize MLX\n", 32);
		exit (1);
	}
	fract->win = mlx_new_window(fract->mlx, WINDOW_WIDTH, WINDOW_HEIGHT,
			WINDOW_TITLE);
	if (!fract->win)
	{
		write(2, "Error: Could not create window\n", 31);
		exit (1);
	}
}

void	setup_canvas(t_fractal *fract)
{
	fract->canvas.img_ptr = mlx_new_image(fract->mlx, WINDOW_WIDTH,
			WINDOW_HEIGHT);
	if (!fract->canvas.img_ptr)
	{
		write(2, "Error: Could not create image\n", 30);
		exit (1);
	}
	fract->canvas.addr = mlx_get_data_addr(fract->canvas.img_ptr, 
		&fract->canvas.bpp, &fract->canvas.line_len,
			&fract->canvas.endian);
}

void	reset_view(t_fractal *fract)
{
	if (fract->type == TYPE_MANDELBROT)
	{
		fract->center_x = -0.5;
		fract->center_y = 0.0;
		fract->zoom_level = 1.0;
	}
	else if (fract->type == TYPE_JULIA)
	{
		fract->center_x = 0.0;
		fract->center_y = 0.0;
		fract->zoom_level = 1.0;
	}
	else if (fract->type == TYPE_BURNING_SHIP)
	{
		fract->center_x = -0.4;
		fract->center_y = -0.5;
		fract->zoom_level = 0.7;
	}
	fract->scale_factor = 4.0;
	render_fractal(fract);
}
