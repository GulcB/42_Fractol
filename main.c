/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:23:42 by gbodur            #+#    #+#             */
/*   Updated: 2025/03/19 18:56:39 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	show_usage(void)
{
	ft_printf("Usage: ./fractol [fractal_type]\n\n");
	ft_printf("Fractal types:\n");
	ft_printf("  mandelbrot   - Mandelbrot set\n");
	ft_printf("  julia        - Julia set\n");
	ft_printf("  burning_ship - Burning Ship fractal (bonus)\n\n");
	ft_printf("Controls:\n");
	ft_printf("  Mouse wheel      - Zoom in/out\n");
	ft_printf("  Mouse drag       - Pan view\n");
	ft_printf("  C key            - Change color theme\n");
	ft_printf("  F key            - Change fractal type\n");
	ft_printf("  R key            - Reset view\n");
	ft_printf("  +/- keys         - Increase/decrease iterations\n");
	ft_printf("  Arrow keys       - Pan view\n");
	ft_printf("  ESC key          - Exit\n");
}

int	main(int ac, char **av)
{
	t_fractal	finder;

	if (ac != 2)
	{
		show_usage();
		return (1);	
	}
	if (ft_strncmp(av[1], "mandelbrot", 11) == 0)
		init_fractal(&finder, TYPE_MANDELBROT);
	else if (ft_strncmp(av[1], "julia", 6) == 0)
		init_fractal(&finder, TYPE_JULIA);
	else if (ft_strncmp(av[1], "burning_ship", 13) == 0)
		init_fractal(&finder, TYPE_BURNING_SHIP);
	else
	{
		show_usage();
		return (1);	
	}
	render_fractal(&finder);
	mlx_key_hook(finder.win, handle_keypress, &finder);
	mlx_mouse_hook(finder.win, handle_mouse_button, &finder);
	mlx_hook(finder.win, 6, 1L << 6, handle_mouse_move, &finder);
	mlx_hook(finder.win, 17, 0, handle_close, &finder);
	mlx_loop(finder.mlx);
	return (0);
}
