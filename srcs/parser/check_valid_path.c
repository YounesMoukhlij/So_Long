/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:55:35 by youmoukh          #+#    #+#             */
/*   Updated: 2024/01/26 18:15:28 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	flood_fill(char **map, int x, int y)
{
	t_solong	variable;

	if (y < 0 || x < 0 || x >= variable.win_heigth || map[x][y] == 'E' || map[x][y] == '1'
		|| y >= variable.win_length || map[x][y] == 'T')
		return ;
	map[x][y] = 'T';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

int	check_valid_path(t_solong *var)
{
	int		i;
	int		j;

	i = 0;
	flood_fill(var->map.map, 48, 8);
	while (var->map.map[i])
	{
		j = 0;
		while (var->map.map[i][j])
		{
			if ((var->map.map[i][j] == 'C' || var->map.map[i][j] == 'E')
				&& var->map.map[i + 1][j] == 'T' && var->map.map[i - 1][j] == 'T'
				&& var->map.map[i][j - 1] == 'T'  && var->map.map[i][j + 1] == 'T')
				return (1);
			j++;
		}
		i++;
	}
	i = 0;
	while (var->map.map[i])
	{
		printf("%s\n", var->map.map[i]);
		i++;
	}
	return (0);
}
