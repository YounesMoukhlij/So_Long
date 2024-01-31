/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:04:27 by youmoukh          #+#    #+#             */
/*   Updated: 2024/01/31 19:54:22 by youmoukh         ###   ########.fr       */
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

void	ft_animate_enemy(t_solong *var)
{
	static int	counter;

	if (counter++ < var->enemy.frame * 5)
		mlx_put_image_to_window(var->mlx, var->mlx_window,
			var->ennemy_1, var->enemy.x * SIZE, var->enemy.y * SIZE);
	else if (counter++ < var->enemy.frame * 6)
		mlx_put_image_to_window(var->mlx, var->mlx_window,
			var->ennemy_2, var->enemy.x * SIZE, var->enemy.y * SIZE);
	else if (counter++ < var->enemy.frame * 7)
		mlx_put_image_to_window(var->mlx, var->mlx_window,
			var->ennemy_3, var->enemy.x * SIZE, var->enemy.y * SIZE);
	else if (counter < var->enemy.frame * 50)
		counter = 0;
}

int	ft_animation(t_solong *variable)
{
	ft_animate_enemy(variable);
	if (variable->enemy.x == variable->map.player.x && variable->enemy.y == variable->map.player.y)
	{
		write(1, "YOU LOSE (< . . . >)\nHe's a Baster for sure !\n", 47);
		ft_destroy(variable, 0);
	}
	ft_put_string_to_screen(variable);
	return (0);
}
