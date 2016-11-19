/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_variation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 18:04:09 by vcaquant          #+#    #+#             */
/*   Updated: 2016/11/19 18:04:11 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	var_it(t_env *env, int keycode)
{
	if (env->menu == 1)
	{
		if (keycode == 24)
			env->it_max += 2.5;
		else if (keycode == 27)
			env->it_max -= 2.5;
	}
	else if (env->menu == 2)
	{
		if (keycode == 24)
			env->it_max += 2;
		else if (keycode == 27)
			env->it_max -= 2;
	}
	else
	{
		if (keycode == 24)
			env->it_max += 2;
		else if (keycode == 27)
			env->it_max -= 2;
	}
	draw_frct(env);
}

void	var_c(t_env *env, int key)
{
	if (key == 17)
	{
		env->cr += 0.1;
		draw_frct(env);
	}
	if (key == 5)
	{
		env->cr -= 0.1;
		draw_frct(env);
	}
	if (key == 3)
	{
		env->ci += 0.1;
		draw_frct(env);
	}
	if (key == 38)
	{
		env->ci -= 0.1;
		draw_frct(env);
	}
}

void	var_z(t_env *env, int key)
{
	if (key == 17)
	{
		env->var_zr += 0.1;
		draw_frct(env);
	}
	if (key == 5)
	{
		env->var_zr -= 0.1;
		draw_frct(env);
	}
	if (key == 3)
	{
		env->var_zi += 0.1;
		draw_frct(env);
	}
	if (key == 38)
	{
		env->var_zi -= 0.1;
		draw_frct(env);
	}
}
