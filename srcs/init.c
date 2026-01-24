/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 20:42:23 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/01/24 04:01:58 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_init_viewport(t_fractal *fractal)
{
	if (fractal->type == MANDELBROT)
	{
		fractal->x_min = -2.0;
		fractal->x_max = 2.0;
		fractal->y_min = 2.0;
		fractal->y_max = -2.0;
	}
	else if (fractal->type == JULIA)
	{
		fractal->x_min = -2.0;
		fractal->x_max = 2.0;
		fractal->y_min = 2.0;
		fractal->y_max = -2.0;
	}
}

void	ft_data_init(t_fractal *fractal)
{
	if (ft_strncmp(fractal->name, "mandelbrot", 10) == 0)
		fractal->type = MANDELBROT;
	else if (ft_strncmp(fractal->name, "julia", 5) == 0)
		fractal->type = JULIA;
	fractal->max_iter = MAX_ITERATIONS;
	fractal->color_shift = 0;
	fractal->color_scheme = 0;
	fractal->escape_value = 4;
	fractal->zoom = 1.2;
	fractal->max_iter = 40;
	ft_init_viewport(fractal);
}

static void	ft_init_mlx(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (!fractal->mlx_connection)
		ft_error_exit("MLX initialization failed\n");
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection,
			WIDTH, HEIGHT, fractal->name);
	if (!fractal->mlx_window)
	{
		free(fractal->mlx_connection);
		ft_error_exit("Error: Unable to create window\n");
	}
}

static void	ft_init_image(t_fractal *fractal)
{
	fractal->img = ft_calloc(1, sizeof(t_image));
	if (!fractal->img)
		ft_error_exit("Error: Image allocation failed\n");
	fractal->img->img_ptr = mlx_new_image(fractal->mlx_connection,
			WIDTH, HEIGHT);
	if (!fractal->img->img_ptr)
		ft_error_exit("Error: Unable to create image\n");
	fractal->img->pixels_ptr = mlx_get_data_addr(fractal->img->img_ptr,
			&fractal->img->bpp, &fractal->img->line_len, &fractal->img->endian);
	if (!fractal->img->pixels_ptr)
	{
		mlx_destroy_image(fractal->mlx_connection, fractal->img->img_ptr);
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		free(fractal->mlx_connection);
		ft_error_exit("Error: unable to reach pixel buffer\n");
	}
}

void	ft_fractal_init(t_fractal *fractal)
{
	ft_init_mlx(fractal);
	ft_init_image(fractal);
	ft_data_init(fractal);
}
