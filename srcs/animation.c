
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
	int	i;
	int	j;

	i = var->enemy.x;
	j = var->enemy.y;
	if (var->map.map[i][j + 1] == '0')
	{
		ft_swap(&var->map.map[var->enemy.x][var->enemy.y + 1],
			&var->map.map[var->enemy.x][var->enemy.y]);
		var->enemy.y++;
	}
	else if (var->map.map[i][j - 1] == '0')
	{
		ft_swap(&var->map.map[var->enemy.x][var->enemy.y],
			&var->map.map[var->enemy.x][var->enemy.y - 1]);
		var->enemy.y--;
	}
	fill_out_game(var);
}

void	ft_animate_enemy(t_solong *var)
{
	int	i;
	int j;
	static int	counter;

	i = var->enemy.x;
	j = var->enemy.y;
	if (counter++ < var->enemy.frame * 15)
		mlx_put_image_to_window(var->mlx, var->mlx_window, var->ennemy_1, j * SIZE, i * SIZE);
	else if (counter++ < var->enemy.frame * 20)
		mlx_put_image_to_window(var->mlx, var->mlx_window, var->ennemy_2, j * SIZE, i * SIZE);
	else if (counter++ < var->enemy.frame * 25)
		mlx_put_image_to_window(var->mlx, var->mlx_window, var->ennemy_3, j * SIZE, i * SIZE);
	else if (counter++ < var->enemy.frame * 30)
	{
		ft_move_enemy(var);
		counter = 0;
	}
}

void	ft_animate_spirites(t_solong *var)
{
	int			i;
	int			j;
	static int	c;

	i = var->spirite.x;
	j = var->spirite.y;
	if (c++ < var->enemy.frame * 5)
		mlx_put_image_to_window(var->mlx, var->mlx_window, var->spirite_1, j * SIZE, i * SIZE);
	else if (c++ < var->enemy.frame * 6)
		mlx_put_image_to_window(var->mlx, var->mlx_window, var->spirite_2, j * SIZE, i * SIZE);
	else if (c++ < var->enemy.frame * 7)
		mlx_put_image_to_window(var->mlx, var->mlx_window, var->spirite_3, j * SIZE, i * SIZE);
	else if (c++ < var->enemy.frame * 8)
		mlx_put_image_to_window(var->mlx, var->mlx_window, var->spirite_4, j * SIZE, i * SIZE);
	else if (c++ < var->enemy.frame * 9)
		mlx_put_image_to_window(var->mlx, var->mlx_window, var->spirite_5, j * SIZE, i * SIZE);
	else if (c++ < var->enemy.frame * 10)
		mlx_put_image_to_window(var->mlx, var->mlx_window, var->spirite_6, j * SIZE, i * SIZE);
	else if (c++ < var->enemy.frame * 11)
		mlx_put_image_to_window(var->mlx, var->mlx_window, var->spirite_7, j * SIZE, i * SIZE);
	else if (c++ < var->enemy.frame * 12)
	{
		mlx_put_image_to_window(var->mlx, var->mlx_window, var->spirite_8, j * SIZE, i * SIZE);
		c = 0;
	}
}

int	ft_animation(t_solong *variable)
{
	ft_animate_enemy(variable);
	ft_animate_spirites(variable);
	if (variable->enemy.x == variable->map.player.x && variable->enemy.y == variable->map.player.y)
	{
		ft_free_map(&variable);
		write(1, "YOU LOSE (< . . . >)\n He's a Baster for sure !\n", 45);
		mlx_destroy_window(variable->mlx, variable->mlx_window);
		exit(0);
	}
	ft_put_string_to_screen(variable);
	return (1);
}
