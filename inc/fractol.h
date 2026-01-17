/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 17:10:49 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/01/17 06:03:41 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <limits.h>
#include <math.h>
#include "mlx.h"
#include "../libft/libft.h"

# define WIDTH	800
# define HEIGHT	800

# define MAX_ITERATIONS 150
# define ESCAPE_RADIUS 2.0

# define MANDELBROT 1
# define JULIA 2

# define BLACK 0x000000FF
# define WHITE 0xFFFFFFFF
# define BLUE 0x0000FFFF
# define RED 0xFF0000FF
# define GREEN 0x00FF00FF
# define YELLOW 0xFFFF00FF

typedef struct	s_complex
{
	double		real;
	double		imag;
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
	//Fractype
	char		*name;
	int			type;
	//MLX
	void		*mlx_connection; //mlx_init()
	void		*mlx_window; //mlx_new_window()
	t_image		*img;
	//Julia
	double		julia_real;
	double		julia_imag;
	//Viewport
	double		x_min;
	double		x_max;
	double		y_min;
	double		y_max;
	//Controls
	int			max_iter;
	double		zoom;
	int			color_shift;
	
}				t_fractal;

void	*error_exit(char *msg);
int		main(int ac, char **av);

void	my_mlx_pixel_put(t_image *data, int x, int y, int color);

void	fractal_init(t_fractal *fractal);
void	fractal_render(t_fractal *fractal);

#endif