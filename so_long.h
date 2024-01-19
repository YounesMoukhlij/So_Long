/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younesmoukhlij <younesmoukhlij@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:37:09 by youmoukh          #+#    #+#             */
/*   Updated: 2024/01/19 01:18:06 by younesmoukh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif


typedef struct	s_map
{
	int		exit;
	char	**map;
	int		player;
	int		collectible;
}	t_map;

typedef	struct s_solong
{
	t_map	map;
}	t_solong;

void	error_msg(void);
void	*ft_free(char **s);
int		ft_strlen(char *str);
char	*ft_strdup(char *s1);
char	*get_next_line(int fd);
int		is_valid_walls(char **map);
char	**ft_split(char *s, char c);
int		ft_lookfor_newline(char *s);
int		ft_parse(int ac, char *file);
int		ft_strcmp(char *s1, char *s2);
int		is_valid_rectangle(char **map);
char	*ft_strjoin(char *s1, char *s2);
int		is_valid_collectible(char **map);
char	**read_map_from_file(char *file);

#endif
