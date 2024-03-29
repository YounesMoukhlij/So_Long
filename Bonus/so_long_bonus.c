/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:39:48 by youmoukh          #+#    #+#             */
/*   Updated: 2024/02/01 16:44:50 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	fill_out_variables(t_solong *variables)
{
	variables->move_count = 0;
	variables->enemy.frame = 5;
	position_player(variables);
	position_enemy(variables);
	position_exit(variables);
	variables->image_size = SIZE;
	full_fill_xpm_to_image(variables);
	variables->win_length = calculate_length((variables)->map.map);
	variables->win_heigth = calculate_heigth((variables)->map.map);
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

	variable.mlx = mlx_init();
	ft_parse(ac, av[1], &variable);
	variable.mlx_window = mlx_new_window(variable.mlx,
			variable.win_length * SIZE, variable.win_heigth * SIZE, "So-Long");
	fill_out_game(&variable);
	mlx_loop_hook(variable.mlx, ft_animation, &variable);
	mlx_hook(variable.mlx_window, 2, 0, key_hook_function, &variable);
	mlx_hook(variable.mlx_window, 17, 0, exit_game, &variable);
	mlx_loop(variable.mlx);
	return (0);
}
