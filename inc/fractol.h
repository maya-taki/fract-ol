/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 17:10:49 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/01/14 21:47:53 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <limits.h>
#include <math.h>
#include "../minilibx/mlx.h"
#include "../libft/libft.h"

typedef struct 	s_image
{
	void		*img_ptr; //pointer to image struct
	char		*pixels_ptr; //points to the actual pixels
	int			bpp; //bits per pixel
	int			endian;
	int			line_len;
}				t_image;

typedef	struct	s_fractal
{
	//MLX
	void		*mlx_connection; //mlx_init()
	void		*mlx_window; //mlx_new_window()
	//Image
	t_image		*img;
	
	//Hooks member variables //TODO
}				t_fractal;

void	*error_exit(char *msg);


#endif