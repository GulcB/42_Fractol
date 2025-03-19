NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I./ft_printf
MLX_LIB = ./minilibx-linux/libmlx.a
LIBFT_DIR = ./libft 
LIBFT = $(LIBFT_DIR)/libft.a

SRC = src/burning_ship.c \
		src/color_scheme.c \
		src/color.c \
		src/events.c \
		src/init.c \
		src/julia.c \
		src/mandelbrot.c \
		src/render.c \
		src/utils.c \
		ft_printf/ft_printf_funcs.c \
		ft_printf/ft_printf.c \
		main.c

OBJS = $(SRC:.c=.o)

all: $(NAME) 

$(MLX_LIB):
	@make -C ./minilibx-linux

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(MLX_LIB) $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_LIB) -L$(LIBFT_DIR) -lft -o $(NAME) -lm -lX11 -lXext

clean:
	@make -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	@make -C ./libft fclean
	@make -C ./minilibx-linux clean
	$(RM) $(NAME) $(OBJ)

re: fclean all

.PHONY: all clean fclean re

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:22:17 by gbodur            #+#    #+#             */
/*   Updated: 2025/03/19 20:20:00 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include "./minilibx-linux/mlx.h"

# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 400
# define WINDOW_TITLE "Fractal Explorer"

# define TYPE_MANDELBROT 0
# define TYPE_JULIA 1
# define TYPE_BURNING_SHIP 2

# define ESC 65307
# define KEY_R 114
# define KEY_C 99
# define KEY_F 102
# define PLUS 65451
# define PLUS_ALT 61
# define MINUS 65453
# define MINUS_ALT 45
# define LEFT 65361
# define UP 65362
# define RIGHT 65663
# define DOWN 65364
# define MOUSE_LEFT 1
# define MOUSE_RIGHT 3
# define MOUSE_SCROLL_UP 4
# define MOUSE_SCROLL_DOWN 5

typedef struct s_canvas
{
	void		*img_ptr;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
}				t_canvas;

typedef struct	s_map
{
	double		val;
	double		in_min;
	double		in_max;
	double		out_min;
	double		out_max;
}				t_map;

typedef struct s_julia
{
	double		x;
	double		y;
	double		cr;
	double		ci;
	int			limit;
}				t_julia;

typedef struct s_fractal
{
	void    	*mlx;
	void    	*win;
	t_canvas   	canvas;
	
	double      center_x;
	double      center_y;
	double      zoom_level;
	double      scale_factor;
	double  	param_real;
	double  	param_imag;
	
	int     	type;
	int     	max_iter;
	int     	color_scheme;
	int         is_dragging;
	int         drag_start_x;
	int         drag_start_y;
}				t_fractal;

int     compute_burning_ship(double x, double y, int limit);

int		color_scheme_0(double ratio);
int		color_scheme_1(double ratio);
int		color_scheme_2(int iter);
int		color_scheme_3(double ratio);
int		color_scheme_4(double ratio);

int     get_color(int iter, int max_iter, int color_scheme);
void    cycle_color_scheme(t_fractal *fract);
void    cycle_fractal_type(t_fractal *fract);

int     handle_keypress(int key, t_fractal *fract);
void    handle_arrow_keys(int key, t_fractal *fract);
int     handle_mouse_button(int button, int x, int y, t_fractal *fract);
int     handle_mouse_move(int x, int y, t_fractal *fract);
int     handle_close(t_fractal *fract);

void    init_fractal(t_fractal *fract, int type);
void    setup_window(t_fractal *fract);
void    setup_canvas(t_fractal *fract);
void    reset_view(t_fractal *fract);

int     compute_julia(t_julia *julia);

int     compute_mandelbrot(double x, double y, int limit);

void    render_fractal(t_fractal *fract);
void    calc_mouse_coords(t_fractal *fract, int x, int y, double *coords);
void    zoom_view(t_fractal *fract, int x, int y, double factor);
void    pan_view(t_fractal *fract, double dx, double dy);

void    draw_pixel(t_canvas *canvas, int x, int y, int color);
double  map_range(t_map *map);
void    update_display(t_fractal *fract);
void    calc_coords(t_fractal *fract, int x, int y, double *coords);
int     calc_iteration(t_fractal *fract, double real, double imag);


void    show_usage(void);

#endif
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 23:33:31 by gbodur            #+#    #+#             */
/*   Updated: 2025/03/18 21:42:09 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	compute_burning_ship(double x, double y, int limit)
{
	double	real;
	double	imag;
	double	temp_real;
	int		count_iter;

	real = 0.0;
	imag = 0.0;
	count_iter = 0;
	while (count_iter < limit)
	{
		if ((real * real + imag * imag) > 4.0)
			break ;
		temp_real = real;
		real = real * real - imag * imag + x;
		imag = 2 * fabs(temp_real * imag) + y;
		count_iter++;
	}
	return (count_iter);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_scheme.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 17:07:24 by gbodur            #+#    #+#             */
