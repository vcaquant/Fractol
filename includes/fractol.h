/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 16:49:27 by vcaquant          #+#    #+#             */
/*   Updated: 2016/11/15 15:57:13 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define BLACK		0x000000
# define WHI		0xFFFFFF
# define AZUR		0x74D0F1
# define AZUR_F		0x1E7FCB
# define ABSINTHE	0x7FDD4C
# define RED		0x00FF0000
# define BRO		0x00996600
# define G_P		0x0099FF00
# define G_F		0x0000CC00
# define Y_P		0x00CCCC66

# include "../libft/libft.h"
# include "../libft/get_next_line.h"

# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/uio.h>
# include <sys/types.h>

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	void	*s_win;
	int		**tab;
	int		ret;
	int		fd;
}				t_env;

int				ft_init_struct(t_env **env, char **av);

int				ft_error(int ac);

#endif
