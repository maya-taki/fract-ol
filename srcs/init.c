/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulo-c <rpaulo-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 20:42:23 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/01/17 05:57:49 by rpaulo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//TODO

void	fractal_init(t_fractal *fractal)
{
	//MLX
	fractal->mlx_connection = mlx_init();
	if (fractal->mlx_connection == NULL)
	{
		malloc_error(); //TODO
		error_exit("MLX initialization failed\n");
	}
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection, mlx_ptr:
										WIDTH, size_x:
										HEIGHT, size y:
										fractal->name); title:
	if (!fractal->img)
	{
		mlx_terminate(fractal->mlx_window);
		return(0);
	}
	if (mlx_image_to_window(fractal->mlx_window, fractal->img, 0, 0) < 0)
	{
		mlx_delete_image(fractal->mlx_window, fractal->img);
		mlx_terminate(fractal->mlx_window);
	}
}

void	fractal_render(t_fractal *fractal)
{
	(void)fractal;
}
