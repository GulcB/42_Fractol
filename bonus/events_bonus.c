/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:52:37 by gbodur            #+#    #+#             */
/*   Updated: 2025/03/24 13:20:51 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

static void	handle_additional_keys_bonus(int key, t_fractal *fract)
{
	ft_printf("Key pressed: %d\n", key);
	if (key == KEY_SPACE)
	{
		fract->max_iter = MAX_ITER;
		render_fractal_bonus(fract);
	}
	else if (key == KEY_PLUS)
	{
		fract->max_iter += 10;
		render_fractal_bonus(fract);
	}
	else if ((key == KEY_MINUS || key == 95) && fract->max_iter > 10)
	{
		fract->max_iter -= 10;
		render_fractal_bonus(fract);
	}
}

int	handle_keypress_bonus(int key, t_fractal *fract)
{
	ft_printf("Key pressed: %d\n", key);
	if (key == ESC)
		handle_close_bonus(fract);
	else if (key == KEY_C)
		cycle_color_scheme_bonus(fract);
	else if (key == KEY_R)
		reset_view_bonus(fract);
	else if (key == KEY_F)
		cycle_fractal_type_bonus(fract);
	else if (key == LEFT || key == RIGHT || key == UP || key == DOWN)
		handle_arrow_keys_bonus(key, fract);
	else
		handle_additional_keys_bonus(key, fract);
	return (0);
}

int	handle_mouse_bonus(int button, int x, int y, t_fractal *fract)
{
	t_complex	pos;

	if (button == MOUSE_SCROLL_UP)
		zoom_view_bonus(fract, x, y, 1.1);
	else if (button == MOUSE_SCROLL_DOWN)
		zoom_view_bonus(fract, x, y, 0.9);
	else if (button == MOUSE_LEFT)
	{
		fract->is_dragging = 1;
		fract->drag_start_x = x;
		fract->drag_start_y = y;
	}
	else if (button == MOUSE_RIGHT && fract->type == TYPE_JULIA)
	{
		calc_cmplx_coords_bonus(fract, x, y, &pos);
		fract->julia_c.real = pos.real;
		fract->julia_c.imag = pos.imag;
		render_fractal_bonus(fract);
	}
	return (0);
}

int	handle_mouse_move_bonus(int x, int y, t_fractal *fract)
{
	int	dx;
	int	dy;

	if (fract->is_dragging)
	{
		dx = fract->drag_start_x - x;
		dy = fract->drag_start_y - y;
		if (dx != 0 || dy != 0)
		{
			pan_view_bonus(fract, dx, -dy);
			fract->drag_start_x = x;
			fract->drag_start_y = y;
		}
	}
	return (0);
}

int	handle_close_bonus(t_fractal *fract)
{
	mlx_destroy_image(fract->mlx, fract->canvas.img);
	mlx_destroy_window(fract->mlx, fract->win);
	mlx_destroy_display(fract->mlx);
	free(fract->mlx);
	exit(0);
	return (0);
}
