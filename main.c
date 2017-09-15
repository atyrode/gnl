/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyrode <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 12:52:52 by atyrode           #+#    #+#             */
/*   Updated: 2017/09/15 15:53:36 by atyrode          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int		get_next_line(const int fd, char **line);

int		main(int argc, const char **argv)
{
	char *line;
	int fd;
	int	test;

	line = NULL;
	test = 1;
	if (argc >= 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			return (0);
		/*
		   while (get_next_line(fd, &line) == 1)
		   {
		   ft_putendl(line);
		   free(line);
		   line = NULL;
		   }
		   */
		while (test <= 4)
		{
			ft_putstr("-----------------------\n");
			ft_putstr("appel de la fonction numero : ");
			ft_putnbr(test);
			ft_putstr("\n[malloc line]\n");
			line = malloc(sizeof(char) * (BUFF_SIZE +1));
			get_next_line(fd, &line);
			if (line)
			{
				ft_putstr("\n\n::: line = ");
				ft_putstr(line);
				ft_putstr(" :::\n");
				
			}
			ft_putstr("[free line]\n\n");
			free(line);
			test++;
		}
		/*
		   printf("%s", line);
		   free(line);
		   */
	}
	return (0);
}
