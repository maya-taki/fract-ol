/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:54:02 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/01/19 20:40:22 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_fractal	fractal;
	
	if ((ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10)) //TODO
	|| (ac == 4 && !ft_strncmp(av[1], "julia", 5)))
	{
		fractal.name = av[1];
		fractal_init(&fractal);
		fractal_render(&fractal); //2
		mlx_loop(fractal.mlx_connection); //3
	}
	else
		error_exit("Error\nTry typing: mandelbrot or julia [] []");
}