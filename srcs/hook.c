/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 23:02:45 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/01/24 03:43:50 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_close_handler(t_fractal *fractal)
{
	if (fractal->img)
		mlx_destroy_image(fractal->mlx_connection, fractal->img->img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	free(fractal->img);
	ft_printf("Closing Fract-ol Window\n\n");
	exit (EXIT_SUCCESS);
	return (0);
}

static void	ft_move_view(t_fractal *fractal, int keycode, double move_step)
{
	if (keycode == KEY_LEFT || keycode == KEY_A)
	{
		fractal->x_min -= move_step;
		fractal->x_max -= move_step;
	}
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
	{
		fractal->x_min += move_step;
		fractal->x_max += move_step;
	}
	else if (keycode == KEY_UP || keycode == KEY_W)
	{
		fractal->y_min += move_step;
		fractal->y_max += move_step;
	}
	else if (keycode == KEY_DOWN || keycode == KEY_S)
	{
		fractal->y_min -= move_step;
		fractal->y_max -= move_step;
	}
}

int	ft_key_handler(int keycode, t_fractal *fractal)
{
	if (keycode == KEY_ESC)
		ft_close_handler(fractal);
	else
		ft_move_view(fractal, keycode,
			(fractal->x_max - fractal->x_min) * 0.05);
	ft_fractal_render(fractal);
	return (0);
}

int	ft_mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	double	mouse_re;
	double	mouse_im;

	mouse_re = ft_map(x, fractal->x_min, fractal->x_max, WIDTH);
	mouse_im = ft_map(y, fractal->y_min, fractal->y_max, HEIGHT);
	fractal->zoom = 1.1;
	if (button == MOUSE_WHEEL_UP)
	{
		fractal->x_min = mouse_re + (fractal->x_min - mouse_re) / fractal->zoom;
		fractal->x_max = mouse_re + (fractal->x_max - mouse_re) / fractal->zoom;
		fractal->y_max = mouse_im + (fractal->y_max - mouse_im) / fractal->zoom;
		fractal->y_min = mouse_im + (fractal->y_min - mouse_im) / fractal->zoom;
	}
	else if (button == MOUSE_WHEEL_DOWN)
	{
		fractal->x_min = mouse_re + (fractal->x_min - mouse_re) * fractal->zoom;
		fractal->x_max = mouse_re + (fractal->x_max - mouse_re) * fractal->zoom;
		fractal->y_max = mouse_im + (fractal->y_max - mouse_im) * fractal->zoom;
		fractal->y_min = mouse_im + (fractal->y_min - mouse_im) * fractal->zoom;
	}
	ft_fractal_render(fractal);
	return (0);
}
