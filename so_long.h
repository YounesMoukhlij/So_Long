/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younesmoukhlij <younesmoukhlij@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:37:09 by youmoukh          #+#    #+#             */
/*   Updated: 2024/01/28 19:04:23 by younesmoukh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include "mlx/mlx.h"

# define SIZE 35
# define SKEY_D 1
# define SKEY_L 0
# define SKEY_R 2
# define SKEY_U 13
# define SKEY_ESC 53
# define BUFFER_SIZE 10
# define WINDOW_CLOSE 17
# define CL "icons/coin.xpm"
// # define EN_1 "icons/enemy_1.xpm"
// # define EN_2 "icons/enemy_2.xpm"
// # define EN_3 "icons/enemy_3.xpm"
# define EN_1 "icons/1.xpm"
# define EN_2 "icons/2.xpm"
# define EN_3 "icons/3.xpm"
# define WL "icons/wall.xpm"
# define FL "icons/floor.xpm"
# define S1 "icons/spirite/potion_08.xpm"
# define S2 "icons/spirite/potion_09.xpm"
# define S3 "icons/spirite/potion_10.xpm"
# define S4 "icons/spirite/potion_11.xpm"
# define S5 "icons/spirite/potion_12.xpm"
# define S6 "icons/spirite/potion_13.xpm"
# define S7 "icons/spirite/potion_14.xpm"
# define S8 "icons/spirite/potion_15.xpm"
# define PL "icons/player.xpm"
# define exit_open "icons/exit_open.xpm"
# define exit_closd "icons/exit_closed.xpm"

typedef struct s_player
{
	int		x;
	int		y;
	int		player;
}	t_player;

typedef struct s_enemy
{
	int		x;
	int		y;
	int		enemy;
	int		frame;
}	t_enemy;

typedef struct s_sprite
{
	int		x;
	int		y;
	int		frame;
}	t_spirite;

typedef struct s_map
{
	int			exit;
	char		**map;
	t_player	player;
	int			collectible;
}	t_map;

typedef struct s_solong
{
	t_map		map;
	void		*mlx;
	void		*wall;
	t_enemy		enemy;
	void		*floor;
	void		*collec;
	t_spirite	spirite;
	void		*player;
	void		*exit_cld;
	void		*ennemy_1;
	void		*ennemy_2;
	void		*ennemy_3;
	void		*ennemy_4;
	void		*spirite_1;
	void		*spirite_2;
	void		*spirite_3;
	void		*spirite_4;
	void		*spirite_5;
	void		*spirite_6;
	void		*spirite_7;
	void		*spirite_8;
	int			image_size;
	void		*mlx_image;
	int			move_count;
	int			win_heigth;
	int			win_length;
	void		*mlx_window;
	void		*exit_opened;
}	t_solong;

int		check_valid_path(t_solong **var);
void	is_free_position_for_enemy(t_solong *variable);
void	is_free_position_for_spirite(t_solong *variable);
void	ft_swap(char *a, char *b);
void	ft_move_enemy(t_solong *var);
char	*ft_strjoin_bonus(char *s1, char *s2);
void	ft_animate_enemy(t_solong *var);
void	ft_put_string_to_screen(t_solong *var);
void	error_msg(void);
void	ft_putnbr(int nbr);
void	ft_free(char **s);
int		ft_strlen(char *str);
char	*ft_strdup(char *s1);
char	*get_next_line(int fd);
char	*ft_strjoin_bonus(char *s1, char *s2);
char	*ft_itoa(int nbr);
void	write_moves_helper(t_solong *variable);
void	flood_fill(char **map, int x, int y);
int		ft_lookfor_newline(char *s);
char	**ft_split(char *s, char c);
int		calculate_length(char **map);
int		calculate_heigth(char **map);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strjoin(char *s1, char *s2);
char	**read_map_from_file(char *file);
int		is_valid_walls(t_solong *variable);
int		is_valid_rectangle(t_solong *variable);
int		is_valid_collectible(t_solong *variable);

int		key_hook_function(int key, void *program);
int		position_player(t_solong *variable, char flag);
void	ft_parse(int ac, char *file, t_solong *variable);

void	ft_free_map(t_solong **variable);
int		ft_animation(t_solong *variable);
void	move_to_up(t_solong *game);
void	move_to_down(t_solong *game);
void	move_to_right(t_solong *game);
void	move_to_left(t_solong *game);
void	fill_out_game(t_solong *variable);
void	full_fill_xpm_to_image(t_solong *var);
void	fill_out_image_to_window(t_solong *var, int i, int j);
void	show(void);
#endif
