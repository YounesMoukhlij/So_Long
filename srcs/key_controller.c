/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_controller.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younesmoukhlij <younesmoukhlij@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 01:11:22 by younesmoukh       #+#    #+#             */
/*   Updated: 2024/01/20 01:14:49 by younesmoukh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	key_hook(int key, t_solong *variable)
{
	int	x;

	if (key == SKEY_R || key == 124)
		to_right(&variable);
	else if (key == SKEY_L || key == 123)
		to_left(&variable);
	else if (key == SKEY_U || key == 126)
		to_up(&variable);
	else if (key == SKEY_D || key == 125)
		to_down(&variable);
	else if (key == SKEY_ESC)
	{
		ft_free_map(&variable)
		mlx_destroy_window(variable->mlx, variable->mlx_window);
		exit(1);
	}
	return (0);
}
