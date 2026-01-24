/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 14:42:31 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/01/23 23:11:21 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_clamp_color(int *r, int *g, int *b)
{
	if (*r < 0)
		*r = 0;
	else if (*r > 255)
		*r = 255;
	if (*g < 0)
		*g = 0;
	else if (*g > 255)
		*g = 255;
	if (*b < 0)
		*b = 0;
	else if (*b > 255)
		*b = 255;
}

int		ft_get_color(double iter, double max_iter)
{
	int	r;
	int	g;
	int	b;
	double	t;
	
	if (iter == max_iter)
		return (0x000000);
	t = iter / max_iter;
	r =	(int)(9 * (1 - t) * t * t * t * 255); 
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b =	(int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	
	ft_clamp_color(&r, &g, &b);
	return (r << 16 | g << 8 | b);
}