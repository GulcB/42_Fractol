/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 14:12:24 by gbodur            #+#    #+#             */
/*   Updated: 2025/03/24 13:18:22 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	my_pxl_put(t_canvas *canvas, int x, int y, int color)
{
	char	*pxl;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		pxl = canvas->addr + (y * canvas->line_len + x * (canvas->bpp / 8));
		*(unsigned int *)pxl = color;
	}
}

void	calc_complex_coords(t_fractal *fract, int x, int y, t_complex *pos)
{
	pos->real = (4.0 * ((double)x / WIDTH - 0.5)) * fract->zoom
		+ fract->offset_x;
	pos->imag = (4.0 * ((double)y / HEIGHT - 0.5)) * fract->zoom
		+ fract->offset_y;
}

void	render_fractal(t_fractal *fract)
{
	int			x;
	int			y;
	t_complex	pos;
	int			iter;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			calc_complex_coords(fract, x, y, &pos);
			if (fract->type == TYPE_MANDELBROT)
				iter = compute_mandelbrot(pos.real, pos.imag, fract->max_iter);
			else
				iter = compute_julia(pos.real, pos.imag, fract->julia_c,
						fract->max_iter);
			my_pxl_put(&fract->canvas, x, y, get_color(iter, fract->max_iter));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fract->mlx, fract->win, fract->canvas.img, 0, 0);
}
