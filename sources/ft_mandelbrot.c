/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 15:51:51 by vcaquant          #+#    #+#             */
/*   Updated: 2016/11/19 17:53:42 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		findmandelbrot(t_env *env)
{
	double	tmp;
	int		i;

	i = 0;
	env->zr = 0 + env->var_zr;
	env->zi = 0 + env->var_zi;
	while ((env->zr * env->zr + env->zi * env->zi) < 4 &&
			i < env->it_max)
	{
		tmp = env->zr * env->zr - env->zi * env->zi + env->cr;
		env->zi = 2 * env->zi * env->zr + env->ci;
		env->zr = tmp;
		i++;
	}
	return (i);
}

void	ft_mandelbrot(t_env *env)
{
	int		x;
	int		y;
	double	n;
	double	i;

	env->x1 = -2.1;
	env->x2 = 0.6;
	env->y1 = -1.2;
	env->y2 = 1.2;
	i = env->it_max / 2;
	y = 0;
	while (y < W_Y)
	{
		x = 0;
		while (x < W_X)
		{
			env->cr = maptoreal(x, W_X, env->x1, env->x2);
			env->ci = maptoimaginary(y, W_Y, env->y1, env->y2);
			n = findmandelbrot(env);
			ft_get_color(env, n, env->it_max);
			ft_pixel(env, x, y);
			x++;
		}
		y++;
	}
}
