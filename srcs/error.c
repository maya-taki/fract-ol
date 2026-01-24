/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 17:07:17 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/01/24 04:46:56 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	ft_error_exit(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(EXIT_FAILURE);
}

void	ft_error_howto(void)
{
	ft_putstr_fd("\n╔════════════════════════════════════╗\n", 2);
	ft_putstr_fd("║        FRACT'OL - HOW TO           ║\n", 2);
	ft_putstr_fd("╠════════════════════════════════════╣\n", 2);
	ft_putstr_fd("║ ./fractol mandelbrot               ║\n", 2);
	ft_putstr_fd("║ ./fractol julia <real> <imag>      ║\n", 2);
	ft_putstr_fd("╠════════════════════════════════════╣\n", 2);
	ft_putstr_fd("║ Examples Julia:                    ║\n", 2);
	ft_putstr_fd("║   ./fractol julia -0.7 0.27015     ║\n", 2);
	ft_putstr_fd("║   ./fractol julia -0.4 0.6         ║\n", 2);
	ft_putstr_fd("║   ./fractol julia 0.285 0.01       ║\n", 2);
	ft_putstr_fd("╚════════════════════════════════════╝\n\n", 2);
}
