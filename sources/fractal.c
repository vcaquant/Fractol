/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 16:33:56 by vcaquant          #+#    #+#             */
/*   Updated: 2016/11/17 17:10:27 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_julia(t_env *env)
{
	int		x;
	int		y;
	int		i;
	double	tmp;

	env->x1 = -1;
	env->x2 = 1;
	env->y1 = -1.2;
	env->y2 = 1.2;
	env->zoom = 100;
	env->it_max = 150;
	env->img_x = (env->x2 - env->x1) * env->zoom;
	env->img_y = (env->y2 - env->y1) * env->zoom;
	x = 0;
	while (x < env->img_x)
	{
		y = 0;
		while (y < env->img_y)
		{
			env->c_r = 0.285;
			env->c_i = 0.01;
			env->z_r = x / env->zoom + env->x1;
			env->z_i = y / env->zoom + env->y1;
			i = 0;
			while ((env->z_r * env->z_r + env->z_i * env->z_i) < 4 &&
					i < env->it_max)
			{
				tmp = env->z_r;
				env->z_r = env->z_r * env->z_r - env->z_i * env->z_i + env->c_r;
				env->z_i = 2 * env->z_i * tmp + env->c_i;
				i++;
			}
			if (i == env->it_max)
				ft_pixel(env, x, y);
			else
				ft_pixel2(env, x, y);
			y++;
		}
		x++;
	}
}

void	ft_mandelbrot(t_env *env)
{
	int		x;
	int		y;
	int		i;
	double	tmp;

	env->x1 = -2.1;
	env->x2 = 0.6;
	env->y1 = -1.2;
	env->y2 = 1.2;
	env->zoom = 100;
	env->it_max = 50;
	env->img_x = (env->x2 - env->x1) * env->zoom;
	env->img_y = (env->y2 - env->y1) * env->zoom;
	x = 0;
	while (x < env->img_x)
	{
		y = 0;
		while (y < env->img_y)
		{
			env->c_r = x / env->zoom + env->x1;
			env->c_i = y / env->zoom + env->y1;
			env->z_r = 0;
			env->z_i = 0;
			i = 0;
			while ((env->z_r * env->z_r + env->z_i * env->z_i) < 4 &&
					i < env->it_max)
			{
				tmp = env->z_r;
				env->z_r = env->z_r * env->z_r - env->z_i * env->z_i + env->c_r;
				env->z_i = 2 * env->z_i * tmp + env->c_i;
				i++;
			}
			if (i == env->it_max)
				ft_pixel(env, x, y);
			else
				ft_pixel2(env, x, y);
			y++;
		}
		x++;
	}
}
