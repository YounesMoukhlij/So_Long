/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younesmoukhlij <younesmoukhlij@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:35:47 by youmoukh          #+#    #+#             */
/*   Updated: 2024/01/19 01:18:28 by younesmoukh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	ft_parse(int ac, char *file)
{
	t_solong variable;

	if (ac <= 1 || ac >= 3)
		error_msg();
	if (check_extension(file) == 0)
		error_msg();
	variable.map.map  = read_map_from_file(file);
	printf("ft_parse func >>>>>> [%s] √\n\n", variable.map.map[1]);
	if (is_valid_rectangle(variable.map.map) || is_valid_walls(variable.map.map) || is_valid_collectible(variable.map.map))
		error_msg();

	printf("%d\n", (variable.map.player));
	// printf("%d\n", a.collectible);
	// ft_free(map);
	return (1);
}
