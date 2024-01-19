/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younesmoukhlij <younesmoukhlij@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:29:19 by youmoukh          #+#    #+#             */
/*   Updated: 2024/01/19 01:17:28 by younesmoukh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_rectangle(char **map)
{
	int	i;
	int	j;
	int	count_line;

	i = 0;
	count_line = 0;
	while (map[i])
	{
		j = 0;
		while (i > j)
		{
			if (ft_strlen(map[i]) != ft_strlen(map[j]))
				return (1);
			j++;
		}
		i++;
		count_line++;
	}
	if (count_line == ft_strlen(map[0]))
		return (1);
	return (0);
}

int	is_valid_walls(char **map)
{
	int	i;
	int	heigth;
	int	heigth_1;

	heigth = 0;
	while (map[heigth])
		heigth++;
	heigth_1 = heigth;
	while (heigth--)
	{
		i = ft_strlen(map[heigth]) - 1;
		if (map[heigth][0] != '1' || map[heigth][i] != '1')
			return (1);
	}
	i = 0;
	while (map[heigth_1 - 1][i])
		if (map[heigth_1 - 1][i++] != '1')
			return (1);
	i = 0;
	while (map[0][i])
		if (map[0][i++] != '1')
			return (1);
	return (0);
}

void	collect_collectibles(char **map)
{
	int			heigth;
	t_solong	s_map;
	int		i;

	s_map.map.exit = 0;
	s_map.map.player = 0;
	s_map.map.collectible = 0;
	heigth = 0;
	while (map[heigth])
		heigth++;
	while (heigth--)
	{
		i = 0;
		while (map[heigth][i])
		{
			if (map[heigth][i] == 'P')
				s_map.map.player++;
			if (map[heigth][i] == 'E')
				s_map.map.exit++;
			if (map[heigth][i] == 'C')
				s_map.map.collectible++;
			i++;
		}
	}
	printf("%d\n", s_map.map.collectible);
	printf("%d\n", s_map.map.player);
	printf("%d\n", s_map.map.exit);
}

int	is_valid_collectible(char **map)
{
	collect_collectibles(map);
	return (0);
}
