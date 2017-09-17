/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyrode <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 15:32:47 by atyrode           #+#    #+#             */
/*   Updated: 2017/09/17 16:51:21 by atyrode          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int     get_next_line(const int fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	static	char	*str = NULL;
	int				ret;
	char			**tab_ret;
	char			*tempstr;
	int				yes;

	yes = 1;
	ft_strclr(*line);
	if (str == NULL)
		str = malloc(sizeof(char) * BUFF_SIZE + 1);
	else
	{
		ft_putstr("\n[");
		ft_putstr(str);
		ft_putstr("]\n");
		if (!(ft_strchr(str + 1, '\n')))
		{
			ft_strcat(*line, str + 1);
			ft_putstr("yes == 1\n");
		}
		else if (str[0] == '\n' && str[1] != '\0')
		{
			tab_ret = ft_strsplit(str + 1, '\n');
			str = ft_strchr(str + 1, '\n');
			ft_strcat(*line, tab_ret[0]);
			yes = 0;
		}
	}
	tempstr = malloc(sizeof(char) * BUFF_SIZE + 1);
	ret = read(fd, buff, BUFF_SIZE);
	buff[ret] = '\0';
	ft_putstr("[buff = ");
	ft_putstr(buff);
	ft_putstr("]\n");
	ft_strcat(str, buff);
	if (ret == 0)
		ft_putstr("ret == 0\n");
	else
		if (yes == 1 && (tempstr = ft_strchr(buff, '\n')))
		{
			str = ft_strdup(tempstr);
			tab_ret = ft_strsplit(buff, '\n');
			ft_strcat(*line, tab_ret[0]);
		}
	ft_putstr("[");
	ft_putstr(str);
	ft_putstr("]\n");
	return (0);
}
