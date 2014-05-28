/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspail <mgaspail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 16:20:49 by mgaspail          #+#    #+#             */
/*   Updated: 2014/01/18 20:16:17 by mgaspail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <math.h>

int			ft_put_p(t_data *e, int x, int y, int color[3])
{
	int		pos;

	pos = (y * e->w + x) * 4;
	e->i_data[pos++] = color[0];
	e->i_data[pos++] = color[1];
	e->i_data[pos] = color[2];
	return (0);
}

void		ft_put_floor(t_data *e, int sy, int x)
{
	int		y;
	int		color[3];

	color[0] = 0x55;
	color[1] = 0x7B;
	color[2] = 0x2;
	y = e->h - 1;
	while (y > sy)
		ft_put_p(e, x, y--, color);
}

void	ft_put_sky(t_data *e, int se, int x)
{
	int		y;
	int		color[3];

	color[0] = 0x7B;
	color[1] = 0x35;
	color[2] = 0x22;
	y = 0;
	while (y <= se)
		ft_put_p(e, x, y++, color);
}

void		ft_verline(t_data *e, int x, float y[2], int color)
{
	int		tab[3];

	tab[0] = (e->hit == 15 ? 0x25 : color % 65536);
	color -= tab[0] * 65536;
	tab[1] = (e->hit == 15 ? 0x25 : color % 256);
	color -= tab[1] * 256;
	tab[2] = (e->hit == 15 ? 0x25 : color);
	if (y[0] > y[1])
	{
		while (y[1] <= y[0])
			ft_put_p(e, x, y[1]++, tab);
	}
	else
	{
		while (y[1] >= y[0])
			ft_put_p(e, x, y[1]--, tab);
	}
}
