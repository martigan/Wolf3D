/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspail <mgaspail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 14:35:57 by mgaspail          #+#    #+#             */
/*   Updated: 2014/01/18 19:14:18 by mgaspail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <math.h>
#include <string.h>
#include <unistd.h>

void		ft_ray_pos(t_data *e, int x)
{
	e->camx = 2 * x / (float)e->w - 1;
	e->rayposx = e->posx;
	e->rayposy = e->posy;
	e->raydirx = e->dirx + e->planex * e->camx;
	e->raydiry = e->diry + e->planey * e->camx;
}

void		ft_calc_dist(t_data *e)
{
	if (e->raydirx < 0)
	{
		e->stepx = -1;
		e->sdistx = (e->rayposx - e->mapx) * e->ddistx;
	}
	else
	{
		e->stepx = 1;
		e->sdistx = (e->mapx + 1.0 - e->rayposx) * e->ddistx;
	}
	if (e->raydiry < 0)
	{
		e->stepy = -1;
		e->sdisty = (e->rayposy - e->mapy) * e->ddisty;
	}
	else
	{
		e->stepy = 1;
		e->sdisty = (e->mapy + 1.0 - e->rayposy) * e->ddisty;
	}
}

void		ft_calc_hwall(t_data *e, int x)
{
	float		lineheight;
	float		sy[2];
	float		color;
	int			wallmod;

	wallmod = getwallmod(e);
	lineheight = fabs((e->h + wallmod) / e->wdist);
	sy[0] = -lineheight / 2 + e->h / 2 + e->up;
	if (sy[0] < 0)
		sy[0] = 0;
	sy[1] = lineheight / 2 + e->h / 2 + e->up - wallmod / e->wdist / 2;
	if (sy[1] >= e->h)
		sy[1] = e->h - 1;
	color = (e->stepx == 1 ? 0x0000FF : (0x0000FF / 2));
	if (e->side == 1)
		color = (e->stepy == 1 ? 0xFDBFB7 : (0xFDBFB7 / 2));
	ft_put_floor(e, sy[1], x);
	ft_put_sky(e, sy[0], x);
	ft_verline(e, x, sy, color);
}

void		ft_print_wall(t_data *e)
{
	float		x;

	ft_init_vec(e);
	x = 0;
	while (x < e->w)
	{
		ft_ray_pos(e, x);
		ft_init_dda(e);
		ft_calc_dist(e);
		ft_dda(e);
		ft_correct_feye(e);
		ft_calc_hwall(e, x);
		x++;
	}
}
