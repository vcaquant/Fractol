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

int		ft_init_struct(t_env **env, char **av)
{
	int		i;
	char	*str;

	i = 0;
	str = av[1];
	if (!(*env = (t_env*)malloc(sizeof(t_env))))
		return (0);
	(*env)->s_win = NULL;
	return (1);
}

int     main(int ac, char **av)
{
    t_env   *env;

    
}
