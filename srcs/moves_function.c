/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younesmoukhlij <younesmoukhlij@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:17:19 by youmoukh          #+#    #+#             */
/*   Updated: 2024/01/28 21:42:14 by younesmoukh      ###   ########.fr       */
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
	if (var->map.map[var->map.player.x - 1][var->map.player.y] == '0')
	{
		ft_swap(&var->map.map[var->map.player.x - 1][var->map.player.y],
			&var->map.map[var->map.player.x][var->map.player.y]);
		var->map.player.x--;
		write_moves_helper(var);
	}
	else if (var->map.map[var->map.player.x - 1][var->map.player.y] == 'C')
	{
		var->map.collectible--;
		var->map.map[var->map.player.x][var->map.player.y] = '0';
		var->map.map[var->map.player.x - 1][var->map.player.y] = 'P';
		var->map.player.x--;
		write_moves_helper(var);
	}
	else if (var->map.map[var->map.player.x - 1][var->map.player.y] == 'E'
		&& !var->map.collectible)
	{
		ft_free_map(&var);
		mlx_destroy_window(var->mlx, var->mlx_window);
		write(1, "Bravo\n", 6);
		exit(0);
	}
}

void	move_to_down(t_solong *var)
{
	if (var->map.map[var->map.player.x + 1][var->map.player.y] == '0')
	{
		ft_swap(&var->map.map[var->map.player.x + 1][var->map.player.y],
			&var->map.map[var->map.player.x][var->map.player.y]);
		var->map.player.x++;
		write_moves_helper(var);
	}
	else if (var->map.map[var->map.player.x + 1][var->map.player.y] == 'C')
	{
		var->map.collectible--;
		var->map.map[var->map.player.x][var->map.player.y] = '0';
		var->map.map[var->map.player.x + 1][var->map.player.y] = 'P';
		var->map.player.x++;
		write_moves_helper(var);
	}
	else if (var->map.map[var->map.player.x + 1][var->map.player.y] == 'E'
		&& !var->map.collectible)
	{
		ft_free_map(&var);
		mlx_destroy_window(var->mlx, var->mlx_window);
		write(1, "YOU WIN\n", 8);
		exit(0);
	}
}

void	move_to_left(t_solong *var)
{
	if (var->map.map[var->map.player.x][var->map.player.y - 1] == '0')
	{
		ft_swap(&var->map.map[var->map.player.x][var->map.player.y - 1],
			&var->map.map[var->map.player.x][var->map.player.y]);
		var->map.player.y--;
		write_moves_helper(var);
	}
	else if (var->map.map[var->map.player.x][var->map.player.y - 1] == 'C')
	{
		var->map.collectible--;
		var->map.map[var->map.player.x][var->map.player.y] = '0';
		var->map.map[var->map.player.x][var->map.player.y - 1] = 'P';
		var->map.player.y--;
		write_moves_helper(var);
	}
	else if (var->map.map[var->map.player.x][var->map.player.y - 1] == 'E'
		&& !var->map.collectible)
	{
		ft_free_map(&var);
		mlx_destroy_window(var->mlx, var->mlx_window);
		write(1, "YOU WIN\n", 8);
		exit(0);
	}
}

void	move_to_right(t_solong *var)
{
	if (var->map.map[var->map.player.x][var->map.player.y + 1] == '0')
	{
		ft_swap(&var->map.map[var->map.player.x][var->map.player.y + 1],
			&var->map.map[var->map.player.x][var->map.player.y]);
		var->map.player.y++;
		write_moves_helper(var);
	}
	else if (var->map.map[var->map.player.x][var->map.player.y + 1] == 'C')
	{
		var->map.collectible--;
		var->map.map[var->map.player.x][var->map.player.y] = '0';
		var->map.map[var->map.player.x][var->map.player.y + 1] = 'P';
		var->map.player.y++;
		write_moves_helper(var);
	}
	else if (var->map.map[var->map.player.x][var->map.player.y + 1] == 'E'
		&& !var->map.collectible)
	{
		ft_free_map(&var);
		mlx_destroy_window(var->mlx, var->mlx_window);
		write(1, "YOU WIN\n", 8);
		exit(0);
	}
}
