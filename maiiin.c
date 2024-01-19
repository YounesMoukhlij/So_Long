#include "mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct s_tt
{
	void	*mlx;
	void	*mlx_win;
} t_tt;
int key(int keycode,  void *param)
{
	t_tt *hello = (t_tt*)param;
	printf("%d\n", keycode);
	if (keycode == 53)
	{
		mlx_destroy_window(hello->mlx, hello->mlx_win);
		exit(1);
	}
	return (0);
}

int main(void)
{
	t_tt vars;
	int a;

	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, 800, 800, "youness");
	mlx_hook(vars.mlx_win, 2, 0, key, &vars);
	mlx_loop(vars.mlx);
}
