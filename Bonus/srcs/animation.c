/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younesmoukhlij <younesmoukhlij@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:04:27 by youmoukh          #+#    #+#             */
/*   Updated: 2024/01/30 00:39:59 by younesmoukh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_put_string_to_screen(t_solong *var)
{
	char	*s;
	char	*str;

	str = ft_itoa(var->move_count);
	s = ft_strjoin_bonus("Move : ", str);
	mlx_string_put(var->mlx, var->mlx_window, 50, 50, 0xffffff, s);
	free (s);
}

void	ft_move_enemy(t_solong *var)
{
	if (var->map.map[var->enemy.y][var->enemy.x + 1] == '0')
	{
		ft_swap(&var->map.map[var->enemy.y][var->enemy.x + 1],
			&var->map.map[var->enemy.y][var->enemy.x]);
		var->enemy.x++;
	}
	else if (var->map.map[var->enemy.y][var->enemy.x - 1] == '0')
	{
		ft_swap(&var->map.map[var->enemy.y][var->enemy.x - 1],
			&var->map.map[var->enemy.y][var->enemy.x]);
		var->enemy.x--;
	}
	fill_out_game(var);
}

void	ft_animate_enemy(t_solong *var)
{
	int			i;
	int			j;
	static int	counter1;

	i = var->enemy.x;
	j = var->enemy.y;
	if (counter1++ < var->enemy.frame * 15)
		mlx_put_image_to_window(var->mlx, var->mlx_window, var->ennemy_1, i * SIZE, j * SIZE);
	else if (counter1++ < var->enemy.frame * 20)
		mlx_put_image_to_window(var->mlx, var->mlx_window, var->ennemy_2, i * SIZE, j * SIZE);
	else if (counter1++ < var->enemy.frame * 25)
		mlx_put_image_to_window(var->mlx, var->mlx_window, var->ennemy_3, i * SIZE, j * SIZE);
	else if (counter1++ < var->enemy.frame * 32)
	{
		ft_move_enemy(var);
		counter1 = 0;
	}
}

int	ft_animation(t_solong *variable)
{
	ft_animate_enemy(variable);
	if (variable->enemy.x == variable->map.player.x && variable->enemy.y == variable->map.player.y)
	{
		write(1, "YOU LOSE (< . . . >)\n He's a Baster for sure !\n", 45);
		ft_destroy(variable, 0);
	}
	ft_put_string_to_screen(variable);
	return (0);
}
