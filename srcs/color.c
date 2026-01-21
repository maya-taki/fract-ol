/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 14:42:31 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/01/20 22:48:14 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_get_color(int iter, int max_iter)
{
	int	r;
	int	g;
	int	b;
	if (iter == max_iter)
		return (0x000000);
	double	t;
	t = (double)iter / (double)max_iter;
	r =	(int)(9 * (1-t) * t * t * t * 255); 
	g = (int)(15 * (1-t) * (1-t) * t * t * 255);
	b =	(int)(8.5 * (1-t) * (1-t) * (1-t) * t * 255);

	return ((r << 16) | (g << 8) | b);
}