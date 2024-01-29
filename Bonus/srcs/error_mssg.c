/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_mssg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:20:26 by youmoukh          #+#    #+#             */
/*   Updated: 2024/01/29 12:22:36 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	error_mssg(int mode)
{
	if (mode == 0)
		write(1, "file could not ne opened\n", 30);
	if (mode == 1)
		write(1, "file could not ne opened\n", 30);
	if (mode == 2)
		write(1, "file could not ne opened\n", 30);
	if (mode == 3)
		write(1, "file could not ne opened\n", 30);
	if (mode == 4)
		write(1, "file could not ne opened\n", 30);
}
