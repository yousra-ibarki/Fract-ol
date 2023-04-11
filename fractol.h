/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoibarki <yoibarki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:11:21 by yoibarki          #+#    #+#             */
/*   Updated: 2023/04/09 10:03:28 by yoibarki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define H 800
# define W 800

# define KEY_ESC 53
# define KEY_DWN 125
# define KEY_UP 126
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_PLUS 69
# define KEY_MINUS 78

# define MOUSE_DWN 4
# define MOUSE_UP 5
# define MOUSE_MOVE 6
# define MOUSE_LEFT 1
# define MOUSE_RIGHT 2
# define MOUSE_MIDLLE 3

# define A 0
# define B 11
# define C 8
# define D 2
# define E 14
# define F 3
# define G 5
# define KEY_H 4
# define I 34
# define J 38
# define K 40
# define L 37
# define M 46
# define N 45
# define O 31
# define P 35
# define Q 13
# define R 15
# define S 1
# define T 17
# define U 32
# define KEY_W 13
# define X 7
# define Y 16
# define Z 6

typedef struct s_variable
{
	void	*mlx;
	void	*mlx_win;
	void	*mlx_img;
	int		black;
	int		color;
	int		llen;
	int		end;
	int		bit_pixel;
	int		maxiteration;
	int		n;
	int		flag;
	int		id;
	char	*addr;
	double	mnr;
	double	mxr;
	double	mni;
	double	mxi;
	double	rfactor;
	double	ifactor;
	double	y;
	double	x;
	double	c_im;
	double	c_re;
	double	z_re;
	double	z_im;
	double	z_re2;
	double	z_im2;
	double	a;
	double	b;
	double	olda;
	double	oldb;
	double	newa;
	double	newb;
	double	z;
	double	x_center;
	double	y_center;
	double	distancea;
	double	distanceb;

}			t_variable;

int			handel_key(int key, t_variable *var);
void		ft_mandelbrot(t_variable *var);
void		ft_julia(t_variable *var);
void		my_mlx_pixel_put(t_variable *var, int x, int y, int color);
int			cross(t_variable *var);
int			mouse_move(int key, int x, int y, t_variable *var);
void		ft_tricorn(t_variable *var);
int			ft_color(t_variable *var);
int			ft_change_color(t_variable *var, int r, int b, int g);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
size_t		ft_strlen(const char *s);
void		ft_error(void);
void		ft_redraw(t_variable *var);
void		ft_init(t_variable *var);

#endif
