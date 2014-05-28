/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspail <mgaspail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 15:32:40 by mgaspail          #+#    #+#             */
/*   Updated: 2014/01/18 20:08:39 by mgaspail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		put_hud(t_data *e)
{
	char	*str;

	if (e->pfps == 1)
	{
		mlx_string_put(e->mlx, e->win, 50, e->h - 40, 0x550033,"FPS :");
		str = ft_itoa(e->fps);
		mlx_string_put(e->mlx, e->win, 90, e->h - 40, 0x550033, str);
	}
}
