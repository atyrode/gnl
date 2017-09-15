/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyrode <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 18:46:23 by atyrode           #+#    #+#             */
/*   Updated: 2016/09/08 19:11:58 by atyrode          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *haystack, char *needle, size_t len)
{
	size_t		vars[3];

	vars[0] = 0;
	if (needle[vars[0]] == '\0')
		return (haystack);
	while (haystack[vars[0]])
	{
		vars[2] = 1;
		vars[1] = 0;
		while (needle[vars[1]])
		{
			if (vars[1] + vars[0] >= len)
				return (0);
			if (!(haystack[vars[0] + vars[1]] == needle[vars[1]]))
			{
				vars[2] = 0;
				break ;
			}
			vars[1]++;
		}
		if (vars[2] == 1)
			return (haystack + vars[0]);
		vars[0]++;
	}
	return (0);
}
