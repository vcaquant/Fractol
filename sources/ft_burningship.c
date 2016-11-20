/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_burningship.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 22:47:31 by vcaquant          #+#    #+#             */
/*   Updated: 2016/11/19 22:47:33 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

float	ft_fabs(float f)
{
	f = (f < 0 ? -f : f);
	return (f);
}

int		findburningship(t_env *env)
{
	double	tmp;
	int		i;

	i = 0;
	env->zr = 0 + env->var_zr;
	env->zi = 0 + env->var_zi;
	while (env->zr * env->zr * env->zi * env->zi <= 4 && i < env->it_max)
	{
		tmp = env->zr;
		env->zr = ft_fabs(tmp * tmp) - env->zi * env->zi + env->cr;
		env->zi = 2 * ft_fabs(tmp * env->zi) + env->ci;
		i++;
	}
	return (i);
}

void	ft_burningship(t_env *env)
{
	int		x;
	int		y;
	int		n;
	int		i;

	env->x1 = -2;
	env->x2 = 1.2;
	env->y1 = -2;
	env->y2 = 1;
	i = env->it_max / 2.5;
	y = 0;
	while (y < W_Y)
	{
		x = 0;
		while (x < W_X)
		{
			env->cr = maptoreal(env, x);
			env->ci = maptoimaginary(env, y);
			n = findburningship(env);
			ft_get_color(env, n, env->it_max);
			ft_pixel(env, x, y);
			x++;
		}
		y++;
	}
}