/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:17:19 by youmoukh          #+#    #+#             */
/*   Updated: 2024/01/29 18:18:11 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_swap(char *a, char *b)
{
	char	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	move_to_up(t_solong *var)
{
	if (var->map.map[var->map.player.y - 1][var->map.player.x] == '0')
	{
		ft_swap(&var->map.map[var->map.player.y - 1][var->map.player.x],
			&var->map.map[var->map.player.y][var->map.player.x]);
		var->map.player.y--;
		write_moves_helper(var);
	}
	else if (var->map.map[var->map.player.y - 1][var->map.player.x] == 'C')
	{
		var->map.collectible--;
		var->map.map[var->map.player.y][var->map.player.x] = '0';
		var->map.map[var->map.player.y - 1][var->map.player.x] = 'P';
		var->map.player.y--;
		write_moves_helper(var);
	}
	else if (var->map.map[var->map.player.y - 1][var->map.player.x] == 'E'
		&& !var->map.collectible)
	{
		write(1, "Bravo\n", 6);
		ft_destroy(var, 0);
	}
}

void	move_to_down(t_solong *var)
{
	if (var->map.map[var->map.player.y + 1][var->map.player.x] == '0')
	{
		ft_swap(&var->map.map[var->map.player.y + 1][var->map.player.x],
			&var->map.map[var->map.player.y][var->map.player.x]);
		var->map.player.y++;
		write_moves_helper(var);
	}
	else if (var->map.map[var->map.player.y + 1][var->map.player.x] == 'C')
	{
		var->map.collectible--;
		var->map.map[var->map.player.y][var->map.player.x] = '0';
		var->map.map[var->map.player.y + 1][var->map.player.x] = 'P';
		var->map.player.y++;
		write_moves_helper(var);
	}
	else if (var->map.map[var->map.player.y + 1][var->map.player.x] == 'E'
		&& !var->map.collectible)
	{
		write(1, "Bravo\n", 6);
		ft_destroy(var, 0);
	}
}

void	move_to_left(t_solong *var)
{
	if (var->map.map[var->map.player.y][var->map.player.x - 1] == '0')
	{
		ft_swap(&var->map.map[var->map.player.y][var->map.player.x - 1],
			&var->map.map[var->map.player.y][var->map.player.x]);
		var->map.player.x--;
		write_moves_helper(var);
	}
	else if (var->map.map[var->map.player.y][var->map.player.x - 1] == 'C')
	{
		var->map.collectible--;
		var->map.map[var->map.player.y][var->map.player.x] = '0';
		var->map.map[var->map.player.y][var->map.player.x - 1] = 'P';
		var->map.player.x--;
		write_moves_helper(var);
	}
	else if (var->map.map[var->map.player.y][var->map.player.x - 1] == 'E'
		&& !var->map.collectible)
	{
		write(1, "Bravo\n", 6);
		ft_destroy(var, 0);
	}
}

void	move_to_right(t_solong *var)
{
	if (var->map.map[var->map.player.y][var->map.player.x + 1] == '0')
	{
		ft_swap(&var->map.map[var->map.player.y][var->map.player.x + 1],
			&var->map.map[var->map.player.y][var->map.player.x]);
		var->map.player.x++;
		write_moves_helper(var);
	}
	else if (var->map.map[var->map.player.y][var->map.player.x + 1] == 'C')
	{
		var->map.collectible--;
		var->map.map[var->map.player.y][var->map.player.x] = '0';
		var->map.map[var->map.player.y][var->map.player.x + 1] = 'P';
		var->map.player.x++;
		write_moves_helper(var);
	}
	else if (var->map.map[var->map.player.y][var->map.player.x + 1] == 'E'
		&& !var->map.collectible)
	{
		write(1, "Congrats You Won :)\n", 20);
		ft_destroy(var, 0);
	}
}
