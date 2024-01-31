/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younesmoukhlij <younesmoukhlij@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:17:19 by youmoukh          #+#    #+#             */
/*   Updated: 2024/01/31 21:54:00 by younesmoukh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_move(t_solong *var, int mode)
{
	if (mode == 0)
	{
		mlx_put_image_to_window(var->mlx, var->mlx_window, var->floor,
			(var->map.player.x) * SIZE, var->map.player.y * SIZE);
		mlx_put_image_to_window(var->mlx, var->mlx_window, var->floor,
			(var->map.player.x + 1) * SIZE, var->map.player.y * SIZE);
		mlx_put_image_to_window(var->mlx, var->mlx_window, var->player,
			(var->map.player.x + 1) * SIZE, var->map.player.y * SIZE);
		var->map.player.x++;
	}
	if (mode == 1)
	{
		mlx_put_image_to_window(var->mlx, var->mlx_window, var->floor,
			(var->map.player.x) * SIZE, var->map.player.y * SIZE);
		mlx_put_image_to_window(var->mlx, var->mlx_window, var->floor,
			(var->map.player.x - 1) * SIZE, var->map.player.y * SIZE);
		mlx_put_image_to_window(var->mlx, var->mlx_window, var->player,
			(var->map.player.x - 1) * SIZE, var->map.player.y * SIZE);
		var->map.player.x--;
	}
	if (var->map.collectible == 0)
		mlx_put_image_to_window(var->mlx, var->mlx_window, var->exit_opened,
			var->map.exit_x * SIZE, var->map.exit_y * SIZE);
	ft_move_helper(var, mode);
}

void	move_to_up(t_solong *var)
{
	if (var->map.map[var->map.player.y - 1][var->map.player.x] == '0')
	{
		ft_swap(&var->map.map[var->map.player.y - 1][var->map.player.x],
			&var->map.map[var->map.player.y][var->map.player.x]);
		ft_move(var, 3);
		write_moves_helper(var);
	}
	else if (var->map.map[var->map.player.y - 1][var->map.player.x] == 'C')
	{
		var->map.collectible--;
		var->map.map[var->map.player.y][var->map.player.x] = '0';
		var->map.map[var->map.player.y - 1][var->map.player.x] = 'P';
		ft_move(var, 3);
		write_moves_helper(var);
	}
	else if (var->map.map[var->map.player.y - 1][var->map.player.x] == 'E'
		&& !var->map.collectible)
	{
		write(1, "Congrats You Won :)\n", 20);
		ft_destroy(var, 0);
	}
}

void	move_to_down(t_solong *var)
{
	if (var->map.map[var->map.player.y + 1][var->map.player.x] == '0')
	{
		ft_swap(&var->map.map[var->map.player.y + 1][var->map.player.x],
			&var->map.map[var->map.player.y][var->map.player.x]);
		ft_move(var, 2);
		write_moves_helper(var);
	}
	else if (var->map.map[var->map.player.y + 1][var->map.player.x] == 'C')
	{
		var->map.collectible--;
		var->map.map[var->map.player.y][var->map.player.x] = '0';
		var->map.map[var->map.player.y + 1][var->map.player.x] = 'P';
		ft_move(var, 2);
		write_moves_helper(var);
	}
	else if (var->map.map[var->map.player.y + 1][var->map.player.x] == 'E'
		&& !var->map.collectible)
	{
		write(1, "Congrats You Won :)\n", 20);
		ft_destroy(var, 0);
	}
}

void	move_to_left(t_solong *var)
{
	if (var->map.map[var->map.player.y][var->map.player.x - 1] == '0')
	{
		ft_swap(&var->map.map[var->map.player.y][var->map.player.x - 1],
			&var->map.map[var->map.player.y][var->map.player.x]);
		ft_move(var, 1);
		write_moves_helper(var);
	}
	else if (var->map.map[var->map.player.y][var->map.player.x - 1] == 'C')
	{
		var->map.collectible--;
		var->map.map[var->map.player.y][var->map.player.x] = '0';
		var->map.map[var->map.player.y][var->map.player.x - 1] = 'P';
		ft_move(var, 1);
		write_moves_helper(var);
	}
	else if (var->map.map[var->map.player.y][var->map.player.x - 1] == 'E'
		&& !var->map.collectible)
	{
		write(1, "Congrats You Won :)\n", 20);
		ft_destroy(var, 0);
	}
}

void	move_to_right(t_solong *var)
{
	if (var->map.map[var->map.player.y][var->map.player.x + 1] == '0')
	{
		ft_swap(&var->map.map[var->map.player.y][var->map.player.x + 1],
			&var->map.map[var->map.player.y][var->map.player.x]);
		ft_move(var, 0);
		write_moves_helper(var);
	}
	else if (var->map.map[var->map.player.y][var->map.player.x + 1] == 'C')
	{
		var->map.collectible--;
		var->map.map[var->map.player.y][var->map.player.x] = '0';
		var->map.map[var->map.player.y][var->map.player.x + 1] = 'P';
		ft_move(var, 0);
		write_moves_helper(var);
	}
	else if (var->map.map[var->map.player.y][var->map.player.x + 1] == 'E'
		&& !var->map.collectible)
	{
		write(1, "Congrats You Won :)\n", 20);
		ft_destroy(var, 0);
	}
}
