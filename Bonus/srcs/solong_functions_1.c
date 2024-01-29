/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_functions_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younesmoukhlij <younesmoukhlij@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:13:57 by youmoukh          #+#    #+#             */
/*   Updated: 2024/01/30 00:37:28 by younesmoukh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	position_player(t_solong *variable)
{
	int	i;
	int	j;

	i = 0;
	while (variable->map.map[i])
	{
		j = 0;
		while (variable->map.map[i][j])
		{
			if (variable->map.map[i][j] == 'P')
			{
				variable->map.player.y = i;
				variable->map.player.x = j;
			}
			j++;
		}
		i++;
	}
}

void	position_enemy(t_solong *var)
{
	int	i;
	int	j;

	i = 0;
	while (var->map.map[i])
	{
		j = 0;
		while (var->map.map[i][j])
		{
			if (var->map.map[i][j] == '0' && var->map.map[i][j + 1] == '0')
			{
				var->enemy.y = i;
				var->enemy.x = j;
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
