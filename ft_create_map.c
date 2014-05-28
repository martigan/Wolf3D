/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspail <mgaspail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 15:42:08 by mgaspail          #+#    #+#             */
/*   Updated: 2014/01/18 20:06:55 by mgaspail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

static int		*ft_create_line(char *str)
{
	int			*line;
	char		**tab;
	int			i;

	tab = ft_strsplit(str, ',');
	i = 0;
	while (tab[i])
		i++;
	if (!(line = (int *)malloc(sizeof(int) * (i + 1))))
		return (NULL);
	i = 0;
	while (tab[i])
	{
		line[i] = ft_atoi(tab[i]);
		i++;
	}
	return (line);
}

static int		**ft_create_tab(char **str)
{
	char		**tab_str;
	int			**tab;
	int			i;

	if (!(tab_str = ft_strsplit(*str, '\n')))
		return (NULL);
	free(*str);
	i = 0;
	while (tab_str[i])
		i++;
	if (!(tab = (int**)malloc(sizeof(int *) * (i + 1))))
		return (NULL);
	i = 0;
	while (tab_str[i])
	{
		if (!(tab[i] = ft_create_line(tab_str[i])))
			return (NULL);
		i++;
	}
	free(tab_str);
	tab[i] = NULL;
	return (tab);
}

void			ft_init_map(t_data *e)
{
	int			fd;
	char		*str;

	e->map = (int ***)malloc(sizeof(int**) * 4);
	fd = open("map0", O_RDONLY);
	ft_read_file(fd, &str);
	e->map[0] = ft_create_tab(&str);
	close(fd);
	fd = open("map1", O_RDONLY);
	ft_read_file(fd, &str);
	e->map[1] = ft_create_tab(&str);
	close(fd);
	fd = open("map2", O_RDONLY);
	ft_read_file(fd, &str);
	e->map[2] = ft_create_tab(&str);
	close(fd);
	fd = open("map3", O_RDONLY);
	ft_read_file(fd, &str);
	e->map[3] = ft_create_tab(&str);
	close(fd);
}
