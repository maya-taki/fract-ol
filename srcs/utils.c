/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:34:33 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/01/23 17:08:39 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_isdouble(char *nptr)
{
	if (*nptr == '.')
		return (0);
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	if (*nptr == '\0')
		return (0);
	while (ft_isdigit(*nptr))
		nptr++;
	if (*nptr == '.')
		nptr++;
	if (*nptr == '.')
		return (0);
	while (ft_isdigit(*nptr))
	{
		nptr++;
	}
	if (*nptr == '\0')
		return (1);
	return (0);
}