/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_functions_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:14:26 by youmoukh          #+#    #+#             */
/*   Updated: 2024/01/29 15:14:29 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	count_length(long n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count++;
		n *= -1;
	}
	if (n == 0)
		count++;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int nbr)
{
	long	n;
	char	*s;
	int		len;

	n = (long)nbr;
	len = count_length(n);
	s = malloc(sizeof(char) * len + 1);
	if (!s)
		return (NULL);
	s[len--] = '\0';
	if (n < 0)
	{
		n *= -1;
		s[0] = '-';
	}
	if (n == 0)
		s[0] = '0';
	while (n)
	{
		s[len--] = ((n % 10) + 48);
		n /= 10;
	}
	return (s);
}

char	*ft_strjoin_bonus(char *s1, char *s2)
{
	char	*r;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	r = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!r)
		return (free(s1), s1 = NULL, NULL);
	while (s1[j])
		r[i++] = s1[j++];
	j = 0;
	while (s2[j])
		r[i++] = s2[j++];
	r[i] = '\0';
	free (s2);
	return (r);
}

void	ft_destroy(t_solong *variable, int mode)
{
	ft_free_map(&variable);
	mlx_destroy_window(variable->mlx, variable->mlx_window);
	if (mode == 1)
		exit(1);
	else
		exit(0);
}
