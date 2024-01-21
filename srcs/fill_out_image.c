/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_out_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younesmoukhlij <younesmoukhlij@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 20:56:38 by younesmoukh       #+#    #+#             */
/*   Updated: 2024/01/20 21:54:44 by younesmoukh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*render_xpm_to_image(t_solong *var, char *xpm_file)
{
	void	*ptr;
	int		i;

	i = 40;
	printf("%s\n", "younes");
	// ptr = mlx_xpm_file_to_image(var->mlx, xpm_file, &(var->image_size), &(var->image_size));
	ptr = mlx_xpm_file_to_image(var->mlx, xpm_file, &(i), &(i));
	// if (!ptr)
	// {
	// 	printf("%s\n", (char *)ptr);
	// 	write(1, "mlx_xpm_file_to_image function fails!\n", 39);
	// 	// exit(1);
	// }
	return (ptr);
}

void	inisialize_and_store_images(t_solong *var)
{
	var->wall = render_xpm_to_image(var->mlx, WL);
	var->floor = render_xpm_to_image(var->mlx, FL);
	var->player = render_xpm_to_image(var, PL);
	var->collec = render_xpm_to_image(var->mlx, CL);
	if (var->collec == 0)
		var->exit = render_xpm_to_image(var->mlx, exit_open);
	else
		var->exit = render_xpm_to_image(var->mlx, exit_closed);
}
