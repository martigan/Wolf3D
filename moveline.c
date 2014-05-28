/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspail <mgaspail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 16:19:55 by mgaspail          #+#    #+#             */
/*   Updated: 2014/01/18 19:24:07 by mgaspail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <math.h>

static int	ghost(float dirx, float diry, t_data *e)
{
	if (e->map_1[(int)(e->posx + dirx * 0.1)][(int)(e->posy + diry * 0.1)]
			!= 10 && e->ghost == 1)
		return (1);
	return (0);
}

void		move_line(float dirx, float diry, t_data *e)
{
	if (e->map_1[(int)(e->posx + dirx * 0.10)][(int)e->posy] < 1
		|| ghost(dirx, 0, e))
		e->posx += dirx * 0.05;
	if (e->map_1[(int)e->posx][(int)(e->posy + diry * 0.10)] < 1
		|| ghost(0, diry, e))
		e->posy += diry * 0.05;
	if (e->map_1[(int)(e->posx + dirx * 0.10)]
		[(int)(e->posy + diry * 0.10)] == 15 && e->ghost == 0)
		change_map(0, e);
}

void		rotate(float angle, float oldplanex, float olddirx, t_data *e)
{
	e->dirx = e->dirx * cos(angle) - e->diry * sin(angle);
	e->diry = olddirx * sin(angle) + e->diry * cos(angle);
	e->planex = e->planex * cos(angle) - e->planey * sin(angle);
	e->planey = oldplanex * sin(angle) + e->planey * cos(angle);
}

void		distortion(float oldplanex, float olddirx, t_data *d)
{
		d->dirx = d->dirx * cos(-0.05) - d->diry * sin(-0.025);
		d->diry = olddirx * sin(-0.05) + d->diry * cos(-0.025);
		d->planex = d->planex * cos(-0.05) - d->planey * sin(-0.025);
		d->planey = oldplanex * sin(-0.05) + d->planey * cos(-0.025);
		d->dirx = d->dirx * cos(0.05) - d->diry * sin(0.025);
		d->diry = olddirx * sin(0.05) + d->diry * cos(0.025);
		d->planex = d->planex * cos(0.05) - d->planey * sin(0.025);
		d->planey = oldplanex * sin(0.05) + d->planey * cos(0.025);
}
