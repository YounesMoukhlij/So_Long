/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path_door_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:52:13 by youmoukh          #+#    #+#             */
/*   Updated: 2024/02/01 16:29:47 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	flood_fill_1(t_solong *var, char **map, int y, int x)
{
	if (x < 0 || y < 0 || x >= var->win_heigth || map[x][y] == 'E'
		|| y >= var->win_length || map[x][y] == 'Y' || map[x][y] == '1')
		return ;
	map[x][y] = 'Y';
	flood_fill_1(var, map, y + 1, x);
	flood_fill_1(var, map, y - 1, x);
	flood_fill_1(var, map, y, x + 1);
	flood_fill_1(var, map, y, x - 1);
}

char	**create_map_copy_1(char **map, int x, int y)
{
	int		i;
	int		j;
	char	**map_copy;

	i = 0;
	map_copy = malloc(sizeof(char *) * y + 1);
	if (!map_copy)
		return (NULL);
	while (i < y)
	{
		j = 0;
		map_copy[i] = malloc(sizeof(char) * x + 1);
		if (!map_copy[i])
			return (NULL);
		while (j < x)
		{
			map_copy[i][j] = map[i][j];
			j++;
		}
		map_copy[i][j] = '\0';
		i++;
	}
	map_copy[i] = 0;
	return (map_copy);
}

int	now_just_check_1(char **map_copy)
{
	int	i;
	int	j;

	i = 0;
	while (map_copy[i])
	{
		j = 0;
		while (map_copy[i][j])
		{
			if ((map_copy[i][j] == 'C'
				|| map_copy[i][j] == 'P'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_valid_path_door(t_solong *var)
{
	char	**map_copy;

	map_copy = create_map_copy_1(var->map.map,
			var->win_length, var->win_heigth);
	flood_fill_1(var, map_copy, var->map.player.x, var->map.player.y);
	if (now_just_check_1(map_copy))
		return (ft_free(map_copy), 1);
	return (ft_free(map_copy), 0);
}
