/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyrode <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 18:46:23 by atyrode           #+#    #+#             */
/*   Updated: 2016/09/08 19:11:58 by atyrode          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	int i;
	int n;

	n = 0;
	i = 0;
	while (1)
	{
		n += ((unsigned char)s1[i] - (unsigned char)s2[i]);
		if (s1[i] == '\0' && s2[i] == '\0')
			return (n);
		if ((unsigned char)s1[i] == (unsigned char)s2[i])
			i++;
		else
			return (n);
	}
}
