/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoibarki <yoibarki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:58:45 by yoibarki          #+#    #+#             */
/*   Updated: 2023/04/11 17:21:37 by yoibarki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_call_fractal(t_variable *var, char *str)
{
	var->id = 0;
	if ((!ft_strncmp(str, "Mandelbrot", ft_strlen(str)) || !ft_strncmp(str,
				"mandelbrot", ft_strlen(str))) && ft_strlen(str) == 10)
	{
		ft_mandelbrot(var);
		var->id = 0;
	}
	else if ((!ft_strncmp(str, "Julia", ft_strlen(str)) || !ft_strncmp(str,
				"julia", ft_strlen(str))) && ft_strlen(str) == 5)
	{
		ft_julia(var);
		var->id = 1;
	}
	else if ((!ft_strncmp(str, "Tricorn", ft_strlen(str)) || !ft_strncmp(str,
				"tricorn", ft_strlen(str))) && ft_strlen(str) == 7)
	{
		ft_tricorn(var);
		var->id = 2;
	}
	else
		ft_error();
	return (var->id);
}

void	ft_init(t_variable *var)
{
	var->mnr = -2.0;
	var->mxr = 2.0;
	var->mni = -2.0;
	var->mxi = 2.0;
	var->a = -0.54;
	var->b = 0.54;
	var->flag = 0;
	var->z = 0.5;
	var->x_center = -0.01;
	var->y_center = 0.01;
	var->maxiteration = 80;
	var->distancea = 0;
	var->distanceb = 0;
	var->id = 0;
	var->black = 0x000000;
}

int	main(int ac, char **av)
{
	t_variable	var;

	if (ac == 2)
	{
		ft_init(&var);
		var.mlx = mlx_init();
		var.mlx_win = mlx_new_window(var.mlx, W, H, "");
		var.mlx_img = mlx_new_image(var.mlx, W, H);
		var.addr = mlx_get_data_addr(var.mlx_img, &var.bit_pixel, &var.llen,
				&var.end);
		var.id = ft_call_fractal(&var, av[1]);
		mlx_key_hook(var.mlx_win, handel_key, &var);
		mlx_hook(var.mlx_win, 17, 1L << 0, cross, &var);
		mlx_hook(var.mlx_win, 4, 0, mouse_move, &var);
		mlx_loop(var.mlx);
	}
	else
		ft_error();
}
