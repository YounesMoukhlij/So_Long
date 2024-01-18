/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:29:19 by youmoukh          #+#    #+#             */
/*   Updated: 2024/01/18 19:01:47 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_rectangle(char **map)
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
	printf("count [%d] \n", count_line);
	return (0);
}
