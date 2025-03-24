/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:48:17 by gbodur            #+#    #+#             */
/*   Updated: 2025/03/24 13:20:31 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "../minilibx-linux/mlx.h"

# define WIDTH 1600
# define HEIGHT 1400
# define WINDOW_TITLE "fractol"
# define MAX_ITER 100

# define TYPE_MANDELBROT 0
# define TYPE_JULIA 1

# define ESC 65307
# define KEY_F 102
# define KEY_R 114
# define MOUSE_SCROLL_UP 4
# define MOUSE_SCROLL_DOWN 5

typedef struct s_complex
{
	double	real;
	double	imag;
}			t_complex;

typedef struct s_canvas
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_canvas;

typedef struct s_fractal
{
	void		*mlx;
	void		*win;
	t_canvas	canvas;
	int			type;
	int			max_iter;
	double		zoom;
	double		offset_x;
	double		offset_y;

	t_complex	julia_c;
}				t_fractal;

void	init_fractal(t_fractal *fract, int type);
void	setup_window(t_fractal *fract);
void	setup_canvas(t_fractal *fract);
void	reset_view(t_fractal *fract);

int		compute_mandelbrot(double real, double imag, int max_iter);
int		compute_julia(double real, double imag, t_complex c, int max_iter);

void	my_pxl_put(t_canvas *canvas, int x, int y, int color);
void	calc_complex_coords(t_fractal *fract, int x, int y, t_complex *pos);
void	render_fractal(t_fractal *fract);

int		get_color(int iter, int max_iter);

int		handle_keypress(int key, t_fractal *fract);
int		handle_mouse(int button, int x, int y, t_fractal *fract);
void	cycle_fractal_type(t_fractal *fract);
int		handle_close(t_fractal *fract);

double	ft_atof(const char *str);
int		is_number(char *str);
void	error_exit(char *msg);
void	print_usage(void);

void	zoom_view(t_fractal *fract, int x, int y, double factor);

#endif