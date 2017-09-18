/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyrode <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 13:19:20 by atyrode           #+#    #+#             */
/*   Updated: 2017/09/18 13:41:03 by atyrode          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				get_next_line(const int fd, char **line)
{
	char		*buff;
	static char	*str = NULL;
	int			ret;
	char		**tab_ret;
	char		*tempstr;
	int			yes;
	int			test;
	int			fl;

	test = 0;
	yes = 1;
	fl = 0;
	ft_strclr(*line);
	if (fd < 0)
		return (-1);
	buff = malloc(sizeof(char) * BUFF_SIZE + 1);
	if (str == NULL)
	{
		str = malloc(sizeof(char) * BUFF_SIZE + 1);
		*line = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
		fl = 1;
	}
	else
	{
		if (str[0] == '\n' && str[1] == '\n')
			str++;
		if (!(ft_strchr(str + 1, '\n')))
			ft_strcat(*line, str + 1);
		else if (str[0] == '\n' && str[1] != '\0' && str[1] != '\n')
		{
			tab_ret = ft_strsplit(str + 1, '\n');
			str = ft_strchr(str + 1, '\n');
			ft_strcat(*line, tab_ret[0]);
			yes = 0;
		}
	}
	tempstr = malloc(sizeof(char) * BUFF_SIZE + 1);
	while ((ret = read(fd, buff, BUFF_SIZE)) && (!(ft_strchr(buff, '\n'))))
	{
		if (ret < 0)
			return (-1);
		buff[ret] = '\0';
		ft_strcat(*line, buff);
	}
	if (ret == 0 && str[0] == '\0' && fl == 0)
	{
		free(str);
		return (0);
	}
	ft_strcat(str, buff);
	if (ret == 0 && ((str[0] == '\0') || (str[0] == '\n' && str[1] == '\0')))
		return (0);
	else if (yes == 1 && (tempstr = ft_strchr(buff, '\n')))
	{
		str = ft_strdup(tempstr);
		tab_ret = ft_strsplit(buff, '\n');
		if (buff[0] != '\n')
			ft_strcat(*line, tab_ret[0]);
		return (1);
	}
	free(buff);
	if ((!(ft_strchr(str + 1, '\n'))) && (ft_strchr(str, '\0')))
	{
		ft_strclr(str);
		return (1);
	}
	return (0);
}
