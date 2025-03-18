/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:22:17 by gbodur            #+#    #+#             */
/*   Updated: 2025/03/18 14:22:00 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include "./libft/libft.h"
# include "./minilibx-linux/mlx.h"

# define WINDOW_WIDTH 1000
# define WINDOW_HEIGHT 800
# define WINDOW_TITLE "Fractal Explorer"

# define TYPE_MANDELBROT 0
# define TYPE_JULIA 1
# define TYPE_BURNING_SHIP 2

typedef struct s_canvas
{
	void		*img_ptr;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
}				t_canvas;

typedef	struct s_fractal
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

void    init_fractal(t_fractal *fract, int type);
void    setup_window(t_fractal *fract);
void    setup_canvas(t_fractal *fract);
void    reset_view(t_fractal *fract);

int     compute_mandelbrot(double x, double y, int limit);
int     compute_julia(double x, double y, double cr, double ci, int limit);
int     compute_burning_ship(double x, double y, int limit);

void    render_fractal(t_fractal *fract);
void    draw_pixel(t_canvas *canvas, int x, int y, int color);
int     get_color(int iter, int max_iter, int color_scheme);
void    update_display(t_fractal *fract);

int     handle_keypress(int key, t_fractal *fract);
int     handle_mouse_button(int button, int x, int y, t_fractal *fract);
int     handle_mouse_move(int x, int y, t_fractal *fract);
int     handle_close(t_fractal *fract);

void    zoom_view(t_fractal *fract, int x, int y, double factor);
void    pan_view(t_fractal *fract, double dx, double dy);
void    cycle_color_scheme(t_fractal *fract);
void    cycle_fractal_type(t_fractal *fract);

void    show_usage(void);
double  map_range(double val, double in_min, double in_max, double out_min, double out_max);

#endif
