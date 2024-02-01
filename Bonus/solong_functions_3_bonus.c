/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_functions_3_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:21:45 by youmoukh          #+#    #+#             */
/*   Updated: 2024/02/01 13:25:02 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_swap(char *a, char *b)
{
	char	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_move_helper(t_solong *var, int mode)
{
	if (mode == 2)
	{
		mlx_put_image_to_window(var->mlx, var->mlx_window, var->floor,
			(var->map.player.x) * SIZE, (var->map.player.y) * SIZE);
		mlx_put_image_to_window(var->mlx, var->mlx_window, var->floor,
			(var->map.player.x) * SIZE, (var->map.player.y + 1) * SIZE);
		mlx_put_image_to_window(var->mlx, var->mlx_window, var->player,
			(var->map.player.x) * SIZE, (var->map.player.y + 1) * SIZE);
		var->map.player.y++;
	}
	if (mode == 3)
	{
		mlx_put_image_to_window(var->mlx, var->mlx_window, var->floor,
			var->map.player.x * SIZE, (var->map.player.y) * SIZE);
		mlx_put_image_to_window(var->mlx, var->mlx_window, var->floor,
			var->map.player.x * SIZE, (var->map.player.y - 1) * SIZE);
		mlx_put_image_to_window(var->mlx, var->mlx_window, var->player,
			var->map.player.x * SIZE, (var->map.player.y - 1) * SIZE);
		var->map.player.y--;
	}
	if (var->map.collectible == 0)
		mlx_put_image_to_window(var->mlx, var->mlx_window, var->exit_opened,
			var->map.exit_x * SIZE, var->map.exit_y * SIZE);
}
