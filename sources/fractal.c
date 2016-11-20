/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 16:33:56 by vcaquant          #+#    #+#             */
/*   Updated: 2016/11/18 15:53:06 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double	maptoreal(t_env *env, int x)
{
	double	range;

	range = ((4 * (float)x / W_X - 2) / env->zoom) + ((env->x / W_X));
	return (range);
}

double	maptoimaginary(t_env *env, int y)
{
	double	range;

	range = ((-4 * (float)y / W_Y + 2) / env->zoom) + ((env->y / W_Y));
	return (range);
}
