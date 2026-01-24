/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 17:10:49 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/01/23 23:10:22 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <limits.h>
#include <math.h>
#include "mlx.h"
#include "../libft/libft.h"

# define WIDTH	800
# define HEIGHT	600

# define MAX_ITERATIONS 150

# define MANDELBROT 1
# define JULIA 2

# define BLACK				0x00000000
# define WHITE				0xFFFFFFFF
# define BLUE				0x000000FF
# define RED				0xFF0000FF
# define GREEN				0x00FF00FF
# define YELLOW				0xFFFF00FF

# define KEY_ESC			65307
# define KEY_W				119
# define KEY_A				97
# define KEY_S				115
# define KEY_D				100
# define KEY_RIGHT			65363
# define KEY_LEFT			65361
# define KEY_UP				65362
# define KEY_DOWN			65364

# define MOUSE_LEFT			1
# define MOUSE_MIDDLE		2
# define MOUSE_RIGHT		3
# define MOUSE_WHEEL_UP		4
# define MOUSE_WHEEL_DOWN	5

# define DESTROY_NOTIFY		17 // x to close window

typedef struct	s_key_maps
{
	int			esc;
}				t_key_maps;

typedef struct	s_complex
{
	double		x;
	double		y;
}				t_complex;

typedef struct 	s_image
{
	void		*img_ptr; //pointer to image struct
	char		*pixels_ptr; //points to the actual pixels
	int			bpp; //bits per pixel
	int			endian;
	int			line_len;
}				t_image;

typedef	struct	s_fractal
{
	char		*name;
	int			type;
	void		*mlx;
	void		*mlx_connection; //mlx_init()
	void		*mlx_window; //mlx_new_window()
	t_image		*img;
	t_key_maps	keys;
	double		escape_value;
	double		julia_real;
	double		julia_imag;
	double		x_min;
	double		x_max;
	double		y_min;
	double		y_max;
	double		max_iter;
	double		zoom;
	int			color_shift;
	int			color_scheme;
	
}				t_fractal;

int			ft_error_exit(char *msg);
int			main(int ac, char **av);

void		ft_data_init(t_fractal *fractal);
void		ft_fractal_init(t_fractal *fractal);
void		ft_fractal_render(t_fractal *fractal);

double		ft_map(double value, double new_min, double new_max, double old_max);
		   
int			ft_get_color(double iter, double max_iter);

/* =================================================== */
/* -----------------------UTILS----------------------- */
/* =================================================== */
int			ft_isdouble(char *nptr);
t_complex	ft_square_complex(t_complex z);
t_complex	ft_sum_complex(t_complex z, t_complex c);

/* =================================================== */
/* -----------------------HOOKS----------------------- */
/* =================================================== */
int			ft_key_handler(int keycode, t_fractal *fractal);
int			ft_close_handler(t_fractal *fractal);
int			ft_mouse_handler(int button, int x, int y, t_fractal *fractal);



#endif