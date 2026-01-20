/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 01:18:51 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/01/19 20:46:26 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_complex c, int max_iter)
{
	t_complex	z;
	int			i;
	double		z_real_sq;
	double		z_imag_sq;
	
	z.real = 0.0;
	z.imag= 0.0;
	z_real_sq = 0.0;
	z_imag_sq = 0.0;
	i = 0;
	
	while (i < max_iter)
	{
		// z² = (a + bi)² a² - b² + 2abi
		z.real = z.real * z.real;
		z_imag_sq = z.imag * z.imag;
		if (z_real_sq + z_imag_sq > 4.0)
			break ;
		z.imag = 2.0 * z.real * z.imag + c.imag;
		z.real = z_real_sq - z_imag_sq + c.real;
		i++;
	}
	return (i);
}

int julia(t_complex z, t_complex c, t_fractal *fractal, int max_iter)
{
	int		i;
	double	z_real_sq;
	double	z_imag_sq;
	(void)c;
	(void)max_iter;
	
	i = 0;
	while (i < fractal->max_iter)
	{
		z_real_sq = z.real * z.real;
		z_imag_sq = z.imag * z.imag;
		if (z_real_sq + z_imag_sq > 4.0)
			break ;
		z.imag = 2.0 * z.real * z.imag + fractal->julia_imag;
		z.real = z_real_sq - z_imag_sq + fractal->julia_real;
		i++;
	}
	return (i);
}