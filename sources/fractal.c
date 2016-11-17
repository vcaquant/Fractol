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
			env->cr = 0.285;
			env->ci = 0.01;
			env->zr = x / env->zoom + env->x1;
			env->zi = y / env->zoom + env->y1;
			i = 0;
			while ((env->zr * env->zr + env->zi * env->zi) < 4 &&
					i < env->it_max)
			{
				tmp = env->zr;
				env->zr = env->zr * env->zr - env->zi * env->zi + env->cr;
				env->zi = 2 * env->zi * tmp + env->ci;
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

double  maptoreal(int x, int img_x, double minr, double maxr)
{
    double  range;

    range = maxr - minr;
    return (x * (range / img_x) + minr);
}

double  maptoimaginary(int y, int img_y, double mini, double maxi)
{
    double  range;

    range = maxi - mini;
    return (y * (range / img_y) + mini);
}

int     findmandelbrot(t_env *env)
{
    double	tmp;
    int		i;

    env->zr = 0;
    env->zi = 0;
    i = 0;
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
    int     n;

	env->x1 = -2.1;
	env->x2 = 0.6;
	env->y1 = -1.2;
	env->y2 = 1.2;
	env->it_max = 50;
	env->img_x = (env->x2 - env->x1) * env->zoom;
	env->img_y = (env->y2 - env->y1) * env->zoom;
	y = 0;
    while (y < env->img_y)
    {
        x = 0;
        while (x < env->img_x)
        {
            env->cr = maptoreal(x, env->img_x, env->x1, env->x2);
            env->ci = maptoimaginary(y, env->img_y, env->y1, env->y2);
            n = findmandelbrot(env);
            if (n == env->it_max)
                ft_pixel(env, x, y);
            x++;
        }
        y++;
    }
			/*env->cr = 1.5 * (x - env->img_x / 2) / (0.5 * env->zoom * env->img_x) + (env->x1 / env->img_x / 1.37) - 0.5;
			env->ci = (y - env->img_y / 2) / (0.5 * env->zoom * env->img_y) + (env->y1 / env->img_y / 1.92);
			env->zr = 0;
			env->zi = 0;
			i = 0;
			while ((env->zr * env->zr + env->zi * env->zi) < 4 &&
					i < env->it_max)
			{
				tmp = env->zr;
				env->zr = env->zr * env->zr - env->zi * env->zi + env->cr;
				env->zi = 2 * env->zi * tmp + env->ci;
				i++;
			}
			if (i == env->it_max)
				ft_pixel(env, x, y);
			else
				ft_pixel2(env, x, y);
			y++;
		}
		x++;
	}*/
}
