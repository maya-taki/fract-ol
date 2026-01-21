/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 01:18:51 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/01/20 22:26:12 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_mandelbrot(t_complex c, int max_iter)
{
	t_complex z = {0, 0};
	double	temp_real;
	int			iter;

	iter = 0;
	while ((z.real * z.real + z.imag * z.imag) <= 4.0 && iter < max_iter)
	{
		temp_real = z.real * z.real - z.imag * z.imag + c.real;
		z.imag = 2.0 * z.real * z.imag + c.imag;
		z.real = temp_real;
		iter++;
	}
	return (iter);
}

int ft_julia(t_complex z, t_complex c, int max_iter)
{
	int		iter;
	double	temp_real;

	iter = 0;
	while ((z.real * z.real + z.imag * z.imag) <= 4.0 && iter < max_iter)
	{
		temp_real = z.real * z.real - z.imag * z.imag + c.real;
		z.imag = 2.0 * z.real * z.imag + c.imag;
		z.real = temp_real;
		iter++;
	}
	return (iter);
}