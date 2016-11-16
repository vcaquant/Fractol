/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 17:43:32 by vcaquant          #+#    #+#             */
/*   Updated: 2016/11/15 17:43:36 by vcaquant         ###   ########.fr       */
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
	return (1);
}

void 	Mandelbrot(t_env *env)
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
			while ((env->z_r * env->z_r + env->z_i * env->z_i) < 4 && i < env->it_max)
			{
				tmp = env->z_r;
				env->z_r = env->z_r * env->z_r - env->z_i * env->z_i + env->c_r;
				env->z_i = 2 * env->z_i * tmp + env->c_i;
				i++;
			}
			if (i == env->it_max)
				mlx_pixel_put(env->mlx, env->win, x, y, WHI);
			y++;
		}
		x++;
	}
}

int     main(void)
{
    t_env   *env;

    if (!ft_init_struct(&env))
		return (-1);
    env->mlx = mlx_init();
    env->win = mlx_new_window(env->mlx, W_X, W_Y, "Fract_ol");
	env->img->ptr_img = mlx_new_image(env->mlx, W_X, W_Y);
	env->img->bits_img = mlx_get_data_addr(env->img->ptr_img, &(env->img->bpp),
			&(env->img->size_line), &(env->img->end));
	Mandelbrot(env);
    mlx_hook(env->win, 2, 0, aff_key, env);
	mlx_loop(env->mlx);
	return (0);
}
