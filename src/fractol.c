/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 14:04:21 by gbodur            #+#    #+#             */
/*   Updated: 2025/03/24 13:49:34 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	print_usage(void)
{
	ft_printf("Usage: ./fractol [fractal_type] [params]\n\n");
	ft_printf("Fractal types:\n");
	ft_printf("  mandelbrot   - Mandelbrot set\n");
	ft_printf("  julia        - Julia set (optional params: real imag)\n\n");
	ft_printf("Examples:\n");
	ft_printf("  ./fractol mandelbrot\n");
	ft_printf("  ./fractol julia\n");
	ft_printf("  ./fractol julia -0.7 0.27015\n");
}

static int	parse_args(t_fractal *fract, int ac, char **av)
{
	if (ac < 2)
		return (0);
	if (ft_strncmp(av[1], "mandelbrot", 11) == 0)
	{
		init_fractal(fract, TYPE_MANDELBROT);
		if (ac > 2)
			ft_printf("Note: Mandelbrot set doesn't use extra parameters\n");
	}
	else if (ft_strncmp(av[1], "julia", 6) == 0)
	{
		init_fractal(fract, TYPE_JULIA);
		if (ac >= 4)
		{
			if (!is_number(av[2]) || !is_number(av[3]))
			{
				ft_printf("Error: Invalid parameters for Julia set\n");
				return (0);
			}
			fract->julia_c.real = ft_atof(av[2]);
			fract->julia_c.imag = ft_atof(av[3]);
		}
	}
	else
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_fractal	fract;

	ft_memset(&fract, 0, sizeof(t_fractal));
	if (!parse_args(&fract, ac, av))
	{
		print_usage();
		return (1);
	}
	render_fractal(&fract);
	mlx_key_hook(fract.win, handle_keypress, &fract);
	mlx_mouse_hook(fract.win, handle_mouse, &fract);
	mlx_hook(fract.win, 17, 0, handle_close, &fract);
	mlx_loop(fract.mlx);
	return (0);
}
