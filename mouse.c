/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspail <mgaspail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 16:19:20 by mgaspail          #+#    #+#             */
/*   Updated: 2014/01/18 19:30:51 by mgaspail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <math.h>

int					mouse_hook(int x, int y, t_data *d)
{
	static int		previousx = 0;
	static int		previousy = 0;

	if (previousx == 0 || fabs(x - previousx) >= 70)
		previousx = x;
	if (previousy == 0 || fabs(y - previousy) >= 70)
		previousy = y;
	if (previousx != x)
		rotate(-(((float)(x - previousx)) / 2) / 1000, d->planex, d->dirx, d);
	if (previousy != y)
	{
		if (d->up - y + previousy >= -300 && d->up - y + previousy <= 300)
			d->up -= y - previousy;
	}
	previousx = x;
	previousy = y;
	return (0);
}
