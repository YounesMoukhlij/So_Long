/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:17:19 by youmoukh          #+#    #+#             */
/*   Updated: 2024/01/26 13:33:45 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_swap(char *a, char *b)
{
	char	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	move_to_up(t_solong *variable)
{
	if (variable->map.map[variable->map.player.x - 1][variable->map.player.y] == '0')
	{
		ft_swap(&variable->map.map[variable->map.player.x - 1][variable->map.player.y],
			&variable->map.map[variable->map.player.x][variable->map.player.y]);
		variable->map.player.x--;
		write_moves_helper(variable);
	}
	else if (variable->map.map[variable->map.player.x - 1][variable->map.player.y] == 'C')
	{
		variable->map.collectible--;
		variable->map.map[variable->map.player.x][variable->map.player.y] = '0';
		variable->map.map[variable->map.player.x - 1][variable->map.player.y] = 'P';
		variable->map.player.x--;
		write_moves_helper(variable);
	}
	else if (variable->map.map[variable->map.player.x - 1][variable->map.player.y] == 'E'
		&& !variable->map.collectible)
	{
		ft_free_map(&variable);
		mlx_destroy_window(variable->mlx, variable->mlx_window);
		write(1, "Bravo\n", 6);
		exit(0);
	}
}

void	move_to_down(t_solong *variable)
{
	if (variable->map.map[variable->map.player.x + 1][variable->map.player.y] == '0')
	{
		ft_swap(&variable->map.map[variable->map.player.x + 1][variable->map.player.y],
			&variable->map.map[variable->map.player.x][variable->map.player.y]);
		variable->map.player.x++;
		write_moves_helper(variable);
	}
	else if (variable->map.map[variable->map.player.x + 1][variable->map.player.y] == 'C')
	{
		variable->map.collectible--;
		variable->map.map[variable->map.player.x][variable->map.player.y] = '0';
		variable->map.map[variable->map.player.x + 1][variable->map.player.y] = 'P';
		variable->map.player.x++;
		write_moves_helper(variable);
	}
	else if (variable->map.map[variable->map.player.x + 1][variable->map.player.y] == 'E'
		&& !variable->map.collectible)
	{
		ft_free_map(&variable);
		mlx_destroy_window(variable->mlx, variable->mlx_window);
		write(1, "Bravo\n", 6);
		exit(0);
	}
}

void	move_to_left(t_solong *variable)
{
	if (variable->map.map[variable->map.player.x][variable->map.player.y - 1] == '0')
	{
		ft_swap(&variable->map.map[variable->map.player.x][variable->map.player.y - 1],
			&variable->map.map[variable->map.player.x][variable->map.player.y]);
		variable->map.player.y--;
		write_moves_helper(variable);
	}
	else if (variable->map.map[variable->map.player.x][variable->map.player.y - 1] == 'C')
	{
		variable->map.collectible--;
		variable->map.map[variable->map.player.x][variable->map.player.y] = '0';
		variable->map.map[variable->map.player.x][variable->map.player.y - 1] = 'P';
		variable->map.player.y--;
		write_moves_helper(variable);
	}
	else if (variable->map.map[variable->map.player.x][variable->map.player.y - 1] == 'E'
		&& !variable->map.collectible)
	{
		ft_free_map(&variable);
		mlx_destroy_window(variable->mlx, variable->mlx_window);
		write(1, "Bravo\n", 6);
		exit(0);
	}
}

void	move_to_right(t_solong *variable)
{
	if (variable->map.map[variable->map.player.x][variable->map.player.y + 1] == '0')
	{
		ft_swap(&variable->map.map[variable->map.player.x][variable->map.player.y + 1],
			&variable->map.map[variable->map.player.x][variable->map.player.y]);
		variable->map.player.y++;
		write_moves_helper(variable);
	}
	else if (variable->map.map[variable->map.player.x][variable->map.player.y + 1] == 'C')
	{
		variable->map.collectible--;
		variable->map.map[variable->map.player.x][variable->map.player.y] = '0';
		variable->map.map[variable->map.player.x][variable->map.player.y + 1] = 'P';
		variable->map.player.y++;
		write_moves_helper(variable);
	}
	else if (variable->map.map[variable->map.player.x][variable->map.player.y + 1] == 'E'
		&& !variable->map.collectible)
	{
		ft_free_map(&variable);
		mlx_destroy_window(variable->mlx, variable->mlx_window);
		write(1, "Bravo\n", 6);
		exit(0);
	}
}