/*   Updated: 2025/03/19 17:10:38 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	color_scheme_0(double ratio)
{
	int	r;
	int	g;
	int	b;

	r = (int)(9 * (1 - ratio) * ratio * ratio * ratio * 255);
	g = (int)(15 * (1 - ratio) * (1 - ratio) * ratio * ratio * 255);
	b = (int)(8.5 * (1 - ratio) * (1 - ratio) * (1 - ratio) * ratio * 255);
	return ((r << 16) | (g << 8) | b);
}

int	color_scheme_1(double ratio)
{
	int	r;
	int	g;
	int	b;

	r = (int)(255 * ratio);
	g = (int)(128 * ratio * ratio);
	b = (int)(50 * ratio * ratio * ratio);
	return ((r << 16) | (g << 8) | b);
}

int	color_scheme_2(int iter)
{
	int	r;
	int	g;
	int	b;

	r = (int)(sin(0.3 * iter + 0) * 127 + 128);
	g = (int)(sin(0.3 * iter + 2) * 127 + 128);
	b = (int)(sin(0.3 * iter + 4) * 127 + 128);
	return ((r << 16) | (g << 8) | b);
}

int	color_scheme_3(double ratio)
{
	int	r;
	int	g;
	int	b;

	r = (int)(ratio * 255);
	g = (int)(ratio * 255);
	b = (int)(ratio * 255);
	return ((r << 16) | (g << 8) | b);
}

int	color_scheme_4(double ratio)
{
	int	r;
	int	g;
	int	b;

	r = (int)(ratio * ratio * 255);
	g = (int)(ratio * 255);
	b = (int)(255 - ratio * 255);
	return ((r << 16) | (g << 8) | b);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 17:22:37 by gbodur            #+#    #+#             */
/*   Updated: 2025/03/19 17:27:12 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int     get_color(int iter, int max_iter, int color_scheme)
{
	double	ratio;

	if (iter == max_iter)
		return (0x000000);
	ratio = (double)iter / (double)max_iter;
	if (color_scheme == 0)
		return (color_scheme_0(ratio));
	else if (color_scheme == 1)
		return(color_scheme_1(ratio));
	else if (color_scheme == 2)
		return (color_scheme_2(iter));
	else if (color_scheme == 3)
		return (color_scheme_3(ratio));
	else
		return (color_scheme_4(ratio));
}

void    cycle_color_scheme(t_fractal *fract)
{
	fract->color_scheme = (fract->color_scheme + 1) % 5;
	render_fractal(fract);
}

void    cycle_fractal_type(t_fractal *fract)
{
	fract->type = (fract->type + 1) % 3;
	reset_view(fract);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 23:33:24 by gbodur            #+#    #+#             */
/*   Updated: 2025/03/19 19:02:13 by gbodur           ###   ########.fr       */
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
	mlx_destroy_display(fract->mlx);
	free(fract->mlx);
	exit(0);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 23:33:49 by gbodur            #+#    #+#             */
/*   Updated: 2025/03/18 21:42:48 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	init_fractal(t_fractal *fract, int type)
{
	fract->type = type;
	fract->max_iter = 50;
	fract->color_scheme = 0;
	fract->is_dragging = 0;
	fract->drag_start_x = 0;
	fract->drag_start_y = 0;
	fract->param_real = -0.7;
	fract->param_imag = 0.27015;
	setup_window(fract);
	setup_canvas(fract);
	reset_view(fract);
}

void	setup_window(t_fractal *fract)
{
	fract->mlx = mlx_init();
	if (!fract->mlx)
	{
		write(2, "Error: Could not initialize MLX\n", 32);
		exit (1);
	}
	fract->win = mlx_new_window(fract->mlx, WINDOW_WIDTH, WINDOW_HEIGHT,
			WINDOW_TITLE);
	if (!fract->win)
	{
		write(2, "Error: Could not create window\n", 31);
		exit (1);
	}
}

void	setup_canvas(t_fractal *fract)
{
	fract->canvas.img_ptr = mlx_new_image(fract->mlx, WINDOW_WIDTH,
			WINDOW_HEIGHT);
	if (!fract->canvas.img_ptr)
	{
		write(2, "Error: Could not create image\n", 30);
		exit (1);
	}
	fract->canvas.addr = mlx_get_data_addr(fract->canvas.img_ptr, 
		&fract->canvas.bpp, &fract->canvas.line_len,
			&fract->canvas.endian);
}

void	reset_view(t_fractal *fract)
{
	if (fract->type == TYPE_MANDELBROT)
	{
		fract->center_x = -0.5;
		fract->center_y = 0.0;
		fract->zoom_level = 1.0;
	}
	else if (fract->type == TYPE_JULIA)
	{
		fract->center_x = 0.0;
		fract->center_y = 0.0;
		fract->zoom_level = 1.0;
	}
	else if (fract->type == TYPE_BURNING_SHIP)
	{
		fract->center_x = -0.4;
		fract->center_y = -0.5;
		fract->zoom_level = 0.7;
	}
	fract->scale_factor = 4.0;
	render_fractal(fract);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 03:33:40 by gbodur            #+#    #+#             */
/*   Updated: 2025/03/18 21:42:51 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	compute_julia(t_julia *julia)
{
	double	real;
	double	imag;
	double	temp_real;
	int		count_iter;

	real = julia->x;
	imag = julia->y;
	count_iter = 0;
	while (count_iter < julia->limit)
	{
		if ((real * real + imag * imag) > 4.0)
			break ;
		temp_real = real;
		real = real * real - imag * imag + julia->cr;
		imag = 2 * temp_real * imag + julia->ci;
		count_iter++;
	}
	return (count_iter);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 03:34:09 by gbodur            #+#    #+#             */
/*   Updated: 2025/03/18 21:42:55 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	compute_mandelbrot(double x, double y, int limit)
{
	double	real;
	double	imag;
	double	temp_real;
	double	temp_imag;
	int		count_iter;

	real = 0.0;
	imag = 0.0;
	count_iter = 0;
	while (count_iter < limit)
	{
		if ((real * real + imag * imag) > 4.0)
			break ;
		temp_imag = imag;
		temp_real = real;
		real = temp_real * temp_real - temp_imag * temp_imag + x;
		imag = 2 * temp_real * temp_imag + y;
		count_iter++;
	}
	return (count_iter);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 20:00:05 by gbodur            #+#    #+#             */
/*   Updated: 2025/03/19 18:56:34 by gbodur           ###   ########.fr       */
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
