/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_from_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:14:52 by youmoukh          #+#    #+#             */
/*   Updated: 2024/01/29 20:21:51 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_check(char *str)
{
	if ((str[0] == '\n' && str[1] == '\0') || str[0] == '\0')
		error_msg();
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
		printf("%s", r_f_g);
		str = ft_strjoin(str, r_f_g);
		if (!str)
			return (free (str), free (r_f_g), NULL);
		free (r_f_g);
	}
	close(fd);
	return (tmp_str = ft_split(str, '\n'), free (str), tmp_str);
}
