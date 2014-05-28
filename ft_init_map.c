/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspail <mgaspail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 15:40:51 by mgaspail          #+#    #+#             */
/*   Updated: 2014/01/18 15:45:13 by mgaspail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <stdlib.h>

void			ft_copy_tab(int **map, t_data *e)
{
	int			i;
	int			j;

	i = 0;
	e->map_1 = (int**)malloc(sizeof(e->map_1) * (26));
	while (i != 26)
	{
		j = 0;
		e->map_1[i] = (int*)malloc(sizeof(e->map_1) * (26));
		while (j != 26)
		{
			e->map_1[i][j] = map[i][j];
			j++;
		}
		i++;
	}
}

int				get_start_pos(int **map, t_data *e)
{
	int		i;
	int		j;

	i = 0;
	while (i < 26)
	{
		j = 0;
		while (j < 26)
		{
			if (map[i][j] == -3)
			{
				e->posx = i;
				e->posy = j;
			}
			j++;
		}
		i++;
	}
	return (0);
}

void			change_map(int override, t_data *e)
{
	static int	number = -1;

	number++;
	if (override != 0)
		number = override;
	if (e->map_1 != NULL)
		free(e->map_1);
	ft_copy_tab(e->map[number % 4], e);
	get_start_pos(e->map[number % 4], e);
	e->planex = 0;
	e->dirx = -1;
	e->diry = 0;
	e->planey = 0.66;
}
