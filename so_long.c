/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younesmoukhlij <younesmoukhlij@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:39:48 by youmoukh          #+#    #+#             */
/*   Updated: 2024/01/20 00:54:23 by younesmoukh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	show(void)
{
	system("leaks so_long");
}

// int	key_hook(int key, t_solong *variable)
// {
// 	int	x;

// 	if (key == 2 || key == 124)
// 		to_right(&variable);
// 	else if (key == 0 || key == 123)
// 		to_left(&variable);
// 	else if (key == 13 || key == 126)
// 		to_up(&variable);
// 	else if (key == 1 || key == 125)
// 		to_down(&variable);
// 	else if (key == 53)
// 	{
// 		ft_free_map(&variable)
// 		mlx_destroy_window(variable->mlx, variable->mlx_window);
// 		exit(1);
// 	}
// 	return (0);
// }

void	fill_out_image_to_window(t_solong ***variable, int x, int y, char *img)
{
	int		img_w;
	int		img_h;

	(**v)->img = mlx_xpm_file_to_image((**v)->mlx, img, &img_w, &img_h);
	if (!(**v)->image)
		error_msg();
	mlx_put_image_to_window((**v)->mlx, (**v)->win, (**v)->img, x, y);
}

void	fill_out_image(char c, int x1, int y1, t_solong **v)
{
	if (c == '1')
		fill_out_image_to_window(&v, x1, y1, "./img/wall.xpm");
	else if (c == 'C')
	{
		fill_out_image_to_window(&v, x1, y1, "./img/floor.xpm");
		fill_out_image_to_window(&v, x1, y1, "./img/collect.xpm");
		(*v)->collect++;
	}
	else if (c == 'P')
	{
		(*v)->y_p = y1;
		(*v)->x_p = x1;
		fill_out_image_to_window(&v, x1, y1, "./img/floor.xpm");
		fill_out_image_to_window(&v, x1, y1, "./img/front.xpm");
	}
	else
		fill_out_image_to_window(&v, x1, y1, "./img/floor.xpm");
}

void	fill_out_variables(t_solong *variables)
{
	variables->win_length = calculate_length((variables)->map.map);
	variables->win_heigth = calculate_heigth((variables)->map.map);
}

void	fill_out_game(t_solong *variable)
{
	int		x;
	int		y;

	x = 0;
	// variable.img_size = 30;
	while (variable->map.map[x])
	{
		y = 0;
		while (variable->map.map[x][y])
		{
			fill_out_image(variable, x, y);
			y++;
		}
		x++;
	}
}

int	main(int ac, char **av)
{
	t_solong	variable;

	// atexit(show);
	ft_parse(ac, av[1], &variable);
	fill_out_variables(&variable);
	printf("*************** KING *************\n");
	printf("length [%d]\n", variable.win_length);
	printf("heigth [%d]\n", variable.win_heigth);
	printf("N   PL [%d]\n", variable.map.player.player);
	printf("N   CL [%d]\n", variable.map.collectible);
	printf("N   EX [%d]\n", variable.map.exit);
	fill_out_game(&variable);
	variable.mlx = mlx_init();
	variable.mlx_window = mlx_new_window(variable.mlx, variable.win_length * 50 , variable.win_heigth * 50, "so_long");
	//mlx_hook(mlx_win_list_t *win_ptr, int x_event, int x_mask, int (*f)(), void *param)

	mlx_loop(variable.mlx);
	// variable.mlx = mlx_init();
	return (0);
}
