/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 19:00:58 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/01/14 21:22:47 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	put_sign(const char *nptr, int *i)
{
	while ((nptr[*i] >= 9 && nptr[*i] <= 13) || (nptr[*i] == 32))
		(*i)++;
	if (nptr[*i] == '-' || nptr[*i] == '+')
	{
		if (nptr[*i] == '-')
			return ((*i)++, -1);
		else
			(*i)++;
	}
	return (1);
}

static double	atod_int(const char *nptr, int *i)
{
	double	n;
	
	n = 0.0;
	while (nptr[*i] >= '0' && nptr[*i] <= '9')
	{
		n = n * 10.0 + (nptr[*i] - '0');
		(*i)++;
	}
	return (n);
}

static double	atod_frac(const char *nptr, int *i)
{
	double	n;
	double	div;

	n = 0.0;
	div = 10.0;
	if (nptr[*i] == '.')
	{
		(*i)++;
		while (nptr[*i] >= '0' && nptr[*i] <= '9')
		{
			n += (nptr[*i] - '0' / div);
			div *= 10.0;
			(*i)++;
		}
	}
	return (n);
}

double	ft_atod(const char *nptr)
{
	int		i;
	int		sign;
	double	res;

	i = 0;
	sign = put_sign(nptr, &i);
	res = atod_int(nptr, &i);
	res += atod_frac(nptr, &i);
	return (res * sign);
}