/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoibarki <yoibarki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 16:13:12 by yoibarki          #+#    #+#             */
/*   Updated: 2023/04/11 20:57:02 by yoibarki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_calcule_julia(t_variable *var)
{
	while (var->n < var->maxiteration)
	{
		var->z_re2 = var->z_re * var->z_re;
		var->z_im2 = var->z_im * var->z_im;
		var->z_im = 2 * var->z_re * var->z_im + var->b;
		var->z_re = var->z_re2 - var->z_im2 + var->a;
		if (var->z_re2 + var->z_im2 > 4)
			break ;
		(var->n)++;
	}
}

void	ft_julia(t_variable *var)
{
	var->y = 0;
	while (var->y < H)
	{
		var->x = 0;
		while (var->x < W)
		{
			var->c_re = var->x_center + (var->x - W / 2) / (0.5 * var->z * W)
				+ var->distancea;
			var->c_im = var->y_center + (var->y - W / 2) / (0.5 * var->z * W)
				+ var->distanceb;
			var->z_re = var->c_re;
			var->z_im = var->c_im;
			var->n = 0;
			ft_calcule_julia(var);
			if (var->n != var->maxiteration)
				my_mlx_pixel_put(var, var->x, var->y, ft_color(var));
			else
				my_mlx_pixel_put(var, var->x, var->y, var->black);
			(var->x)++;
		}
		(var->y)++;
	}
	mlx_put_image_to_window(var->mlx, var->mlx_win, var->mlx_img, 0, 0);
}
