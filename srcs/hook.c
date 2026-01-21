/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 23:02:45 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/01/20 21:04:20 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_key_press(int keycode, void *param)
{
	t_fractal *button;

	button = (t_fractal *)param;
	if (keycode == KEY_ESC)
		button->keys.esc = 1;
	return (0);
}

int	ft_key_release(int keycode, void *param)
{
	t_fractal *button;
	button = (t_fractal *)param;
	if (keycode == KEY_ESC)
		button->keys.esc = 0;
	return (0);
}


int	ft_close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	ft_printf("Closing Fract-ol Window\n\n");
	exit (1);
	return (0);
}

// int	ft_key_handler(int keycode, t_fractal *fractal)
// {
// 	double	move_step;

// 	move_step = (fractal->x_max - fractal->x_min) * 0.05;
// 	if (keycode == KEY_ESC)
// 		ft_close_handler(fractal);
// 	else if (keycode == KEY_LEFT)
// 	{
// 		fractal->x_min -= move_step;
// 		fractal->x_max -= move_step;
// 	}
// 	else if (keycode == KEY_RIGHT)
// 	{
// 		fractal->x_min += move_step;
// 		fractal->x_max += move_step;
// 	}
// 	else if (keycode == KEY_UP)
// 	{
// 		fractal->y_min += move_step;
// 		fractal->y_max += move_step;
// 	}
// 	else if (keycode == KEY_DOWN)
// 	{
// 		fractal->y_min -= move_step;
// 		fractal->y_max -= move_step;
// 	}
// 	ft_fractal_render(fractal);
// 	return (0);
// }
