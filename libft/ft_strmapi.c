/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyrode <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 18:46:23 by atyrode           #+#    #+#             */
/*   Updated: 2016/09/08 19:11:58 by atyrode          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	char	*new;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (s == NULL)
		return (0);
	if (!(new = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (0);
	while (s[i])
	{
		new[i] = f(j, s[j]);
		i++;
		j++;
	}
	new[i] = '\0';
	return (new);
}
