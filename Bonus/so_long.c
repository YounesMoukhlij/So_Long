/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:39:48 by youmoukh          #+#    #+#             */
/*   Updated: 2024/01/29 22:01:14 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	show(void)
{
	system("leaks so_long");
}

void	fill_out_variables(t_solong *variables)
{
	variables->move_count = 0;
	variables->enemy.frame = 5;
	position_player(variables);
	position_enemy(variables);
	printf("x[%d] y[%d]\n", variables->enemy.x, variables->enemy.y);
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

	// atexit(show);
	variable.mlx = mlx_init();
	ft_parse(ac, av[1], &variable);
	variable.mlx_window = mlx_new_window(variable.mlx,
			variable.win_length * SIZE, variable.win_heigth * SIZE, "So-Long");
	fill_out_game(&variable);
	mlx_loop_hook(variable.mlx, ft_animation, &variable);
	printf("x[%d] y[%d]\n", variable.enemy.x, variable.enemy.y);
	mlx_hook(variable.mlx_window, 2, 0, key_hook_function, &variable);
	mlx_hook(variable.mlx_window, 17, 0, exit_game, &variable);
	mlx_loop(variable.mlx);
	return (0);
}