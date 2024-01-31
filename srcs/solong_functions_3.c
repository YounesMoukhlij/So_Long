/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_functions_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:21:45 by youmoukh          #+#    #+#             */
/*   Updated: 2024/01/31 19:43:43 by youmoukh         ###   ########.fr       */
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
}

int	exit_game(void *program)
{
	t_solong	*variable;

	variable = (t_solong *)program;
	ft_destroy(variable, 0);
	return (0);
}
