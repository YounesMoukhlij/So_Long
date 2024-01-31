/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_from_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:14:52 by youmoukh          #+#    #+#             */
/*   Updated: 2024/01/31 19:35:17 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_check(char *str, int mode)
{
	if (mode == 0)
	{
		if ((str[0] == '\n' && str[1] == '\0') || str[0] == '\0')
		{
			write(2, "Error\n Map is not valid.", 24);
			free(str);
			exit(1);
		}
		if (str[ft_strlen(str)] == '\n')
		{
			write(2, "Error\n Map is not valid.", 24);
			free(str);
			exit(1);
		}
	}
	if (mode == 1)
	{
		if (str[ft_strlen(str) - 1] == '\n')
		{
			write(2, "Error\n Map is not valid.", 24);
			free(str);
			exit(1);
		}
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
		ft_check(r_f_g, 0);
		str = ft_strjoin(str, r_f_g);
		if (!str)
			return (free (str), free (r_f_g), NULL);
		free (r_f_g);
	}
	close(fd);
	ft_check(str, 1);
	return (tmp_str = ft_split(str, '\n'), free (str), tmp_str);
}
