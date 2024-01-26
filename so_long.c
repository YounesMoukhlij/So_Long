/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:39:48 by youmoukh          #+#    #+#             */
/*   Updated: 2024/01/26 17:58:58 by youmoukh         ###   ########.fr       */
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
	full_fill_xpm_to_image(variables);
	variables->enemy.x = position_player(variables, 'x');
	variables->enemy.y = position_player(variables, 'y');
	variables->map.player.x = position_player(variables, 'x');
	variables->map.player.y = position_player(variables, 'y');
	variables->win_length = calculate_length((variables)->map.map) * SIZE;
	variables->win_heigth = calculate_heigth((variables)->map.map) * SIZE;
}

// void	ft_move_enemy()
// {

// }

int	exit_game(void *program)
{
	t_solong *variable;
	
	variable = (t_solong *)program;
	ft_free_map(&variable);
	mlx_destroy_window(variable->mlx, variable->mlx_window);
	exit(0);
	return (0);
}

int	ft_animation(t_solong *variable)
{
	(void) variable;
	return (0);
}

int	main(int ac, char **av)
{
	t_solong	variable;

	// atexit(show);
	ft_parse(ac, av[1], &variable);
	variable.mlx = mlx_init();
	fill_out_variables(&variable);
	variable.mlx_window = mlx_new_window(variable.mlx, variable.win_length, variable.win_heigth, "So-Long");
	fill_out_game(&variable);
	mlx_hook(variable.mlx_window, 2, 0, key_hook_function, &variable);
	mlx_hook(variable.mlx_window, 17, 0, exit_game, &variable);
	mlx_string_put(variable.mlx, variable.mlx_window, 100, 110, 0xffffff, "Move : ");
	mlx_loop_hook(variable.mlx, ft_animation, &variable);
	mlx_loop(variable.mlx);
	return (0);
}
