/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_functions_0.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:46:05 by youmoukh          #+#    #+#             */
/*   Updated: 2024/01/31 17:49:02 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	position_exit(t_solong *variable)
{
	int	i;
	int	j;

	i = 0;
	while (variable->map.map[i])
	{
		j = 0;
		while (variable->map.map[i][j])
		{
			if (variable->map.map[i][j] == 'E')
			{
				variable->map.exit_y = i;
				variable->map.exit_x = j;
			}
			j++;
		}
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (1);
	}
	return (0);
}

char	*ft_strdup(char *s1)
{
	int		len;
	int		i;
	char	*r;

	i = 0;
	len = ft_strlen(s1);
	r = malloc(sizeof(char) * (len + 1));
	if (!r)
		return (0);
	while (s1[i])
	{
		r[i] = s1[i];
		i++;
	}
	r[i] = '\0';
	return (r);
}

int	calculate_heigth(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	calculate_length(char **map)
{
	int		i;

	i = 0;
	while (map[0][i])
		i++;
	return (i);
}
