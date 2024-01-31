/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_functions_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:14:18 by youmoukh          #+#    #+#             */
/*   Updated: 2024/01/30 18:14:16 by youmoukh         ###   ########.fr       */
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
