/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 23:33:24 by gbodur            #+#    #+#             */
/*   Updated: 2025/03/19 16:45:38 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	handle_keypress(int key, t_fractal *fract)
{
	if (key == ESC)
	handle_close(fract);
	else if (key == KEY_R)
		reset_view(fract);
	else if (key == KEY_C)
		cycle_color_scheme(fract);
	else if (key == KEY_F)
		cycle_fractal_type(fract);
	else if (key == PLUS || key == PLUS_ALT)
	{
		fract->max_iter += 10;
		render_fractal(fract);
	}
	else if (key == MINUS || key == MINUS_ALT)
	{
		if (fract->max_iter > 10)
			fract->max_iter -= 10;
		render_fractal(fract);
	}
	else if (key >= LEFT && key <= DOWN)
		handle_arrow_keys(key, fract);
	return (0);
}

void	handle_arrow_keys(int key, t_fractal *fract)
{
	double	move_amount;

	move_amount = 0.1 / fract->zoom_level;
	if (key == LEFT)
		fract->center_x -= move_amount;
	else if (key == UP)
		fract->center_y += move_amount;
	else if (key == RIGHT)
		fract->center_x += move_amount;
	else if (key == DOWN)
		fract->center_y -= move_amount;
	render_fractal(fract);
}

int	handle_mouse_button(int button, int x, int y, t_fractal *fract)
{
	if (button == MOUSE_SCROLL_UP)
		zoom_view(fract, x, y, 1.2);
	else if (button == MOUSE_SCROLL_DOWN)
		zoom_view(fract, x, y, 0.8);
	else if (button == MOUSE_LEFT)
		{
		fract->is_dragging = 1;
		fract->drag_start_x = x;
		fract->drag_start_y = y;
	}
	else if (button == MOUSE_RIGHT && fract->type == TYPE_JULIA)
	{
		double	coords[2];
		
		calc_mouse_coords(fract, x, y, coords);
		fract->param_real = coords[0];
		fract->param_imag = coords[1];
		render_fractal(fract);
	}
	return (0);
}


int	handle_mouse_move(int x, int y, t_fractal *fract)
{
    if (fract->is_dragging)
	{
		int	dx;
		int	dy;

		dx = fract->drag_start_x - x;
		dy = fract->drag_start_y - y;

		if (dx != 0 || dy != 0)
		{
			pan_view(fract, dx, -dy);
			fract->drag_start_x = x;
			fract->drag_start_y = y;
		}
	}
	return (0);
}

int	handle_close(t_fractal *fract)
{
    mlx_destroy_image(fract->mlx, fract->canvas.img_ptr);
	mlx_destroy_window(fract->mlx, fract->win);
	exit(0);
	return (0);
}
