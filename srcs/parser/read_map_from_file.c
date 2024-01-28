/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_from_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younesmoukhlij <younesmoukhlij@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:43:37 by youmoukh          #+#    #+#             */
/*   Updated: 2024/01/27 00:03:06 by younesmoukh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_check(char *str)
{
	static int	i;
	int			x;

	x = 0;
	if (str[0] == '\n' && str[1] == '\0')
		exit(1);
	while (str[x] && str[x] != '\n')
	{
		if (str[x] == '1' && str[x] != '\n')
		{
			i++;
			x++;
		}
		else
		{
			i = 0;
			return ;
		}
	}
	if (x == ft_strlen(str) - 1 && i != x)
	{
		exit(1);
	}
}

char	**read_map_from_file(char *file)
{
	int		fd;
	char	*str;
	char	*r_f_g;
	char	**tmp_str;

	str = ft_strdup("");
	fd = open(file, O_RDONLY);
	while (1)
	{
		r_f_g = get_next_line(fd);
		if (r_f_g == NULL)
			break ;
		ft_check(r_f_g);
		str = ft_strjoin(str, r_f_g);
		if (!str)
			return (free (str), free (r_f_g), NULL);
		free (r_f_g);
	}
	close(fd);
	if (str[0] == '\0')
		error_msg();
	return (tmp_str = ft_split(str, '\n'), free (str), tmp_str);
}
