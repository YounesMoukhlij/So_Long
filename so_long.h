/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:37:09 by youmoukh          #+#    #+#             */
/*   Updated: 2024/01/18 18:53:21 by youmoukh         ###   ########.fr       */
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

void	error_msg(void);
void	*ft_free(char **s);
int		ft_strlen(char *str);
char	*ft_strdup(char *s1);
char	*get_next_line(int fd);
int		is_rectangle(char **map);
int		ft_lookfor_newline(char *s);
char	**ft_split(char *s, char c);
int		ft_parse(int ac, char *file);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strjoin(char *s1, char *s2);
char	**read_map_from_file(char *file);

#endif
