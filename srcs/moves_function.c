
#include "../so_long.h"

void	ft_swap(char *a, char *b)
{
	char	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	move_up(t_solong *game)
{
	if (game->map.map[game->map.player.x - 1][game->map.player.y] == '0')
	{
		ft_swap(&game->map.map[game->map.player.x - 1][game->map.player.y],
			&game->map.map[game->map.player.x][game->map.player.y]);
		game->map.player.x--;
		printf("[%sMOVED UP%s] - [%sCOUNT%s] > %zu\n", RED, END, YELLOW, END,
			++game->mv_count);
	}
	else if (game->map.map[game->map.player.x - 1][game->map.player.y] == 'C')
	{
		game->map.collectibles--;
		game->map.map[game->map.player.x][game->map.player.y] = '0';
		game->map.map[game->map.player.x - 1][game->map.player.y] = 'P';
		game->map.player.x--;
	}
	else if (game->map.map[game->map.player.x - 1][game->map.player.y] == 'E'
		&& !game->map.collectibles)
		ft_free(game, "BRAVO!");
}

void	move_down(t_solong *game)
{
	if (game->map.map[game->map.player.x + 1][game->map.player.y] == '0')
	{
		ft_swap(&game->map.map[game->map.player.x + 1][game->map.player.y],
			&game->map.map[game->map.player.x][game->map.player.y]);
		game->map.player.x++;
		printf("[%sMOVED DOWN%s] - [%sCOUNT%s] > %zu\n", RED, END, YELLOW, END,
			++game->mv_count);
	}
	else if (game->map.map[game->map.player.x + 1][game->map.player.y] == 'C')
	{
		game->map.collectibles--;
		game->map.map[game->map.player.x][game->map.player.y] = '0';
		game->map.map[game->map.player.x + 1][game->map.player.y] = 'P';
		game->map.player.x++;
	}
	else if (game->map.map[game->map.player.x + 1][game->map.player.y] == 'E'
		&& !game->map.collectibles)
		ft_free(game, "BRAVO!");
}

void	move_left(t_solong *game)
{
	if (game->map.map[game->map.player.x][game->map.player.y - 1] == '0')
	{
		ft_swap(&game->map.map[game->map.player.x][game->map.player.y - 1],
			&game->map.map[game->map.player.x][game->map.player.y]);
		game->map.player.y--;
		// printf("[%sMOVED LEFT%s] - [%sCOUNT%s] > %zu\n", RED, END, YELLOW, END,
		// 	++game->mv_count);
	}
	else if (game->map.map[game->map.player.x][game->map.player.y - 1] == 'C')
	{
		game->map.collectible--;
		game->map.map[game->map.player.x][game->map.player.y] = '0';
		game->map.map[game->map.player.x][game->map.player.y - 1] = 'P';
		game->map.player.y--;
	}
	else if (game->map.map[game->map.player.x][game->map.player.y - 1] == 'E'
		&& !game->map.collectible)
		// ft_free(game, "BRAVO!");
}

void	move_right(t_solong *game)
{
	if (game->map.map[game->map.player.x][game->map.player.y + 1] == '0')
	{
		ft_swap(&game->map.map[game->map.player.x][game->map.player.y + 1],
			&game->map.map[game->map.player.x][game->map.player.y]);
		game->map.player.y++;
		// printf("[%sMOVED RIGHT%s] - [%sCOUNT%s] > %zu\n", RED, END, YELLOW, END,
		// 	++game->mv_count);
	}
	else if (game->map.map[game->map.player.x][game->map.player.y + 1] == 'C')
	{
		game->map.collectible--;
		game->map.map[game->map.player.x][game->map.player.y] = '0';
		game->map.map[game->map.player.x][game->map.player.y + 1] = 'P';
		game->map.player.y++;
	}
	else if (game->map.map[game->map.player.x][game->map.player.y + 1] == 'E'
		&& !game->map.collectible)
		// ft_free(game, "BRAVO!");
}
