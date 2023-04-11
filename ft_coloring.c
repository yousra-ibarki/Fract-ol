/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coloring.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoibarki <yoibarki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:23:26 by yoibarki          #+#    #+#             */
/*   Updated: 2023/04/08 16:48:24 by yoibarki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_color(t_variable *var)
{
	double	i;
	int		r;
	int		g;
	int		b;

	i = var->n / (double)var->maxiteration;
	r = 5555 * i * i * i * (1 - i);
	g = 4444 * i * i * (1 - i) * (1 - i);
	b = 3333 * i * (1 - i) * (1 - i) * (1 - i);
	return (ft_change_color(var, r, g, b));
}

int	ft_change_color(t_variable *var, int r, int b, int g)
{
	if (var->flag == 0)
		return (0 << 24 | b << 16 | r << 8 | g);
	if (var->flag == 1)
		return (0 << 24 | r << 16 | g << 8 | b);
	if (var->flag == 2)
		return (0 << 24 | g << 16 | r << 8 | b);
	if (var->flag == 3)
		return (0 << 24 | r << 16 | b << 8 | g);
	if (var->flag == 4)
		return (0 << 24 | b << 16 | g << 8 | r);
	if (var->flag == 5)
	{
		var->flag = 0;
		return (0 << 24 | g << 16 | b << 8 | r);
	}
	return (0);
}
