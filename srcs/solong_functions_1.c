/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_functions_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younesmoukhlij <younesmoukhlij@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 21:02:10 by younesmoukh       #+#    #+#             */
/*   Updated: 2024/01/19 21:05:10 by younesmoukh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	position_player(t_solong *variable, char flag)
{
	int	i;
	int	j;

	i = 0;
	while (variable->map.map[i])
	{
		j = 0;
		while (variable->map.map[i][j])
		{
			if (variable->map.map[i][j] == 'P' && flag == 'y')
				return (j);
			else if (variable->map.map[i][j] == 'P' && flag == 'x')
				return (i);
			j++;
		}
		i++;
	}
	return (0);
}