/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:37:09 by youmoukh          #+#    #+#             */
/*   Updated: 2024/01/31 19:16:41 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>

# define SIZE 50
# define SKEY_D 1
# define SKEY_L 0
# define SKEY_R 2
# define SKEY_U 13
# define SKEY_ESC 53
# define BUFFER_SIZE 1
# define WINDOW_CLOSE 17
# define CL "textures/coin.xpm"
# define EN_1 "textures/1.xpm"
# define EN_2 "textures/2.xpm"
# define EN_3 "textures/3.xpm"
# define WL "textures/wall.xpm"
# define FL "textures/floor.xpm"
# define PL "textures/player.xpm"
# define EXIT_OPEN "textures/exit_open.xpm"
# define EXIT_CLOSED "textures/exit_closed.xpm"

typedef struct s_player
{
	int		x;
	int		y;
	int		player;
}	t_player;

typedef struct s_map
{
	int			exit;
	char		**map;
	int			exit_x;
	int			exit_y;
	t_player	player;
	int			collectible;
}	t_map;

typedef struct s_solong
{
	t_map		map;
	void		*mlx;
	void		*wall;
	void		*floor;
	void		*collec;
	void		*player;
	void		*exit_cld;
	int			image_size;
	void		*mlx_image;
	int			move_count;
	int			win_heigth;
	int			win_length;
	void		*mlx_window;
	void		*exit_opened;
}	t_solong;

char	*ft_itoa(int nbr);
void	ft_free(char **s);
void	ft_putnbr(int nbr);
int		ft_strlen(char *str);
char	*ft_strdup(char *s1);
char	*get_next_line(int fd);
void	ft_swap(char *a, char *b);
void	error_message(t_solong *var, int mode);
int		exit_game(void *program);
void	fill_out_variables(t_solong *variable);
void	ft_move_helper(t_solong *var, int mode);
void	ft_destroy(t_solong *variable, int mode);
int		check_valid_path(t_solong *var);
void	write_moves_helper(t_solong *variable);
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
void	position_player(t_solong *variable);
void	position_exit(t_solong *variable);
void	ft_parse(int ac, char *file, t_solong *var);
void	ft_free_map(t_solong **variable);
int		ft_animation(t_solong *variable);
void	move_to_up(t_solong *game);
void	move_to_down(t_solong *game);
void	move_to_right(t_solong *game);
void	move_to_left(t_solong *game);
void	fill_out_game(t_solong *variable);
void	full_fill_xpm_to_image(t_solong *var);
void	show(void);
#endif
