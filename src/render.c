/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 20:00:05 by gbodur            #+#    #+#             */
/*   Updated: 2025/03/18 21:42:59 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	render_fractal(t_fractal *fract)
{
	int		x;
	int		y;
	double	coords[2];
	int		count_iter;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			calc_coords(fract, x, y, coords);
			count_iter = calc_iteration (fract, coords[0], coords[1]);
			draw_pixel(&fract->canvas, x, y,
				get_color(count_iter, fract->max_iter, fract->color_scheme));
			x++;
		}
		y++;
	}
	update_display(fract);
}

void	calc_mouse_coords(t_fractal *fract, int x, int y, double *coords)
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

void	zoom_view(t_fractal *fract, int x, int y, double factor)
{
	double	mouse_coords[2];

	calc_mouse_coords(fract, x, y, mouse_coords);
	fract->center_x = mouse_coords[0] + (fract->center_x - mouse_coords[0])
		/ factor;
	fract->center_y = mouse_coords[1] + (fract->center_y - mouse_coords[1])
		/ factor;
	fract->zoom_level *= factor;
	render_fractal(fract);
}

void	pan_view(t_fractal *fract, double dx, double dy)
{
	double	delta_real;
	double	delta_img;
	
	delta_real = dx * (fract->scale_factor / fract->zoom_level) / WINDOW_WIDTH;
	delta_img = dy * (fract->scale_factor / fract->zoom_level) / WINDOW_HEIGHT;
	fract->center_x -= delta_real;
	fract->center_x += delta_img;
	render_fractal(fract);
}
