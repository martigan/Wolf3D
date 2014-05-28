/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspail <mgaspail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 16:19:05 by mgaspail          #+#    #+#             */
/*   Updated: 2014/01/18 20:20:43 by mgaspail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <unistd.h>

static void		init_data(t_data *d)
{
	d->w = 1024;
	d->h = 748;
	d->dirx = -1;
	d->diry = 0;
	d->up = 0;
	d->planex = 0;
	d->pfps = 1;
	d->ghost = 0;
	d->planey = 0.66;
	d->albert = 0;
	d->mov = 0;
	d->map_1 = NULL;
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, d->w, d->h, "HONEY BADGER 3D");
	d->img = mlx_new_image(d->mlx, d->w, d->h);
	d->i_data = mlx_get_data_addr(d->img, &d->bpp, &d->size_l, &d->endian);
}

int				main()
{
	t_data		d;

	init_data(&d);
	mlx_hook(d.win, 1, (1L << 0), &ft_key_hook, &d);
	ft_init_map(&d);
	change_map(0, &d);
	ft_print_wall(&d);
	mlx_do_key_autorepeatoff(d.mlx);
	mlx_hook(d.win, 6, (1L<<6), mouse_hook, &d);
	mlx_hook(d.win, 2, 2, ft_key_hook, &d);
	mlx_hook(d.win, 3, 3, ft_key_release, &d);
	mlx_expose_hook(d.win, ft_expose_hook, &d);
	mlx_loop_hook(d.mlx, ft_fps, &d);
	mlx_loop(d.mlx);
	return (0);
}
