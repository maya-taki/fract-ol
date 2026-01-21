/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 20:42:23 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/01/20 21:04:54 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_init_viewport(t_fractal *fractal)
{
	if (fractal->type == MANDELBROT)
	{
		fractal->x_min = -2.5;
		fractal->x_max = 1.0;
		fractal->y_min = -1.5;
		fractal->y_max = 1.5;
	}
	else if (fractal->type == JULIA)
	{
		fractal->x_min = -2.0;
		fractal->x_max = 2.0;
		fractal->y_min = -2.0;
		fractal->y_max = 2.0;
	}
}

void	ft_data_init(t_fractal *fractal, char *name)
{
	fractal->name = name;
	if (ft_strncmp(name, "mandelbrot", 10) == 0)
		fractal->type = MANDELBROT;	
	else if (ft_strncmp(name, "julia", 6) == 0)
		fractal->type = JULIA;
	fractal->max_iter = MAX_ITERATIONS;
	fractal->color_shift = 0;
	fractal->color_scheme = 0;
	//fractal->zoom = 1.0;
	ft_init_viewport(fractal);
}


void	ft_fractal_init(t_fractal *fractal)
{
	//MLX
	fractal->x_max = WIDTH;
	fractal->y_min = HEIGHT;
	fractal->x_min = 0.0;
	fractal->y_max = 0.0;
	fractal->img.img_ptr = NULL;
	fractal->mlx_connection = mlx_init();
	if (!fractal->mlx_connection)
		ft_error_exit("MLX initialization failed\n");
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection, WIDTH, HEIGHT, fractal->name);
	if (!fractal->mlx_window)
	{
		free(fractal->mlx_connection);
		ft_error_exit("Error: Unable to create window\n");
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection, WIDTH, HEIGHT);
	if (!fractal->img.img_ptr)
	{
		mlx_destroy_display(fractal->mlx);
		return ;
	}
	fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr, &fractal->img.bpp, 
		&fractal->img.line_len, &fractal->img.endian);
	// if (!fractal->img.pixels_ptr)
	// {
	// 	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	// 	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	// 	free(fractal->mlx_connection);
	// 	error_exit("Error: unable to reach pixel buffer.\n");
	// }
}