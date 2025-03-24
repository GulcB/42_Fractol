/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 13:00:00 by gbodur            #+#    #+#             */
/*   Updated: 2025/03/24 13:09:56 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

void	my_pixel_put_bonus(t_canvas *canvas, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = canvas->addr + (y * canvas->line_len + x * (canvas->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

void	calc_cmplx_coords_bonus(t_fractal *fract, int x, int y, t_complex *pos)
{
	double	scale;

	scale = 4.0 / fract->zoom;
	pos->real = ((double)x / WIDTH - 0.5) * scale + fract->offset_x;
	pos->imag = ((double)y / HEIGHT - 0.5) * scale + fract->offset_y;
}

static int	calc_pixel_bonus(t_fractal *fract, t_complex pos)
{
	if (fract->type == TYPE_MANDELBROT)
		return (compute_mandelbrot_bonus(pos.real, pos.imag, fract->max_iter));
	else if (fract->type == TYPE_JULIA)
		return (compute_julia_bonus(pos.real, pos.imag, fract->julia_c,
				fract->max_iter));
	else
		return (compute_burning_ship_bonus(pos.real, pos.imag,
				fract->max_iter));
}

void	render_fractal_bonus(t_fractal *fract)
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
			calc_cmplx_coords_bonus(fract, x, y, &pos);
			iter = calc_pixel_bonus(fract, pos);
			my_pixel_put_bonus(&fract->canvas, x, y,
				get_color_bonus(iter, fract->max_iter, fract->color_scheme));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fract->mlx, fract->win, fract->canvas.img, 0, 0);
}
