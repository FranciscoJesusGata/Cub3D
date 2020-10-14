/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 10:13:53 by fgata-va          #+#    #+#             */
/*   Updated: 2020/10/14 12:18:45 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "lib/mlx/mlx.h"
# include "lib/GNL/get_next_line.h"
# include "lib/libftprintf/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>

typedef struct	s_map{
	int		resolution[2];
	char	**map_matrix;
	char	*n_texture;
	char	*s_texture;
	char	*w_texture;
	char	*e_texture;
	int		floor[3];
	void	*mlx_ptr;
	void	*window;
}				t_map;

int				cub3d(char *path, int save);
int				ft_check_resol(char *line ,t_map *map);
void			ft_error(const char *msg);
int				ft_check_texture(char *line, t_map *map);

#endif
