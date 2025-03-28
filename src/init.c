/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 14:09:07 by gbodur            #+#    #+#             */
/*   Updated: 2025/03/24 13:21:10 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_fractal(t_fractal *fract, int type)
{
	fract->type = type;
	fract->max_iter = MAX_ITER;
	fract->zoom = 1.0;
	fract->offset_x = 0.0;
	fract->offset_y = 0.0;
	if (type == TYPE_JULIA)
	{
		fract->julia_c.real = -0.7;
		fract->julia_c.imag = 0.27015;
	}
	setup_window(fract);
	setup_canvas(fract);
	reset_view(fract);
}

void	setup_window(t_fractal *fract)
{
	fract->mlx = mlx_init();
	if (!fract->mlx)
		error_exit("Could not initialize MLX");
	fract->win = mlx_new_window(fract->mlx, WIDTH, HEIGHT, WINDOW_TITLE);
	if (!fract->win)
		error_exit("Could not create window");
}

void	setup_canvas(t_fractal *fract)
{
	fract->canvas.img = mlx_new_image(fract->mlx, WIDTH, HEIGHT);
	if (!fract->canvas.img)
		error_exit("Could not create image");
	fract->canvas.addr = mlx_get_data_addr(fract->canvas.img,
			&fract->canvas.bpp, &fract->canvas.line_len,
			&fract->canvas.endian);
}

void	reset_view(t_fractal *fract)
{
	fract->zoom = 1.0;
	fract->offset_x = 0.0;
	fract->offset_y = 0.0;
	if (fract->type == TYPE_MANDELBROT)
		fract->offset_x = -0.5;
	render_fractal(fract);
}
