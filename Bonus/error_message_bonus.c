/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:20:26 by youmoukh          #+#    #+#             */
/*   Updated: 2024/02/01 14:05:08 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	error_message_helper(t_solong *var, int mode)
{
	if (mode == 20)
		write(2, "Malloc is not Working\n", 22);
	if (mode == 7)
		write(2, "Textures cannot be loadable\n", 28);
	if (mode == 100)
	{
		ft_free(var->map.map);
		write(2, "No Space for Enemy!\n", 20);
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
		write(2, "File's extention is not valid\n", 31);
	if (mode == 6)
		write(2, "Try giving me the name of files's Map.\n", 39);
	error_message_helper(var, mode);
	exit(1);
}
