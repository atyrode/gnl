/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyrode <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 18:46:23 by atyrode           #+#    #+#             */
/*   Updated: 2016/11/28 07:57:41 by atyrode          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*source2;
	unsigned char	*source1;

	source1 = (unsigned char *)s1;
	source2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (source1[i] == source2[i])
	{
		i++;
		if (i == n)
			return (0);
	}
	return (source1[i] - source2[i]);
}
