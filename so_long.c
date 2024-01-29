/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:39:48 by youmoukh          #+#    #+#             */
/*   Updated: 2024/01/29 19:12:30 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	show(void)
{
	system("leaks so_long");
}

void	fill_out_variables(t_solong *variable)
{
	variable->win_length = calculate_length((variable)->map.map);
	variable->win_heigth = calculate_heigth((variable)->map.map);
	position_player(variable);
	variable->move_count = 0;
	variable->image_size = SIZE;
	full_fill_xpm_to_image(variable);
}

int	exit_game(void *program)
{
	t_solong	*variable;

	variable = (t_solong *)program;
	ft_destroy(variable, 0);
	return (0);
}

int	main(int ac, char **av)
{
	t_solong	variable;

	// atexit(show);
	variable.mlx = mlx_init();
	ft_parse(ac, av[1], &variable);
	variable.mlx_window = mlx_new_window(variable.mlx,
			variable.win_length * SIZE, variable.win_heigth * SIZE, "So-Long");
	fill_out_game(&variable);
	mlx_hook(variable.mlx_window, 2, 0, key_hook_function, &variable);
	mlx_hook(variable.mlx_window, 17, 0, exit_game, &variable);
	mlx_loop(variable.mlx);
	return (0);
}
