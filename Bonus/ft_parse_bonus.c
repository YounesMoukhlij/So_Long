/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:35:47 by youmoukh          #+#    #+#             */
/*   Updated: 2024/02/01 16:43:32 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

int	check_space_for_enemy(t_solong *var)
{
	int	i;
	int	j;

	i = 0;
	while (var->map.map[i])
	{
		j = 0;
		while (var->map.map[i][j])
		{
			if (var->map.map[i][j] == '0')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_parse(int ac, char *file, t_solong *var)
{
	if (ac <= 1 || ac >= 3)
		error_message(var, 6);
	if (check_extension(file) == 0)
		error_message(var, 5);
	var->map.map = read_map_from_file(file);
	if (!var->map.map)
		error_message(var, 20);
	fill_out_variables(var);
	if (check_valid_members(var))
		error_message(var, 4);
	if (is_valid_rectangle(var))
		error_message(var, 0);
	if (check_space_for_enemy(var))
		error_message(var, 100);
	if (is_valid_walls(var))
		error_message(var, 1);
	if (is_valid_collectible(var))
		error_message(var, 2);
	if (check_valid_path_door(var))
		error_message(var, 3);
	if (check_valid_path(var))
		error_message(var, 3);
}
