/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:54:02 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/01/23 22:41:46 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_fractal	fractal;
	
	if (ac < 2)
		return (ft_error_exit("git gud\n"));
	if (!ft_strncmp(av[1], "mandelbrot", 11))
		fractal.type = MANDELBROT;
	else if (!ft_strncmp(av[1], "julia", 5) && ac == 4)
	{
		fractal.type = JULIA;
		if (!ft_isdouble(av[2]) || !ft_isdouble(av[3]))
			return (ft_error_exit("error\n"));
		fractal.julia_real = ft_atod(av[2]); 
		fractal.julia_imag = ft_atod(av[3]);
	}	
	else
		return (ft_error_exit("invalid fractol git gud\n"));
	fractal.name = av[1];
	ft_fractal_init(&fractal);
	ft_fractal_render(&fractal);
	mlx_hook(fractal.mlx_window, 2, 1L<<0, ft_key_handler, &fractal);
	mlx_hook(fractal.mlx_window, 4, 1L<<2, ft_mouse_handler, &fractal);
	mlx_hook(fractal.mlx_window, 17, 1L<<17, ft_close_handler, &fractal);
	//ft_destroy_env(fractal);
	mlx_loop(fractal.mlx_connection);
	return (EXIT_SUCCESS);
}

//TODO hooks -> mouse, keyboard and camera movements
//TODO validations
//TODO error notifs
