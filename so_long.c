/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younesmoukhlij <younesmoukhlij@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:39:48 by youmoukh          #+#    #+#             */
/*   Updated: 2024/01/20 23:28:16 by younesmoukh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	show(void)
{
	system("leaks so_long");
}

// void	fill_out_image_to_window(t_solong ***var, int x, int y, char *img)
// {
// 	(**var)->mlx_image = mlx_xpm_file_to_image((**var)->mlx, img, &(**var)->image_size, &(**var)->image_size);
// 	// if (!(**var)->mlx_image)
// 	// {
// 		// printf("%s\n", (char *)((**var)->mlx_image));
// 		// error_msg();
// 	// }
// 	mlx_put_image_to_window((**var)->mlx, (**var)->mlx_window, (**var)->mlx_image, x * SIZE, y * SIZE);
// }

// void	fill_out_image(t_solong **v, int x, int y, char a)
// {
// 	if (a == '1')
// 		fill_out_image_to_window(&v, x * SIZE, y * SIZE, (*v)->wall);
// 	else if (a == 'E')
// 		fill_out_image_to_window(&v, x * SIZE, y * SIZE, (*v)->exit);
// 	else if (a == 'C')
// 	{
// 		fill_out_image_to_window(&v, x * SIZE, y * SIZE, (*v)->collec);
// 		// fill_out_image_to_window(&v, x, y, (*v)->floor);
// 		(*v)->map.collectible++;
// 	}
// 	else if (a == 'P')
// 	{
// 		(*v)->map.player.y = y;
// 		(*v)->map.player.x = x;
// 		fill_out_image_to_window(&v, x * SIZE, y * SIZE, (*v)->player);
// 	}
// 	else if ((*v)->map.collectible == 0)
// 		fill_out_image_to_window(&v, x * SIZE, y * SIZE, (*v)->exit);
// 	else
// 		fill_out_image_to_window(&v, x * SIZE, y * SIZE, (*v)->floor);

// }

void	fill_out_variables(t_solong *variables)
{
	variables->image_size = SIZE;
	variables->win_length = calculate_length((variables)->map.map) * SIZE;
	variables->win_heigth = calculate_heigth((variables)->map.map) * SIZE;
	variables->map.player.x = position_player(variables, 'x');
	variables->map.player.y = position_player(variables, 'y');
	// inisialize_and_store_images(variables);
}

// void	fill_out_game(t_solong *variable)
// {
// 	int		x;
// 	int		y;

// 	x = 0;
// 	while (variable->map.map[x])
// 	{
// 		y = 0;
// 		while (variable->map.map[x][y])
// 		{
// 			fill_out_image(&variable, x, y, variable->map.map[x][y]);
// 			y++;
// 		}
// 		x++;
// 	}
// }

int	main(int ac, char **av)
{
	t_solong	variable;

	// atexit(show);
	ft_parse(ac, av[1], &variable);
	fill_out_variables(&variable);
	printf("length [%d]\n", variable.win_length);
	printf("heigth [%d]\n", variable.win_heigth);
	printf("N   PL [%d]\n", variable.map.player.player);
	printf("N   CL [%d]\n", variable.map.collectible);
	printf("N   EX [%d]\n", variable.map.exit);
	variable.mlx = mlx_init();
	variable.mlx_window = mlx_new_window(variable.mlx, variable.win_length , variable.win_heigth, "so_long");
	// fill_out_game(&variable);
	int i = 50;
	// void *ptr;
	char *xpm_file = "player.xpm";
	mlx_xpm_to_image(variable.mlx, &xpm_file, &(i), &(i));
	mlx_put_image_to_window(variable.mlx, variable.mlx_window, xpm_file, 50, 50);
	mlx_hook(variable.mlx_window, 2, 0, key_hook_function, &variable);
	mlx_loop(variable.mlx);
	return (0);
}
