/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_out_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younesmoukhlij <younesmoukhlij@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:13:32 by youmoukh          #+#    #+#             */
/*   Updated: 2024/01/29 23:23:12 by younesmoukh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	full_fill_xpm_to_image(t_solong *var)
{
	int	width;
	int	length;

	var->wall = mlx_xpm_file_to_image(var->mlx, WL, &width, &length);
	var->floor = mlx_xpm_file_to_image(var->mlx, FL, &width, &length);
	var->player = mlx_xpm_file_to_image(var->mlx, PL, &width, &length);
	var->collec = mlx_xpm_file_to_image(var->mlx, CL, &width, &length);
	var->ennemy_1 = mlx_xpm_file_to_image(var->mlx, EN_1, &width, &length);
	var->ennemy_2 = mlx_xpm_file_to_image(var->mlx, EN_2, &width, &length);
	var->ennemy_3 = mlx_xpm_file_to_image(var->mlx, EN_3, &width, &length);
	var->exit_cld = mlx_xpm_file_to_image(var->mlx, EXIT_CLOSED,
			&width, &length);
	var->exit_opened = mlx_xpm_file_to_image(var->mlx, EXIT_OPEN,
			&width, &length);
	if (!var->wall || !var->floor || !var->ennemy_1
		|| !var->ennemy_2 || !var->ennemy_3 || !var->player
		|| !var->collec || !var->exit_cld || !var->exit_opened)
		return ;
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
	if (mlx_clear_window(variable->mlx, variable->mlx_window) == -1)
		ft_destroy(variable, 1);
	full_fill_xpm_to_image(variable);
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
