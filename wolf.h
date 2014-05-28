/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconraux <mconraux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 14:41:16 by mconraux          #+#    #+#             */
/*   Updated: 2014/01/18 18:55:21 by mgaspail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _WOLF_H_
# define _WOLF_H_

# include "libft/libft.h"
# include <mlx.h>

# define LEFT 1
# define UP 2
# define RIGHT 4
# define BACK 8
# define LSTRAFE 16
# define RSTRAFE 32
# define HEADUP 64
# define HEADDOWN 128
# define REDUC 256
# define BIGGA 512

typedef struct	s_back
{
	void		*img_ptr;
	int			bpp;
	int			size_l;
	int			endian;
	int			x;
	int			y;
	char		*data;
}				t_back;

typedef struct	s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*i_data;
	int			bpp;
	int			size_l;
	int			endian;
	int			albert;
	int			w;
	int			h;
	int			indice;
	char		*beg_str;
	int			**map_1;
	int			mapx;
	int			mapy;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	float		sdistx;
	float		sdisty;
	float		ddistx;
	float		ddisty;
	float		wdist;
	float		posx;
	float		posy;
	float		dirx;
	float		diry;
	float		planex;
	float		planey;
	float		camx;
	float		rayposx;
	float		rayposy;
	float		raydirx;
	float		raydiry;
	int			mov;
	int			up;
	int			ghost;
	int			fps;
	int			pfps;
	int			***map;
}				t_data;

void		ft_init_map(t_data *e);
void		change_map(int override, t_data *e);
int			get_start_pos(int **map, t_data *e);
void		ft_copy_tab(int **map, t_data *e);
int			ft_get_key(int keycode, t_data *e);
int			ft_key_hook(int keycode, t_data *e);
int			mouse_hook(int x, int y, t_data *e);
void		move_line(float dirx, float diry, t_data *e);
void		rotate(float angle, float oldplanex, float olddirx, t_data *e);
void		distortion(float oldplanex, float olddirx, t_data *e);
int			ft_fps(t_data *e);
void		ft_print_wall(t_data *e);
float		ft_sqrt(float nbr);
float		ft_fabs(float nbr);
int			ft_abs(int nbr);
int			ft_put_p(t_data *e, int x, int y, int color[3]);
void		ft_verline(t_data *e, int x, float y[2], int color);
void		ft_init_vec(t_data *e);
void		ft_init_dda(t_data *e);
void		ft_ray_post(t_data *e);
void		ft_calc_dist(t_data *e);
void		ft_correct_feye(t_data *e);
int			ft_expose_hook(t_data *e);
int			ft_key_release(int keycode, t_data *e);
/*
** Calculus stuff
*/
void		ft_dda(t_data *e);
int			getwallmod(t_data *e);

/*
** pixel stuff
*/
void		put_hud(t_data *e);
void		ft_put_floor(t_data *e, int sy, int x);
void		ft_put_sky(t_data *e, int se, int x);

#endif /* _WOLF_H_ */
