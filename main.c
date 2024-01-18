/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:39:48 by youmoukh          #+#    #+#             */
/*   Updated: 2024/01/18 18:55:47 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	show(void)
{
	system("leaks so_long");
}

int	main(int ac, char **av)
{
	// atexit(show);
	ft_parse(ac, av[1]);
	return (0);
}
