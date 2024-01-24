/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:29:19 by youmoukh          #+#    #+#             */
/*   Updated: 2024/01/24 20:17:41 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	is_valid_rectangle(t_solong *variable)
{
	int	i;
	int	j;

	i = 0;
	while (variable->map.map[i])
	{
		j = 0;
		while (i > j)
		{
			if (ft_strlen(variable->map.map[i]) != ft_strlen(variable->map.map[j]))
				return (1);
			j++;
		}
		i++;
	}
	if (calculate_heigth(variable->map.map) == calculate_length(variable->map.map))
		return (1);
	return (0);
}

int	is_valid_walls(t_solong *variable)
{
	int	i;
	int	heigth;
	int	heigth_1;

	heigth = calculate_heigth(variable->map.map);
	heigth_1 = heigth;
	while (heigth--)
	{
		i = ft_strlen(variable->map.map[heigth]) - 1;
		if (variable->map.map[heigth][0] != '1' || variable->map.map[heigth][i] != '1')
			return (1);
	}
	i = 0;
	while (variable->map.map[heigth_1 - 1][i])
		if (variable->map.map[heigth_1 - 1][i++] != '1')
			return (1);
	i = 0;
	while (variable->map.map[0][i])
		if (variable->map.map[0][i++] != '1')
			return (1);
	return (0);
}

int	is_valid_collectible(t_solong *variable)
{
	int			i;
	int			heigth;

	variable->map.exit = 0;
	variable->map.collectible = 0;
	variable->map.player.player = 0;
	heigth = calculate_heigth(variable->map.map);
	while (heigth--)
	{
		i = 0;
		while (variable->map.map[heigth][i])
		{
			if (variable->map.map[heigth][i] == 'P')
				variable->map.player.player++;
			if (variable->map.map[heigth][i] == 'E')
				variable->map.exit++;
			if (variable->map.map[heigth][i] == 'C')
				variable->map.collectible++;
			i++;
		}
	}
	if (variable->map.player.player == 0 || variable->map.exit > 1
		|| variable->map.exit == 0 || variable->map.collectible == 0
		|| variable->map.player.player > 1)
		return (1);
	return (0);
}
