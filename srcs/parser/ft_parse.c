/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:35:47 by youmoukh          #+#    #+#             */
/*   Updated: 2024/01/29 20:36:36 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	check_extension(char *file)
{
	int	i;

	i = 0;
	while (file[i])
	{
		if (file[i] == '.' && file[i + 1] == 'b'
			&& file[i + 2] == 'e' && file[i + 3] == 'r' && file[i + 4] == '\0')
			return (1);
		i++;
	}
	return (0);
}

int	check_valid_members(t_solong *variable)
{
	int	i;
	int	j;

	i = 0;
	while (variable->map.map[i])
	{
		j = 0;
		while (variable->map.map[i][j])
		{
			if (!(variable->map.map[i][j] == '0'
				|| variable->map.map[i][j] == '1'
				|| variable->map.map[i][j] == 'C'
				|| variable->map.map[i][j] == 'E'
				|| variable->map.map[i][j] == 'P'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_parse(int ac, char *file, t_solong *variable)
{
	if (ac <= 1 || ac >= 3)
		error_msg();
	if (check_extension(file) == 0)
		error_msg();
	variable->map.map = read_map_from_file(file);
	fill_out_variables(variable);
	if (is_valid_rectangle(variable) || is_valid_walls(variable)
		|| is_valid_collectible(variable) || check_valid_path(variable)
		|| check_valid_members(variable))
		error_msg();
}
