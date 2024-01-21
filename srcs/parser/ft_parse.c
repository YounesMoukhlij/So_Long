/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younesmoukhlij <younesmoukhlij@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:35:47 by youmoukh          #+#    #+#             */
/*   Updated: 2024/01/20 21:46:37 by younesmoukh      ###   ########.fr       */
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

void	ft_parse(int ac, char *file, t_solong *variable)
{
	if (ac <= 1 || ac >= 3)
		error_msg();
	if (check_extension(file) == 0)
		error_msg();
	variable->map.map  = read_map_from_file(file);
	if (is_valid_rectangle(variable) || is_valid_walls(variable)
		|| is_valid_collectible(variable))
		error_msg();
}
