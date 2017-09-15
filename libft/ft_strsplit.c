/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyrode <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 18:46:23 by atyrode           #+#    #+#             */
/*   Updated: 2016/09/08 19:11:58 by atyrode          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**alloc_table(char **table, const char *str, char c)
{
	int		i;
	int		n_words;

	i = 0;
	n_words = 0;
	while (str[i] == c)
		i++;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			n_words++;
			while (str[i] != c && str[i])
				i++;
		}
		else
			i++;
	}
	if (!(table = (char**)ft_memalloc(sizeof(char *) * (n_words + 1))))
		return (0);
	return (table);
}

static char	**alloc_words(char **table, const char *str, char c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i] == c)
		i++;
	while (str[i] != '\0')
	{
		i++;
		if (str[i] == c || !str[i])
		{
			if (!(table[j] = ft_strnew(k + 1)))
				return (0);
			j++;
			k = 0;
			while (str[i] == c)
				i++;
		}
		k++;
	}
	return (table);
}

static char	**fill_table(char **table, const char *str, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i] == c)
		i++;
	while (str[i] != '\0')
	{
		table[j][k] = str[i];
		i++;
		k++;
		if (str[i] == c || !str[i])
		{
			j++;
			k = 0;
			while (str[i] == c)
				i++;
		}
	}
	return (table);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**table;

	if (!s)
		return (NULL);
	table = 0;
	if (!(table = alloc_table(table, s, c)))
		return (0);
	if (!(table = alloc_words(table, s, c)))
		return (0);
	table = fill_table(table, s, c);
	return (table);
}
