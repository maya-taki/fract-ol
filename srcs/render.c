/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 23:03:05 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/01/23 22:47:20 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_mlx_pixel_put(t_image *image, int x, int y, int color)
{
	char	*dst;
	
	if ((x >= 0 && x <= WIDTH) && (y >= 0 && y <= HEIGHT))
	{		
		dst = image->pixels_ptr + (y * image->line_len + (x * (image->bpp / 8)));
		*(unsigned int*)dst = color;
	}
	else
		return ;
}

static void		ft_set_mandelbrot(t_fractal *fractal, int x, int y)
{
	t_complex	c;
	t_complex	z;
	int			iter;
	int			color;

	iter = 0;
	z.x = 0.0;
	z.y = 0.0;
	c.x = ft_map(x, fractal->x_min, fractal->x_max, WIDTH);
	c.y = ft_map(y, fractal->y_min, fractal->y_max, HEIGHT);
	while (iter < fractal->max_iter && z.x < 4)
	{
		z = ft_sum_complex(ft_square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			if (iter == fractal->max_iter)
				color = BLACK;
			else
			{
				color = ft_get_color(iter + 1 - log(log(sqrt(z.x * z.x + z.y * z.y)))/log(2), fractal->max_iter);
			}
			ft_mlx_pixel_put(fractal->img, x, y, color);
			return ;
		}
		iter++;
	}
	ft_mlx_pixel_put(fractal->img, x, y, BLACK);
}

static void		ft_set_julia(t_fractal *fractal, int x, int y)
{
	t_complex	c;
	t_complex	z;
	double		iter;
	int			color;

	iter = 0;
	c.x = fractal->julia_real;
	c.y = fractal->julia_imag;
	z.x = ft_map(x, fractal->x_min, fractal->x_max, WIDTH);
	z.y = ft_map(y, fractal->y_min, fractal->y_max, HEIGHT);
	while (iter < fractal->max_iter)
	{
		z = ft_sum_complex(ft_square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			if (iter == fractal->max_iter)
				color = BLACK;
			else
			{
				color = ft_get_color(iter + 1 - log(log(sqrt(z.x * z.x + z.y * z.y)))/log(2), fractal->max_iter);
			}
			ft_mlx_pixel_put(fractal->img, x, y, color);
			return ;
		}
		iter++;
	}
	ft_mlx_pixel_put(fractal->img, x, y, BLACK);
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
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window, fractal->img->img_ptr, 0, 0);
}