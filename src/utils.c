/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 23:33:56 by gbodur            #+#    #+#             */
/*   Updated: 2025/03/19 16:00:22 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	draw_pixel(t_canvas *canvas, int x, int y, int color)
{
	char	*pixel;

	if (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT)
	{
		pixel = canvas->addr + (y * canvas->line_len + x *(canvas->bpp / 8));
		*(unsigned int *)pixel = color;
	}
}

double	map_range(t_map *map)
{
	return (map->out_min + (map->val - map->in_min)
		* (map->out_max - map->out_min) / (map->in_max - map->in_min));
}

void	update_display(t_fractal *fract)
{
	mlx_put_image_to_window(fract->mlx, fract->win,
		fract->canvas.img_ptr, 0, 0);
}

void	calc_coords(t_fractal *fract, int x, int y, double *coords)
{
	t_map	map_x;
	t_map	map_y;

	map_x.val = x;
	map_x.in_min = 0;
	map_x.in_max = WINDOW_WIDTH;
	map_x.out_min = fract->center_x - fract->scale_factor / fract->zoom_level;
	map_x.out_max = fract->center_x + fract->scale_factor / fract->zoom_level;
	map_y.val = y;
	map_y.in_min = 0;
	map_y.in_max = WINDOW_HEIGHT;
	map_y.out_min = fract->center_y + fract->scale_factor / fract->zoom_level;
	map_y.out_max = fract->center_y - fract->scale_factor / fract->zoom_level;
	coords[0] = map_range(&map_x);
	coords[1] = map_range(&map_y);
}

int	calc_iteration(t_fractal *fract, double real, double imag)
{
	t_julia julia;
	
	if (fract->type == TYPE_MANDELBROT)
		return (compute_mandelbrot(real, imag, fract->max_iter));
	else if (fract->type == TYPE_JULIA)
	{
		julia.x = real;
		julia.y = imag;
		julia.cr = fract->param_real;
		julia.ci = fract->param_imag;
		julia.limit = fract->max_iter;
		return (compute_julia(&julia));
	}
	else if (fract->type == TYPE_BURNING_SHIP)
		return (compute_burning_ship(real, imag, fract->max_iter));
	return (0);
}
