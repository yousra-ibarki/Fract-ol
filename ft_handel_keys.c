/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handel_keys.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoibarki <yoibarki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:18:30 by yoibarki          #+#    #+#             */
/*   Updated: 2023/04/11 13:09:55 by yoibarki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	cross(t_variable *var)
{
	(void)*var;
	exit(0);
}

static void	ft_map(t_variable *var, int x, int y)
{
	if (x > W || y > H || x < 0 || y < 0)
		return ;
	var->newa = var->mxi - y * ((var->mxr - var->mnr)) / W;
	var->newb = var->mnr + x * ((var->mxi - var->mni)) / H;
}

int	mouse_move(int key, int x, int y, t_variable *var)
{
	if (key == MOUSE_LEFT && var->id == 1)
	{
		if (x > W || y > H || x < 0 || y < 0)
			return (0);
		var->a = var->mxi - y * ((var->mxr - var->mnr)) / W;
		var->b = var->mnr + x * ((var->mxi - var->mni)) / H;
		ft_julia(var);
	}
	else if (key == MOUSE_UP)
	{
		ft_map(var, x, y);
		var->z /= 0.9;
		ft_redraw(var);
		return (0);
	}
	else if (key == MOUSE_DWN)
	{
		ft_map(var, x, y);
		var->z *= 0.9;
		ft_redraw(var);
		return (0);
	}
	return (0);
}

int	handel_key(int key, t_variable *var)
{
	if (key == KEY_ESC)
		exit(0);
	else if (key == 8 || key == 48)
	{
		var->color = ft_color(var);
		var->flag++;
	}
	if (key == KEY_LEFT)
		var->distancea -= 0.025;
	else if (key == KEY_RIGHT)
		var->distancea += 0.025;
	else if (key == KEY_UP)
		var->distanceb += 0.025;
	else if (key == KEY_DWN)
		var->distanceb -= 0.025;
	ft_redraw(var);
	return (0);
}
