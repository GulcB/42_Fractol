/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:53:35 by gbodur            #+#    #+#             */
/*   Updated: 2025/03/24 13:12:39 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

void	zoom_view_bonus(t_fractal *fract, int x, int y, double factor)
{
	t_complex	mouse_pos;

	calc_cmplx_coords_bonus(fract, x, y, &mouse_pos);
	fract->zoom *= factor;
	fract->offset_x = mouse_pos.real - ((double)x / WIDTH - 0.5)
		* (4.0 / fract->zoom);
	fract->offset_y = mouse_pos.imag - ((double)y / HEIGHT - 0.5)
		* (4.0 / fract->zoom);
	render_fractal_bonus(fract);
}

void	pan_view_bonus(t_fractal *fract, double dx, double dy)
{
	double	move_x;
	double	move_y;

	move_x = dx * 0.003 * fract->zoom;
	move_y = dy * 0.003 * fract->zoom;
	fract->offset_x += move_x;
	fract->offset_y += move_y;
	render_fractal_bonus(fract);
}

void	handle_arrow_keys_bonus(int key, t_fractal *fract)
{
	double	move_amount;

	move_amount = 0.1 * fract->zoom;
	if (key == LEFT)
		fract->offset_x += move_amount;
	else if (key == RIGHT)
		fract->offset_x -= move_amount;
	else if (key == UP)
		fract->offset_y -= move_amount;
	else if (key == DOWN)
		fract->offset_y += move_amount;
	render_fractal_bonus(fract);
}
