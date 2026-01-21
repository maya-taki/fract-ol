/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 23:03:05 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/01/20 22:47:52 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_mlx_pixel_put(t_fractal *fractal, int x, int y, int color)
{
	char	*dst;
	
	if ((x >= 0 && x <= WIDTH) && (y >= 0 && y <= HEIGHT))
	{		
		dst = fractal->img.pixels_ptr + (y * fractal->img.line_len + x * (fractal->img.bpp / 8));
		*(unsigned int*)dst = color;
	}
	else
		return ;
}

double		map(double value, double in_min, double in_max, double out_min, double out_max)
{
	return (out_min + (value - in_min) * (out_max - out_min) / (in_max - in_min));
}

static int	calculate_pixel(t_fractal *fractal, int x, int y)
{
	t_complex	c;
	t_complex	z;
	int			iter;

	iter = 0;
	c.real = map(x, 0, WIDTH, fractal->x_min, fractal->x_max);
	c.imag = map(y, 0, HEIGHT, fractal->y_max, fractal->y_min);
	// how many times you want to iterate z^2 + c
	if (fractal->type == MANDELBROT)
	{		
		iter = ft_mandelbrot(c, fractal->max_iter);
	}
	else if (fractal->type == JULIA)
	{
		z.real = c.real;
		z.imag = c.imag;
		c.real = fractal->julia_real;
		c.imag = fractal->julia_imag;
		iter = ft_julia(z, c, fractal->max_iter);
	}
	return (ft_get_color(iter, fractal->max_iter));
}

void	ft_fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;
	int	color;

	x = 0;
	y = 0;
	while (x < HEIGHT)
	{
		y = 0;
		while (y < WIDTH)
		{
			//color = 0xFFFFFF;			
			color = calculate_pixel(fractal, x, y);
			ft_mlx_pixel_put(fractal, x, y, color);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window, fractal->img.img_ptr, 0, 0);
}