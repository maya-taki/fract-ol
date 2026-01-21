/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:54:02 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/01/20 21:04:44 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"




int	main(int ac, char **av)
{
	t_fractal	fractal;
	
	if ((ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10)) //TODO
	|| (ac == 4 && !ft_strncmp(av[1], "julia", 6)))
	{
		fractal.name = av[1];
		ft_fractal_init(&fractal);
		ft_fractal_render(&fractal); //2
	//	mlx_key_hook(fractal.mlx_connection, fractal.handle_input, &fractal);
		mlx_loop(fractal.mlx_connection); //3
	}
	else
		ft_error_exit("Error\nTry typing: mandelbrot or julia [] []");
	
}	