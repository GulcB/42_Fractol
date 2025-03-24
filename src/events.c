/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:49:40 by gbodur            #+#    #+#             */
/*   Updated: 2025/03/24 14:00:09 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	handle_keypress(int key, t_fractal *fract)
{
	if (key == ESC)
		handle_close(fract);
	else if (key == KEY_F)
		cycle_fractal_type(fract);
	else if (key == KEY_R)
		reset_view(fract);
	return (0);
}

int	handle_mouse(int button, int x, int y, t_fractal *fract)
{
	if (button == MOUSE_SCROLL_UP)
		zoom_view(fract, x, y, 1.1);
	else if (button == MOUSE_SCROLL_DOWN)
		zoom_view(fract, x, y, 0.9);
	return (0);
}

void	cycle_fractal_type(t_fractal *fract)
{
	fract->type = (fract->type + 1) % 2;
	if (fract->type == TYPE_JULIA)
	{
		fract->julia_c.real = -0.7;
		fract->julia_c.imag = 0.27015;
	}
	reset_view(fract);
}

int	handle_close(t_fractal *fract)
{
	mlx_destroy_image(fract->mlx, fract->canvas.img);
	mlx_destroy_window(fract->mlx, fract->win);
	mlx_destroy_display(fract->mlx);
	free(fract->mlx);
	exit(0);
	return (0);
}
