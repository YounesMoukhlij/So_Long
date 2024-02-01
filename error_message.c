/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:07:31 by youmoukh          #+#    #+#             */
/*   Updated: 2024/02/01 14:09:34 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_message_helper(t_solong *var, int mode)
{
	(void) var;
	if (mode == 7)
		write(2, "Textures cannot be loadable\n", 28);
	if (mode == 20)
	{
		write(2, "Malloc is not Working\n", 22);
	}
}

void	error_message(t_solong *var, int mode)
{
	write(2, "Error\n", 6);
	if (mode == 0)
	{
		ft_free(var->map.map);
		write(2, "Map is not a rectangle.\n", 24);
	}
	if (mode == 1)
	{
		ft_free(var->map.map);
		write(2, "Walls are not valid.\n", 21);
	}
	if (mode == 2 || mode == 4)
	{
		ft_free(var->map.map);
		write(2, "Members are not valid.\n", 23);
	}
	if (mode == 3)
		write(2, "The map has not a valid path.\n", 30);
	if (mode == 5)
		write(2, "File's extenstion is not valid\n", 31);
	if (mode == 6)
		write(2, "Try giving me the name of files's Map.\n", 39);
	error_message_helper(var, mode);
	exit(1);
}
