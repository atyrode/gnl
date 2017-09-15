/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyrode <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 18:46:23 by atyrode           #+#    #+#             */
/*   Updated: 2016/09/08 19:11:58 by atyrode          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t		i;

	i = 0;
	if (n == 0)
		return (1);
	if (s1 == NULL || s2 == NULL)
		return (0);
	if (s1[i] == '\0' && s2[i] == '\0')
		return (1);
	while (s1[i] == s2[i])
	{
		if ((s1[i] == '\0' && s2[i] == '\0') || i >= (n - 1))
			return (1);
		i++;
	}
	return (0);
}
