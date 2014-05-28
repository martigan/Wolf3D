/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_drw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspail <mgaspail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 16:18:30 by mgaspail          #+#    #+#             */
/*   Updated: 2014/01/18 18:08:00 by mgaspail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <math.h>

void		ft_init_dda(t_data *e)
{
	e->mapx = e->rayposx;
	e->mapy = e->rayposy;
	e->ddistx = sqrt(1 + (e->raydiry * e->raydiry)
			/ (e->raydirx * e->raydirx));
	e->ddisty = sqrt(1 + (e->raydirx * e->raydirx)
			/ (e->raydiry * e->raydiry));
	e->hit = 0;
}

void		ft_init_vec(t_data *e)
{
	e->albert = 1;
}

void		ft_dda(t_data *e)
{
	while (e->hit == 0)
	{
		if (e->sdistx < e->sdisty)
		{
			e->sdistx += e->ddistx;
			e->mapx += e->stepx;
			e->side = 0;
		}
		else
		{
			e->sdisty += e->ddisty;
			e->mapy += e->stepy;
			e->side = 1;
		}
		if (e->map_1[e->mapx][e->mapy] > 0)
			e->hit = e->map_1[e->mapx][e->mapy];
	}
}

void		ft_correct_feye(t_data *e)
{
	if (e->side == 0)
		e->wdist = fabs((e->mapx - e->rayposx + (1 - e->stepx) / 2)
				/ e->raydirx);
	else
		e->wdist = fabs((e->mapy - e->rayposy + (1 - e->stepy) / 2)
				/ e->raydiry);
}

int			getwallmod(t_data *e)
{
	int		wallmod;

	wallmod = 1;
	if (e->map_1[e->mapx][e->mapy] == 3)
		wallmod = 1000;
	if (e->map_1[e->mapx][e->mapy] >= 7 && e->map_1[e->mapx][e->mapy] < 10)
		wallmod = (e->map_1[e->mapx][e->mapy] - 5) * 1024;
	return (wallmod);
}
