/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:54:02 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/01/24 04:30:33 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_mlx_hook_init(t_fractal fractal)
{
	ft_fractal_init(&fractal);
	ft_fractal_render(&fractal);
	mlx_hook(fractal.mlx_window, 2, 1L << 0, ft_key_handler, &fractal);
	mlx_hook(fractal.mlx_window, 4, 1L << 2, ft_mouse_handler, &fractal);
	mlx_hook(fractal.mlx_window, 17, 1L << 17, ft_close_handler, &fractal);
	mlx_loop(fractal.mlx_connection);
}

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if (ac < 2)
		return (ft_error_exit("\n"));
	if (!ft_strncmp(av[1], "mandelbrot", 11))
		fractal.type = MANDELBROT;
	else if (!ft_strncmp(av[1], "julia", 6) && ac == 4)
	{
		fractal.type = JULIA;
		if (!ft_isdouble(av[2]) || !ft_isdouble(av[3]))
		{
			ft_error_howto();
			return (0);
		}
		fractal.julia_real = ft_atod(av[2]);
		fractal.julia_imag = ft_atod(av[3]);
	}	
	else
	{
		ft_error_howto();
		return (0);
	}
	fractal.name = av[1];
	ft_mlx_hook_init(fractal);
	return (EXIT_SUCCESS);
}
