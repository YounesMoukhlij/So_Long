/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younesmoukhlij <younesmoukhlij@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:39:48 by youmoukh          #+#    #+#             */
/*   Updated: 2024/01/19 01:21:12 by younesmoukh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	show(void)
{
	system("leaks so_long");
}

int	main(int ac, char **av)
{
	t_solong variable;
	
	// atexit(show);
	ft_parse(ac, av[1]);
	printf("%d\n", (variable.map.player));
	return (0);
}
