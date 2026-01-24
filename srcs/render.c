/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 23:03:05 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/01/24 04:12:20 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_mlx_pixel_put(t_image *image, int x, int y, int color)
{
	char	*dst;

	if ((x >= 0 && x <= WIDTH) && (y >= 0 && y <= HEIGHT))
	{		
		dst = image->pixels_ptr + (y * image->line_len
				+ (x * (image->bpp / 8)));
		*(unsigned int *)dst = color;
	}
}

static int	ft_calculate_fractal(t_fractal *fractal, t_complex c, t_complex *z)
{
	int	iter;

	iter = 0;
	while (iter < fractal->max_iter && (z->x * z->x + z->y * z->y)
		<= fractal->escape_value)
	{
		*z = ft_sum_complex(ft_square_complex(*z), c);
		iter++;
	}
	return (iter);
}

static void	ft_set_mandelbrot(t_fractal *fractal, int x, int y)
{
	t_complex	c;
	t_complex	z;

	z.x = 0.0;
	z.y = 0.0;
	c.x = ft_map(x, fractal->x_min, fractal->x_max, WIDTH);
	c.y = ft_map(y, fractal->y_min, fractal->y_max, HEIGHT);
	ft_mlx_pixel_put(fractal->img, x, y, ft_get_pixel_color
		(ft_calculate_fractal(fractal, c, &z), z, fractal->max_iter));
}

static void	ft_set_julia(t_fractal *fractal, int x, int y)
{
	t_complex	c;
	t_complex	z;

	z.x = ft_map(x, fractal->x_min, fractal->x_max, WIDTH);
	z.y = ft_map(y, fractal->y_min, fractal->y_max, HEIGHT);
	c.x = fractal->julia_real;
	c.y = fractal->julia_imag;
	ft_mlx_pixel_put(fractal->img, x, y, ft_get_pixel_color
		(ft_calculate_fractal(fractal, c, &z), z, fractal->max_iter));
}

void	ft_fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;
	int	color;

	(void)color;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (fractal->type == JULIA)
				ft_set_julia(fractal, x, y);
			else if (fractal->type == MANDELBROT)
				ft_set_mandelbrot(fractal, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx_connection,
		fractal->mlx_window, fractal->img->img_ptr, 0, 0);
}
