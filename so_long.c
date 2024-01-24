/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younesmoukhlij <younesmoukhlij@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:39:48 by youmoukh          #+#    #+#             */
/*   Updated: 2024/01/23 23:15:43 by younesmoukh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	show(void)
{
	system("leaks so_long");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 04:06:44 by sel-jett          #+#    #+#             */
/*   Updated: 2024/01/05 05:03:05 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	get_path(t_maps *map)
{
	int		i;
	char	*path[6];
	int		n;
	int		m;

	i = -1;
	path[0] = "img/black.xpm";
	path[1] = "img/close.xpm";
	path[2] = "img/eth.xpm";
	path[3] = "img/open.xpm";
	path[4] = "img/player.xpm";
	path[5] = "img/wall.xpm";
	while (++i < 6)
	{
		map->arr[i] = mlx_xpm_file_to_image(map->p_mlx, path[i], &n, &m);
		if (!map->arr[i] || n > 50 || m > 50)
			exit(1);
	}
}

static void	my_helper(t_maps *m, int i, int j)
{
	if (m->map[i][j] == '0')
		mlx_put_image_to_window(m->p_mlx, m->w_mlx, m->arr[0], j * 50, i * 50);
	else if (m->map[i][j] == '1')
		mlx_put_image_to_window(m->p_mlx, m->w_mlx, m->arr[5], j * 50, i * 50);
	else if (m->map[i][j] == 'P')
		mlx_put_image_to_window(m->p_mlx, m->w_mlx, m->arr[4], j * 50, i * 50);
	else if (m->map[i][j] == 'E' && m->c > 0)
		mlx_put_image_to_window(m->p_mlx, m->w_mlx, m->arr[1], j * 50, i * 50);
	else if (m->map[i][j] == 'E' && m->c == 0)
		mlx_put_image_to_window(m->p_mlx, m->w_mlx, m->arr[3], j * 50, i * 50);
	else if (m->map[i][j] == 'C')
		mlx_put_image_to_window(m->p_mlx, m->w_mlx, m->arr[2], j * 50, i * 50);
}

void	ft_draw(t_maps *m)
{
	int		i;
	int		j;

	get_path(m);
	i = 0;
	while (m->map[i])
	{
		j = 0;
		while (m->map[i][j])
		{
			my_helper(m, i, j);
			j++;
		}
		i++;
	}
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
	mlx_hook(variable.mlx_window, 2, 0, key_hook_function, &variable);
	mlx_loop(variable.mlx);
	return (0);
}
