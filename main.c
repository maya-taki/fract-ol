/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:54:02 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/01/17 05:01:18 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	if ((x >= 0 && x <= 1920) && (y >= 0 && y <= 1080))
	{
		dst = data->pixels_ptr + (y * data->line_len + x * (data->bpp / 8));
		*(unsigned int*)dst = color;
	}
}

int	main(int ac, char **av)
{
	t_fractal	fractal;
	void		*mlx;
	void		*mlx_win;
	
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
