/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_functions_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 21:02:10 by younesmoukh       #+#    #+#             */
/*   Updated: 2024/01/26 15:02:26 by youmoukh         ###   ########.fr       */
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

void	ft_free_map(t_solong **variable)
{
	int	i;

	i = 0;
	while ((*variable)->map.map[i])
	{
		free((*variable)->map.map[i]);
		i++;
	}
	free((*variable)->map.map);
}

void	write_moves_helper(t_solong *variable)
{
	write(1, "Move : ", 7);
	ft_putnbr(variable->move_count);
	variable->move_count++;
	write(1, "\n", 1);
}

void	ft_putnbr(int nbr)
{
	long	n;
	int		c;

	n = nbr;
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	if (n < 10)
	{
		c = n + 48;
		write(1, &c, 1);
	}
}
