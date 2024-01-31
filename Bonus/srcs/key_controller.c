/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_controller.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:13:40 by youmoukh          #+#    #+#             */
/*   Updated: 2024/01/31 16:20:52 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	key_hook_function(int key, void *program)
{
	t_solong	*variable;

	variable = (t_solong *)program;
	if (key == SKEY_R || key == 124)
		move_to_right(variable);
	else if (key == SKEY_L || key == 123)
		move_to_left(variable);
	else if (key == SKEY_U || key == 126)
		move_to_up(variable);
	else if (key == SKEY_D || key == 125)
		move_to_down(variable);
	else if (key == SKEY_ESC)
		ft_destroy(variable, 0);
	return (0);
}
