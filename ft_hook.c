/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspail <mgaspail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 14:35:04 by mgaspail          #+#    #+#             */
/*   Updated: 2014/01/18 20:12:18 by mgaspail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <time.h>
#include <math.h>
#include <unistd.h>
#include <stdlib.h>

void		ft_fps2(t_data *e, int *cnt)
{
	static long int		timer = 0;

	ft_print_wall(e);
	if (timer != time(NULL))
	{
		e->fps = *cnt;
		*cnt = 0;
		timer = time(NULL);
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	put_hud(e);
}

int			ft_fps(t_data *e)
{
	static int			cnt = 0;

	cnt++;
	if (e->mov & UP)
		move_line(e->dirx, e->diry, e);
	if (e->mov & BACK)
		move_line(-e->dirx, -e->diry, e);
	if (e->mov & LSTRAFE)
		move_line(-e->diry, e->dirx, e);
	if (e->mov & RSTRAFE)
		move_line(e->diry, -e->dirx, e);
	if (e->mov & RIGHT && !(e->mov & LEFT))
		rotate(-0.025, e->planex, e->dirx, e);
	if (e->mov & LEFT && !(e->mov & RIGHT))
		rotate(0.025, e->planex, e->dirx, e);
	if (e->mov & REDUC)
		distortion(e->planex, e->dirx, e);
	if (e->mov & HEADUP && e->up > -300)
		e->up -= 10;
	if (e->mov & HEADDOWN && e->up < 300)
		e->up += 10;
	ft_fps2(e, &cnt);
	return (0);
}

int			ft_key_hook(int keycode, t_data *e)
{
	if (keycode == 65307)
		exit(0);
	e->mov = (keycode == 65363 || keycode == 100 ? e->mov ^ RIGHT : e->mov);
	e->mov = (keycode == 65364 || keycode == 115 ? e->mov ^ BACK : e->mov);
	e->mov = (keycode == 65361 || keycode == 97 ? e->mov ^ LEFT : e->mov);
	e->mov = (keycode == 65362 || keycode == 119 ? e->mov ^ UP : e->mov);
	e->mov = (keycode == 113 ? e->mov ^ LSTRAFE : e->mov);
	e->mov = (keycode == 101 ? e->mov ^ RSTRAFE : e->mov);
	e->ghost = (keycode == 32 ? 1 : e->ghost);
	e->mov = (keycode == 114 ? e->mov ^ HEADUP : e->mov);
	e->mov = (keycode == 102 ? e->mov ^ HEADDOWN : e->mov);
	e->mov = (keycode == 65451 ? e->mov ^ REDUC : e->mov);
	if (keycode == 49)
		change_map(4, e);
	if (keycode == 50)
		change_map(1, e);
	if (keycode == 51)
		change_map(2, e);
	if (keycode == 52)
		change_map(3, e);
	return (0);
}

int			ft_key_release(int keycode, t_data *e)
{
	e->mov = (keycode == 65363 || keycode == 100 ? e->mov ^ RIGHT : e->mov);
	e->mov = (keycode == 65364 || keycode == 115 ? e->mov ^ BACK : e->mov);
	e->mov = (keycode == 65361 || keycode == 97 ? e->mov ^ LEFT : e->mov);
	e->mov = (keycode == 65362 || keycode == 119 ? e->mov ^ UP : e->mov);
	e->mov = (keycode == 113 ? e->mov ^ LSTRAFE : e->mov);
	e->mov = (keycode == 101 ? e->mov ^ RSTRAFE : e->mov);
	e->ghost = (keycode == 32 ? 0 : e->ghost);
	e->mov = (keycode == 114 ? e->mov ^ HEADUP : e->mov);
	e->mov = (keycode == 102 ? e->mov ^ HEADDOWN : e->mov);
	e->mov = (keycode == 65451 ? e->mov ^ REDUC : e->mov);
	e->pfps = (keycode == 104 ? -e->pfps : e->pfps);
	if (keycode == 65289)
		change_map(0, e);
	return (0);
}

int			ft_expose_hook(t_data *pic)
{
	int		i;

	i = mlx_put_image_to_window(pic->mlx, pic->win, pic->img, 0, 0);
	return (i);
}
