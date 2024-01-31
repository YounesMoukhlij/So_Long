/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_out_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younesmoukhlij <younesmoukhlij@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:13:32 by youmoukh          #+#    #+#             */
/*   Updated: 2024/01/31 21:53:43 by younesmoukh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	full_fill_xpm_to_image(t_solong *var)
{
	int	width;
	int	length;

	var->wall = mlx_xpm_file_to_image(var->mlx, WL, &width, &length);
	var->floor = mlx_xpm_file_to_image(var->mlx, FL, &width, &length);
	var->player = mlx_xpm_file_to_image(var->mlx, PL, &width, &length);
	var->collec = mlx_xpm_file_to_image(var->mlx, CL, &width, &length);
	var->ennemy_1 = mlx_xpm_file_to_image(var->mlx, E1, &width, &length);
	var->ennemy_2 = mlx_xpm_file_to_image(var->mlx, E2, &width, &length);
	var->ennemy_3 = mlx_xpm_file_to_image(var->mlx, E3, &width, &length);
	var->exit_cld = mlx_xpm_file_to_image(var->mlx, EXIT_CLOSED,
			&width, &length);
	var->exit_opened = mlx_xpm_file_to_image(var->mlx, EXIT_OPEN,
			&width, &length);
	if (!var->wall || !var->floor || !var->ennemy_1
		|| !var->ennemy_2 || !var->ennemy_3 || !var->player
		|| !var->collec || !var->exit_cld || !var->exit_opened)
		error_message(var, 6);
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

void	fill_out_floor(t_solong *var)
{
	int	x;
	int	y;

	x = 0;
	while (var->map.map[x])
	{
		y = 0;
		while (var->map.map[x][y])
		{
			mlx_put_image_to_window(var->mlx,
				var->mlx_window, var->floor, y * SIZE, x * SIZE);
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
