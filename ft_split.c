/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:17:40 by youmoukh          #+#    #+#             */
/*   Updated: 2024/01/18 16:57:00 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen_word(char *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

void	*ft_free(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

int	count_words(char *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			i++;
		while (*s && *s != c)
			s++;
	}
	return (i);
}

char	*ft_create(char *s, char c)
{
	char	*r;
	int		len;
	int		i;

	len = ft_strlen_word(s, c);
	i = 0;
	r = (char *)malloc(sizeof(char) * (len + 1));
	if (r == NULL)
		return (NULL);
	while (i < len)
	{
		r[i] = s[i];
		i++;
	}
	r[i] = '\0';
	return (r);
}

char	**ft_split(char *s, char c)
{
	int		i;
	char	**r;

	i = 0;
	r = (char **)malloc(sizeof(char *) * ((count_words(s, c) + 1)));
	if (!r)
		return (0);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			r[i++] = ft_create(s, c);
			// if (!r[i++])
			// {
			// 	ft_free(r);
			// 	return (NULL);
			// }
		}
		while (*s && *s != c)
			s++;
	}
	r[i] = 0;
	return (r);
}
