/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:37:09 by youmoukh          #+#    #+#             */
/*   Updated: 2024/01/24 20:13:13 by youmoukh         ###   ########.fr       */
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
# define BUFFER_SIZE 10
# define WINDOW_CLOSE 17
# define CL "icons/col.xpm"
# define WL "icons/wall.xpm"
# define FL "icons/floor.xpm"
# define PL "icons/player.xpm"
# define exit_open "icons/exit_open.xpm"
# define exit_closd "icons/exit_closed.xpm"

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
	t_player	player;
	int			collectible;
}	t_map;

typedef struct s_solong
{
	t_map	map;
	void	*mlx;
	void	*wall;
	void	*floor;
	void	*collec;
	void	*player;
	void	*exit_cld;
	int		image_size;
	void	*mlx_image;
	int		win_heigth;
	int		win_length;
	void	*mlx_window;
	void	*exit_opened;
}	t_solong;

void	error_msg(void);
void	*ft_free(char **s);
int		ft_strlen(char *str);
char	*ft_strdup(char *s1);
char	*get_next_line(int fd);
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

int		key_hook_function(int key, t_solong *variable);
int		position_player(t_solong *variable, char flag);
void	ft_parse(int ac, char *file, t_solong *variable);

void	fill_out_game(t_solong *variable);
void	full_fill_xpm_to_image(t_solong *var);
void	fill_out_image_to_window(t_solong *var, int i, int j);
#endif
