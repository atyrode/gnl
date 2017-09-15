/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyrode <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 18:46:23 by atyrode           #+#    #+#             */
/*   Updated: 2016/11/28 07:56:47 by atyrode          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*tmp;
	int		i;
	int		str;
	int		j;

	if (!s)
		return (NULL);
	if (!*s)
		return (ft_strdup(""));
	i = 0;
	str = ft_strlen(s) - 1;
	while (s[str] == ' ' || s[str] == '\n' || s[str] == '\t')
		str--;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if ((unsigned long)i == (ft_strlen(s)))
		return (ft_strdup(""));
	if (!(tmp = ft_strnew((size_t)(str - i + 1))))
		return (0);
	j = 0;
	while (i <= str)
		tmp[j++] = s[i++];
	tmp[j] = '\0';
	return (tmp);
}
