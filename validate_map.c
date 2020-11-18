/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 11:26:02 by fgata-va          #+#    #+#             */
/*   Updated: 2020/11/16 12:22:20 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_check_player(char **map)
{
	int		i;
	int		j;
	int		fnd;

	fnd = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr("NSWE", map[i][j]))
			{
				if (fnd == 1)
					return (0);
				fnd = 1;
			}
			j++;
		}
		i++;
	}
	if (fnd == 0)
		return (0);
	return (1);
}

void			ft_player_pos(char **map, int *x, int *y)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr("NSWE", map[i][j]))
			{
				*x = j;
				*y = i;
			}
			j++;
		}
		i++;
	}
}

int		ft_check_elements(t_map *data)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	map = data->map_matrix;
	while(map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!(ft_strchr("012NSWE ", map[i][j])))
				return (0);
			j++;
		}
		i++;
	}
	if (ft_check_player(map))
		return (0);
	return (1);
}


int		map_validator(char **map, int x, int y, t_map *data)
{
	int	valid;

	valid = 1;
	if (map[y][x] != 1 && map[y][x] != 3 && valid == 1)
	{
		if (x == (int)ft_strlen(map[y]) || y == data->max_y || x == 0 || y == 0)
			return (0);
		map[y][x] = 3;
		valid = map_validator(map, x + 1, y, data);
		if (x < (int)ft_strlen(map[y - 1]))
			valid = map_validator(map, x, y - 1, data);
		valid = map_validator(map, x - 1, y, data);
		if (x < (int)ft_strlen(map[y + 1]))
			valid = map_validator(map, x, y + 1, data);
	}
	return (valid);
}

int		ft_valid_map(t_map *data)
{
	int	valid;
	char **map_cpy;

	map_cpy = (char **)ft_matrix_cpy(data->map_matrix, data->max_y);
	valid = ft_check_elements(data);
	if (valid)
	{
		ft_player_pos(data->map_matrix, &(data->player_x), &(data->player_y));
		valid = map_validator(map_cpy, data->player_x, data->player_y, data);
	}
	ft_free_matrix((void **)map_cpy, data->max_y);
	return (valid);
}
