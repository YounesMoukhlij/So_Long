/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:35:47 by youmoukh          #+#    #+#             */
/*   Updated: 2024/01/18 18:55:43 by youmoukh         ###   ########.fr       */
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
	char	**map;
	// char	*tmp_map;

	if (ac <= 1 || ac >= 3)
		error_msg();
	if (check_extension(file) == 0)
		error_msg();
	map = read_map_from_file(file);
	// if (is_rectangle(map) || is_player(map) || is_walls() || is_collectible())
	if (is_rectangle(map))
		error_msg();
	ft_free(map);
	return (1);
}
