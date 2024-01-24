/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:39:48 by youmoukh          #+#    #+#             */
/*   Updated: 2024/01/24 20:15:52 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	show(void)
{
	system("leaks so_long");
}

void	fill_out_variables(t_solong *variables)
{
	variables->image_size = SIZE;
	variables->win_length = calculate_length((variables)->map.map) * SIZE;
	variables->win_heigth = calculate_heigth((variables)->map.map) * SIZE;
	variables->map.player.x = position_player(variables, 'x');
	variables->map.player.y = position_player(variables, 'y');
	full_fill_xpm_to_image(variables);
}

int	main(int ac, char **av)
{
	t_solong	variable;

	// atexit(show);
	ft_parse(ac, av[1], &variable);
	fill_out_variables(&variable);
	variable.mlx = mlx_init();
	variable.mlx_window = mlx_new_window(variable.mlx, variable.win_length, variable.win_heigth, "so_long");
	// fill_out_game(&variable);
	// mlx_hook(variable.mlx_window, 2, 0, key_hook_function, &variable);
	mlx_loop(variable.mlx);
	return (0);
}
