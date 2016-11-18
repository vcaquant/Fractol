/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 16:38:23 by vcaquant          #+#    #+#             */
/*   Updated: 2016/11/18 12:51:15 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		ft_chose_color(t_env *env)
{
	if (env->r == 255)
	{
		env->r = 0;
		env->g = 0;
		env->b = 255;
	}
	else if (env->g == 255)
	{
		env->r = 255;
		env->g = 0;
		env->b = 0;
	}
	else if (env->b == 255)
	{
		env->r = 0;
		env->g = 255;
		env->b = 0;
	}
	return (1);
}

void	ft_pixel(t_env *env, int x, int y)
{
	if (x > 0 && x < W_X && y > 0 && y < W_Y)
	{
		env->img->bits_img[(4 * (x + env->img->size_line / 4 * y))] = env->b;
		env->img->bits_img[(4 * (x + env->img->size_line / 4 * y)) + 1] = env->g;
		env->img->bits_img[(4 * (x + env->img->size_line / 4 * y)) + 2] = env->r;
	}
}
