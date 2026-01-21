/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 17:07:17 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/01/20 19:19:55 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	*ft_error_exit(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(EXIT_FAILURE);	
}

void	malloc_error();