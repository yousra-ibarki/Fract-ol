/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoibarki <yoibarki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:13:28 by yoibarki          #+#    #+#             */
/*   Updated: 2023/04/11 12:13:05 by yoibarki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error(void)
{
	write(1, "Error: choose one of the folowing arguments:\n", 46);
	write(1, "\t-> For Mandelbrot write Mandelbrot\n", 37);
	write(1, "\t->For Julia write Julia\n", 26);
	write(1, "\t->For Tricorn write Tricorn\n", 30);
	exit(1);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*ss1;
	unsigned char	*ss2;
	size_t			i;

	i = 0;
	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	if (!n)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n - 1)
		i++;
	return (ss1[i] - ss2[i]);
}

void	ft_redraw(t_variable *var)
{
	if (var->id == 0)
		ft_mandelbrot(var);
	if (var->id == 1)
		ft_julia(var);
	if (var->id == 2)
		ft_tricorn(var);
}
