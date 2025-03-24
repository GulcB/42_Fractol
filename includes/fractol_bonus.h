/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:50:28 by gbodur            #+#    #+#             */
/*   Updated: 2025/03/24 13:21:43 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "../minilibx-linux/mlx.h"

# define WIDTH 1920
# define HEIGHT 1080
# define WINDOW_TITLE "fractol bonus"
# define MAX_ITER 100

# define TYPE_MANDELBROT 0
# define TYPE_JULIA 1
# define TYPE_BURNING_SHIP 2

# define ESC 65307
# define KEY_SPACE 32
# define KEY_R 114
# define KEY_C 99
# define KEY_F 102
# define KEY_PLUS 52
# define KEY_MINUS 45
# define LEFT 65361
# define UP 65362
# define RIGHT 65363
# define DOWN 65364
# define MOUSE_LEFT 1
# define MOUSE_RIGHT 3
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
	int			color_scheme;

	double		zoom;
	double		offset_x;
	double		offset_y;

	int			is_dragging;
	int			drag_start_x;
	int			drag_start_y;

	t_complex	julia_c;
}				t_fractal;

void	init_fractal_bonus(t_fractal *fract, int type);
void	setup_window_bonus(t_fractal *fract);
void	setup_canvas_bonus(t_fractal *fract);
void	reset_view_bonus(t_fractal *fract);

int		compute_mandelbrot_bonus(double real, double imag, int max_iter);
int		compute_julia_bonus(double real, double imag, t_complex c,
			int max_iter);
int		compute_burning_ship_bonus(double real, double imag, int max_iter);

void	my_pixel_put_bonus(t_canvas *canvas, int x, int y, int color);
void	calc_cmplx_coords_bonus(t_fractal *fract, int x, int y, t_complex *pos);
void	render_fractal_bonus(t_fractal *fract);

int		get_color_bonus(int iter, int max_iter, int scheme);
void	cycle_color_scheme_bonus(t_fractal *fract);
void	cycle_fractal_type_bonus(t_fractal *fract);

int		color_scheme_0_bonus(double ratio);
int		color_scheme_1_bonus(double ratio);
int		color_scheme_2_bonus(double ratio);
int		color_scheme_3_bonus(double ratio);
int		color_scheme_4_bonus(double ratio);

int		pastel_range_1(double ratio);
int		pastel_range_2(double ratio);
int		pastel_range_3(double ratio);
int		pastel_range_4(double ratio);

int		sunset_range_1(double ratio);
int		sunset_range_2(double ratio);
int		sunset_range_3(double ratio);
int		sunset_range_4(double ratio);
int		sunset_range_5(double ratio);

int		ocean_range_1(double ratio);
int		ocean_range_2(double ratio);
int		ocean_range_3(double ratio);

int		fire_range_1(double ratio);
int		fire_range_2(double ratio);
int		fire_range_3(double ratio);
int		fire_range_4(double ratio);
int		fire_range_5(double ratio);

int		galaxy_range_1(double ratio);
int		galaxy_range_2(double ratio);
int		galaxy_range_3(double ratio);
int		galaxy_range_4(double ratio);
int		galaxy_range_5(double ratio);

int		handle_keypress_bonus(int key, t_fractal *fract);
int		handle_mouse_bonus(int button, int x, int y, t_fractal *fract);
int		handle_mouse_move_bonus(int x, int y, t_fractal *fract);
int		handle_close_bonus(t_fractal *fract);

void	zoom_view_bonus(t_fractal *fract, int x, int y, double factor);
void	pan_view_bonus(t_fractal *fract, double dx, double dy);
void	handle_arrow_keys_bonus(int key, t_fractal *fract);

double	ft_atof_bonus(const char *str);
int		is_number_bonus(char *str);
void	error_exit_bonus(char *msg);
void	print_usage_bonus(void);
void	print_controls_bonus(void);

#endif
