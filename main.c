/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:54:02 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/01/14 21:45:58 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/fractol.h"

int	main(int ac, char **av)
{
	t_fractal	fractal;
	
	if (2 == ac && !ft_strncmp(av[1], "mandelbrot", 10) //TODO
	|| 4 == ac && !ft_strncmp(av[1], "julia", 5))
	{
		fractal_init(&fractal); //1
		fractal_render(&fractal); //2

		// code
		
		mlx_loop(fractal.mlx_connection); //3
	}
	else
		error_exit("Error\nTry typing: mandelbrot or julia [] []");
}


