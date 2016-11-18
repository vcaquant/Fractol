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

int     findjulia(t_env *env)
{
    double	tmp;
    int		i;

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
    double  n;
    double  i;

	env->x1 = -2.1;
	env->x2 = 0.6;
	env->y1 = -1.2;
	env->y2 = 1.2;
    i = env->it_max / 2.5;
    env->it_sup = env->it_max - i;
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
            if (n == env->it_max && ft_chose_color(env) == 1)
            {
                env->r = 0;
                env->g = 0;
                env->b = 0;
                ft_pixel(env, x, y);
            }
            if (n < env->it_max && n > env->it_max - (i + 6))
            {
                //ft_chose_color(env);
                env->r = 192;
                env->g = 57;
                env->b = 43;
                ft_pixel(env, x, y);
            }
            if (n <= env->it_max - (i + 6) && n > env->it_max - (i + 10))
            {
                //ft_chose_color(env);
                env->r = 231;
                env->g = 76;
                env->b = 60;
                ft_pixel(env, x, y);
            }
            if (n <= env->it_max - (i + 10) && n > env->it_max - (i + 14))
            {
                //ft_chose_color(env);
                env->r = 211;
                env->g = 84;
                env->b = 0;
                ft_pixel(env, x, y);
            }
            if (n <= env->it_max - (i + 14) && n > env->it_max - (i + 18))
            {
                //ft_chose_color(env);
                env->r = 230;
                env->g = 126;
                env->b = 34;
                ft_pixel(env, x, y);
            }
            if (n <= env->it_max - (i + 18) && n > env->it_max - (i + 22))
            {
                //ft_chose_color(env);
                env->r = 243;
                env->g = 156;
                env->b = 18;
                ft_pixel(env, x, y);
            }
            if (n <= env->it_max - (i + 22) && n > env->it_max - env->it_max)
            {
                //ft_chose_color(env);
                env->r = 241;
                env->g = 196;
                env->b = 15;
                ft_pixel(env, x, y);
            }
            /*else if (n == env->it_max - i)// && ft_chose_color(env) == 1)
            {
                env->r = 255;
                env->g = 255;
                env->b = 255;
                ft_pixel(env, x, y);
            }
            else if (n == env->it_max - (i + 1.5))// && ft_chose_color(env) == 1)
            {
                env->r = 50;
                env->g = 50;
                env->b = 50;
                ft_pixel(env, x, y);
            }
            else if (n == env->it_max - (i + 3))// && ft_chose_color(env) == 1)
            {
                env->r = 100;
                env->g = 100;
                env->b = 100;
                ft_pixel(env, x, y);
            }
            else if (n == env->it_max - (i + 4.5))// && ft_chose_color(env) == 1)
            {
                env->r = 150;
                env->g = 150;
                env->b = 150;
                ft_pixel(env, x, y);
            }*/
            x++;
        }
        y++;
    }
}

void	ft_julia(t_env *env)
{
	int		x;
	int		y;
    int     n;

	env->x1 = -1;
	env->x2 = 1;
	env->y1 = -1.2;
	env->y2 = 1.2;
	env->img_x = (env->x2 - env->x1) * env->zoom;
	env->img_y = (env->y2 - env->y1) * env->zoom;
	y = 0;
    env->r = 255;
    env->g = 255;
    env->b = 255;
	while (y < env->img_y)
	{
		x = 0;
		while (x < env->img_x)
		{
			env->cr = 0.285;
			env->ci = 0.01;
            env->zr = maptoreal(x, env->img_x, env->x1, env->x2);
            env->zi = maptoimaginary(y, env->img_y, env->y1, env->y2);
            //env->cr = maptoreal(x, env->img_x, env->x1, env->x2);
            //env->ci = maptoimaginary(y, env->img_y, env->y1, env->y2);
            n = findjulia(env);
			if (n == env->it_max)
				ft_pixel(env, x, y);
			x++;
		}
		y++;
	}
}
