/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_out_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younesmoukhlij <younesmoukhlij@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 20:56:38 by younesmoukh       #+#    #+#             */
/*   Updated: 2024/01/28 18:22:48 by younesmoukh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	fill_out_spirites(t_solong *var, int *width, int *length)
{
	var->spirite_1 = mlx_xpm_file_to_image(var->mlx, S1, width, length);
	var->spirite_2 = mlx_xpm_file_to_image(var->mlx, S2, width, length);
	var->spirite_3 = mlx_xpm_file_to_image(var->mlx, S3, width, length);
	var->spirite_4 = mlx_xpm_file_to_image(var->mlx, S4, width, length);
	var->spirite_5 = mlx_xpm_file_to_image(var->mlx, S5, width, length);
	var->spirite_6 = mlx_xpm_file_to_image(var->mlx, S6, width, length);
	var->spirite_7 = mlx_xpm_file_to_image(var->mlx, S7, width, length);
	var->spirite_8 = mlx_xpm_file_to_image(var->mlx, S8, width, length);
}

void	full_fill_xpm_to_image(t_solong *var)
{
	int	width;
	int	length;

	fill_out_spirites(var, &width, &length);
	var->wall = mlx_xpm_file_to_image(var->mlx, WL, &width, &length);
	var->floor = mlx_xpm_file_to_image(var->mlx, FL, &width, &length);
	var->ennemy_1 = mlx_xpm_file_to_image(var->mlx, EN_1, &width, &length);
	var->ennemy_2 = mlx_xpm_file_to_image(var->mlx, EN_2, &width, &length);
	var->ennemy_3 = mlx_xpm_file_to_image(var->mlx, EN_3, &width, &length);
	var->player = mlx_xpm_file_to_image(var->mlx, PL, &width, &length);
	var->collec = mlx_xpm_file_to_image(var->mlx, CL, &width, &length);
	var->exit_cld = mlx_xpm_file_to_image(var->mlx, exit_closd, &width, &length);
	var->exit_opened = mlx_xpm_file_to_image(var->mlx, exit_open, &width, &length);
}

void	fill_out_image_to_window(t_solong *var, int i, int j)
{
	if (var->map.map[i][j] == '0')
		mlx_put_image_to_window(var->mlx,
			var->mlx_window, var->floor, j * SIZE, i * SIZE);
	else if (var->map.map[i][j] == '1')
		mlx_put_image_to_window(var->mlx, var->mlx_window,
			var->wall, j * SIZE, i * SIZE);
	else if (var->map.map[i][j] == 'P')
		mlx_put_image_to_window(var->mlx,
			var->mlx_window, var->player, j * SIZE, i * SIZE);
	else if (var->map.map[i][j] == 'E' && var->map.collectible > 0)
		mlx_put_image_to_window(var->mlx, var->mlx_window,
			var->exit_cld, j * SIZE, i * SIZE);
	else if (var->map.map[i][j] == 'E' && var->map.collectible == 0)
		mlx_put_image_to_window(var->mlx,
			var->mlx_window, var->exit_opened, j * SIZE, i * SIZE);
	else if (var->map.map[i][j] == 'C')
		mlx_put_image_to_window(var->mlx, var->mlx_window,
			var->collec, j * SIZE, i * SIZE);
}
void	fill_out_floor(t_solong *variable)
{
	int	x;
	int	y;

	x= 0;
	while (variable->map.map[x])
	{
		y = 0;
		while (variable->map.map[x][y])
		{
			mlx_put_image_to_window(variable->mlx,
			variable->mlx_window, variable->floor, y * SIZE, x * SIZE);
			y++;
		}
		x++;
	}
}

void	fill_out_game(t_solong *variable)
{
	int		x;
	int		y;

	x = 0;
	mlx_clear_window(variable->mlx, variable->mlx_window);
	fill_out_floor(variable);
	while (variable->map.map[x])
	{
		y = 0;
		while (variable->map.map[x][y])
		{
			fill_out_image_to_window(variable, x, y);
			y++;
		}
		x++;
	}
}
