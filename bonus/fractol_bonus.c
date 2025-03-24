/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 15:19:19 by gbodur            #+#    #+#             */
/*   Updated: 2025/03/24 14:13:17 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

void	print_usage_bonus(void)
{
	ft_printf("Usage: ./fractol_bonus [fractal_type] [params]\n\n");
	ft_printf("Fractal types:\n");
	ft_printf("  mandelbrot   - Mandelbrot set\n");
	ft_printf("  julia        - Julia set (optional params: real imag)\n");
	ft_printf("  burning_ship - Burning Ship fractal\n\n");
	ft_printf("Examples:\n");
	ft_printf("  ./fractol_bonus mandelbrot\n");
	ft_printf("  ./fractol_bonus julia\n");
	ft_printf("  ./fractol_bonus julia -0.7 0.27015\n");
	ft_printf("  ./fractol_bonus burning_ship\n");
}

void	print_controls_bonus(void)
{
	ft_printf("\n==== Controls ====\n");
	ft_printf("Mouse wheel      - Zoom in/out\n");
	ft_printf("Mouse drag       - Pan view\n");
	ft_printf("Right click      - Set Julia parameter (Julia only)\n");
	ft_printf("C key            - Change color scheme\n");
	ft_printf("F key            - Change fractal type\n");
	ft_printf("R key            - Reset view\n");
	ft_printf("SPACE key        - Reset iterations\n");
	ft_printf("+/- keys         - Increase/decrease iterations\n");
	ft_printf("Arrow keys       - Pan view\n");
	ft_printf("ESC key          - Exit\n");
	ft_printf("=================\n\n");
}

static int	check_julia_params(t_fractal *fract, int ac, char **av)
{
	if (ac >= 4)
	{
		if (!is_number_bonus(av[2]) || !is_number_bonus(av[3]))
		{
			ft_printf("Error: Invalid parameters for Julia set\n");
			return (0);
		}
		fract->julia_c.real = ft_atof_bonus(av[2]);
		fract->julia_c.imag = ft_atof_bonus(av[3]);
	}
	return (1);
}

static int	parse_args_bonus(t_fractal *fract, int ac, char **av)
{
	if (ac < 2)
		return (0);
	if (ft_strncmp(av[1], "mandelbrot", 11) == 0)
	{
		init_fractal_bonus(fract, TYPE_MANDELBROT);
		if (ac > 2)
			ft_printf("Note: Mandelbrot set doesn't use extra parameters\n");
	}
	else if (ft_strncmp(av[1], "julia", 6) == 0)
	{
		init_fractal_bonus(fract, TYPE_JULIA);
		if (!check_julia_params(fract, ac, av))
			return (0);
	}
	else if (ft_strncmp(av[1], "burning_ship", 13) == 0)
		init_fractal_bonus(fract, TYPE_BURNING_SHIP);
	else
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_fractal	fract;

	ft_memset(&fract, 0, sizeof(t_fractal));
	if (!parse_args_bonus(&fract, ac, av))
	{
		print_usage_bonus();
		return (1);
	}
	print_controls_bonus();
	render_fractal_bonus(&fract);
	mlx_mouse_hook(fract.win, handle_mouse_bonus, &fract);
	mlx_hook(fract.win, 6, 1L << 6, handle_mouse_move_bonus, &fract);
	mlx_hook(fract.win, 17, 0, handle_close_bonus, &fract);
	mlx_hook(fract.win, 2, 1L << 0, handle_keypress_bonus, &fract);
	mlx_loop(fract.mlx);
	return (0);
}
