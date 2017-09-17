/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyrode <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 15:32:47 by atyrode           #+#    #+#             */
/*   Updated: 2017/09/17 15:33:56 by atyrode          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



int     get_next_line(const int fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	static char		*str = NULL;
	char			*tempbuff;
	char			tempbuff2[BUFF_SIZE + 1];
	int				ret;
	int				i;
	char			**tab_ret;
	int				test;
	int				testON;
	int				index;

	index = 0;
	test = 0;
	i = 0;
	testON = 1;
	if (str == NULL)
	{
		str = malloc(sizeof(char) * BUFF_SIZE + 1);
	}
	tempbuff = malloc (sizeof(char) * BUFF_SIZE + 1);
	ft_putstr("[str du debut = ");
	ft_putstr(str);
	ft_putstr("]\n");
	ft_putstr("buff size = ");
	ft_putnbr(BUFF_SIZE);
	ft_putstr("\n\n");
	ft_strclr(*line);
	ft_strcat(*line, str + 1);
	while (test == 0 && (ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		ft_putstr("(passage A)\n");
		ft_putstr("[ici, str = ");
		if (str != 0)
			ft_putstr(str);
		else
			ft_putstr("null");
		ft_putstr("]\n");
		ft_putstr("[ici, buff = ");
		ft_putstr(buff);
		ft_putstr("]\n");
		ft_strcat(buff, str);
		if ((tempbuff = ft_strchr(buff, '\n')))
		{
			str = ft_strdup(tempbuff);
			ft_putstr("(passage B)\n");
			if (!(tab_ret = ft_strsplit(buff, '\n')))
			{
				ft_putstr("(fini1) ");
				return (0);
			}
			test = 1;
			ft_putstr("test = 1\n");
			ft_putstr("[str (testy) = ");
			ft_putstr(str);
			ft_putstr("]\n");
			if (tab_ret[0] == 0 || buff[0] == '\n')
			{
				ft_putstr("(fini2)");
				ft_putstr("[str (fini2) = ");
				ft_putstr(str);
				ft_putstr("]\n");
				return (0);
			}
			ft_strcat(*line, tab_ret[0]);
			ft_putstr(tab_ret[0]);
			ft_putstr("\n");
		}
		else
		{
			ft_putstr("(passage D)\n");
			ft_putstr(buff);
			ft_putstr("\n");
			ft_strcat(*line, buff);
		}
	}
	if (ret == 0 && (str == 0 || (str[0] == '\n' && str[1] == '\0')))
	{
		ft_strclr(*line);
		return (0);
	}
	if (ret == 0 && str != 0)
	{
		tempbuff = ft_strchr(str, '\n');
		if (tempbuff[0] == '\n')
			str = ft_strchr(++str, '\n');
		ft_putstr("[final buff = ");
		ft_putstr(tempbuff);
		ft_putstr("]\n");
		tab_ret = ft_strsplit(tempbuff, '\n');
		ft_putstr("[final buff 2 = ");
		ft_putstr(tab_ret[0]);
		ft_putstr("]\n");
		*line = ft_strdup(tab_ret[0]);
		
	}
	ft_putstr("{ret = ");
	ft_putnbr(ret);
	ft_putstr("}\n");
	ft_putstr("(fini3) ");
	ft_putstr("\n[str = ");
	ft_putstr(str);
	ft_putstr("]\n");
	return (0);
}
