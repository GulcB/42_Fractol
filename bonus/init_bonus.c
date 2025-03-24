/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 13:00:00 by gbodur            #+#    #+#             */
/*   Updated: 2025/03/24 13:21:33 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

void	init_fractal_bonus(t_fractal *fract, int type)
{
	fract->type = type;
	fract->max_iter = MAX_ITER;
	fract->color_scheme = 0;
	fract->zoom = 1.0;
	fract->offset_x = 0.0;
	fract->offset_y = 0.0;
	fract->is_dragging = 0;
	fract->drag_start_x = 0;
	fract->drag_start_y = 0;
	if (type == TYPE_JULIA)
	{
		fract->julia_c.real = -0.7;
		fract->julia_c.imag = 0.27015;
	}
	setup_window_bonus(fract);
	setup_canvas_bonus(fract);
	reset_view_bonus(fract);
}

void	setup_window_bonus(t_fractal *fract)
{
	fract->mlx = mlx_init();
	if (!fract->mlx)
		error_exit_bonus("Could not initialize MLX");
	fract->win = mlx_new_window(fract->mlx, WIDTH, HEIGHT, WINDOW_TITLE);
	if (!fract->win)
		error_exit_bonus("Could not create window");
}

void	setup_canvas_bonus(t_fractal *fract)
{
	fract->canvas.img = mlx_new_image(fract->mlx, WIDTH, HEIGHT);
	if (!fract->canvas.img)
		error_exit_bonus("Could not create image");
	fract->canvas.addr = mlx_get_data_addr(fract->canvas.img,
			&fract->canvas.bpp, &fract->canvas.line_len,
			&fract->canvas.endian);
}

void	reset_view_bonus(t_fractal *fract)
{
	fract->zoom = 1.0;
	fract->offset_x = 0.0;
	fract->offset_y = 0.0;
	if (fract->type == TYPE_MANDELBROT)
	{
		fract->offset_x = -0.5;
	}
	else if (fract->type == TYPE_BURNING_SHIP)
	{
		fract->offset_x = -0.4;
		fract->offset_y = -0.5;
	}
	else if (fract->type == TYPE_BURNING_SHIP)
	{
		fract->offset_x = -0.4;
		fract->offset_y = -0.5;
	}
	fract->max_iter = MAX_ITER;
	fract->color_scheme = 0;
	render_fractal_bonus(fract);
}
