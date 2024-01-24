/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_controller.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 01:11:22 by younesmoukh       #+#    #+#             */
/*   Updated: 2024/01/24 20:17:59 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	key_hook_function(int key, t_solong *variable)
{
	// if (key == SKEY_R || key == 124)
	// 	to_right(&variable);
	// else if (key == SKEY_L || key == 123)
	// 	to_left(&variable);
	// else if (key == SKEY_U || key == 126)
	// 	to_up(&variable);
	// else if (key == SKEY_D || key == 125)
	// 	to_down(&variable);
	if (key == SKEY_ESC)
	{
		// ft_free_map(&variable)
		mlx_destroy_window(variable->mlx, variable->mlx_window);
		exit(1);
	}
	return (0);
}
