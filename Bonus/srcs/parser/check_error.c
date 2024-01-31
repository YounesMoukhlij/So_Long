/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:29:19 by youmoukh          #+#    #+#             */
/*   Updated: 2024/01/31 17:51:07 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	is_valid_rectangle(t_solong *var)
{
	int	i;
	int	j;

	i = 0;
	while (var->map.map[i])
	{
		j = 0;
		while (i > j)
		{
			if (ft_strlen(var->map.map[i])
				!= ft_strlen(var->map.map[j]))
				return (1);
			j++;
		}
		i++;
	}
	if (var->win_heigth == var->win_length)
		return (1);
	return (0);
}

int	is_valid_walls(t_solong *var)
{
	int	i;
	int	heigth;
	int	heigth_1;

	heigth = calculate_heigth(var->map.map);
	heigth_1 = heigth;
	while (heigth--)
	{
		i = ft_strlen(var->map.map[heigth]) - 1;
		if (var->map.map[heigth][0] != '1'
			|| var->map.map[heigth][i] != '1')
			return (1);
	}
	i = 0;
	while (var->map.map[heigth_1 - 1][i])
		if (var->map.map[heigth_1 - 1][i++] != '1')
			return (1);
	i = 0;
	while (var->map.map[0][i])
		if (var->map.map[0][i++] != '1')
			return (1);
	return (0);
}

int	is_valid_collectible(t_solong *var)
{
	int			i;
	int			heigth;

	var->map.exit = 0;
	var->map.collectible = 0;
	var->map.player.player = 0;
	heigth = calculate_heigth(var->map.map);
	while (heigth--)
	{
		i = 0;
		while (var->map.map[heigth][i])
		{
			if (var->map.map[heigth][i] == 'P')
				var->map.player.player++;
			if (var->map.map[heigth][i] == 'E')
				var->map.exit++;
			if (var->map.map[heigth][i] == 'C')
				var->map.collectible++;
			i++;
		}
	}
	if (var->map.player.player == 0 || var->map.exit > 1 || var->map.exit == 0
		|| var->map.collectible == 0 || var->map.player.player > 1)
		return (1);
	return (0);
}
