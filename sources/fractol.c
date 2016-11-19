/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 17:43:32 by vcaquant          #+#    #+#             */
/*   Updated: 2016/11/17 17:08:18 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		ft_init_struct(t_env **env)
{
	if (!(*env = (t_env*)malloc(sizeof(t_env))))
		return (0);
	(*env)->s_win = NULL;
	if (!((*env)->img = (t_img*)malloc(sizeof(t_img))))
		return (0);
	(*env)->zoom = 250;
	(*env)->it_max = 50;
	(*env)->rand = 5;
	(*env)->red = 50;
	(*env)->green = 50;
	(*env)->blue = 50;
	(*env)->modul_r = 255;
	(*env)->modul_g = 255;
	(*env)->modul_b = 255;
	return (1);
}

int 	mouse_move(int x, int y, t_env *env)
{
	if (env->move == 1)
	{
		if (env->menu == 1)
		{
			x -= W_X / 2;
			y -= W_Y / 2;
			env->cr = ((float)x / W_X) * 2;
			env->ci = ((float)y / W_Y) * 2;
		}
		else if (env->menu == 2)
		{
			x -= W_X / 2;
			y -= W_Y / 2;
			env->var_zr = ((float)x / W_X) * 2;
			env->var_zi = ((float)y / W_Y) * 2;
		}
		draw_frct(env);
	}
	return (0);
}

void	prp_win(t_env *env)
{
	env->win = mlx_new_window(env->mlx, W_X, W_Y, "Fract_ol");
	env->img = malloc(sizeof(t_img));
	env->img->ptr_img = mlx_new_image(env->mlx, 800, 650);
	env->img->bts_img = mlx_get_data_addr(env->img->ptr_img, &(env->img->bpp),
			&(env->img->size_line), &(env->img->end));
	env->cr = 0.285;
	env->ci = 0.01;
	mlx_hook(env->win, 2, 0, aff_key, env);
	mlx_hook(env->win, 6, (1L << 6), mouse_move, env);
}

void	draw_frct(t_env *env)
{
	mlx_destroy_image(env->mlx, env->img->ptr_img);
	env->img = malloc(sizeof(t_img));
	env->img->ptr_img = mlx_new_image(env->mlx, 800, 650);
	env->img->bts_img = mlx_get_data_addr(env->img->ptr_img, &(env->img->bpp),
			&(env->img->size_line), &(env->img->end));
	if (env->menu == 1)
		ft_julia(env);
	else if (env->menu == 2)
		ft_mandelbrot(env);
	else
		ft_newton(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img->ptr_img, 0, 0);
}

int		main(void)
{
	t_env	*env;

	if (!ft_init_struct(&env))
		return (-1);
	env->menu = 0;
	env->mlx = mlx_init();
	env->win_b = mlx_new_window(env->mlx, W_X, W_Y, "MENU");
	mlx_hook(env->win_b, 2, 0, key_menu, env);
	mlx_loop(env->mlx);
	return (0);
}
