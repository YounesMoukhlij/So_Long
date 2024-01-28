/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_functions_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younesmoukhlij <younesmoukhlij@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 21:02:10 by younesmoukh       #+#    #+#             */
/*   Updated: 2024/01/28 19:08:47 by younesmoukh      ###   ########.fr       */
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

void	is_free_position_for_enemy(t_solong *variable)
{
	int	i;
	int	j;

	i = 0;
	while (variable->map.map[i])
	{
		j = 0;
		while (variable->map.map[i][j])
		{
			if (variable->map.map[i][j] == '0' && variable->map.map[i][j + 1] == '0' &&
				variable->map.map[i][j - 1] == '0')
				{
					variable->enemy.x = i;
					variable->enemy.y = j;
				}
			j++;
		}
		i++;
	}
}

void	is_free_position_for_spirite(t_solong *variable)
{
	int	i;
	int	j;

	i = 0;
	while (variable->map.map[i])
	{
		j = 0;
		while (variable->map.map[i][j])
		{
			if (variable->map.map[i][j] == '0' && variable->map.map[i][j + 1] == '0' &&
				variable->map.map[i][j - 1] == '0')
				{
					variable->spirite.x = i;
					variable->spirite.y = j;
				}
			j++;
		}
		i++;
	}
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

void	write_moves_helper(t_solong *var)
{
	var->move_count++;
	write(1, "Move : ", 7);
	ft_putnbr(var->move_count);
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
