/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyrode <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 18:46:23 by atyrode           #+#    #+#             */
/*   Updated: 2016/09/08 19:11:58 by atyrode          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char *haystack, char *needle)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	if (needle[i] == '\0')
		return (haystack);
	while (haystack[i])
	{
		j = 1;
		k = 0;
		while (needle[k])
		{
			if (!(haystack[i + k] == needle[k]))
			{
				j = 0;
				break ;
			}
			k++;
		}
		if (j == 1)
			return (haystack + i);
		i++;
	}
	return (0);
}
