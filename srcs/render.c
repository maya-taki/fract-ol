/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 23:03:05 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/01/19 21:10:27 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;
	
	if ((x >= 0 && x <= WIDTH) && (y >= 0 && y <= HEIGHT))
	{		
		dst = data->pixels_ptr + (y * data->line_len + x * (data->bpp / 8));
		*(unsigned int*)dst = color;
	}
	else
		return ;
}
void	fractal_render(t_fractal *fractal)
{
	int	i = 0;
	int	j = 0;
	__uint64_t	color = 255;

	while (i < 800)
	{
		j = 0;
		while (j < 800)
		{
			color--;
			my_mlx_pixel_put(&fractal->img, i, j, color);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window, fractal->img.img_ptr, 0, 0);
}