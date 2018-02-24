/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 20:19:58 by vfil              #+#    #+#             */
/*   Updated: 2018/02/12 20:19:59 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include <mlx.h>
# include <math.h>
# include <locale.h>

typedef struct	s_xy
{
	double		x;
	double		y;
	double		z;
	int			color;
}				t_xy;

typedef struct	s_coord
{
	t_xy		crd;
}				t_coord;

typedef struct	s_map
{
	int			win_x;
	int			win_y;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			rows;
	int			columns;
	int			scale;
	int			start_x;
	int			start_y;
	double		x;
	double		y;
	double		z;
	t_coord		**map0;
	t_coord		**map1;
	int			is_color;
}				t_map;

void			change_param(int key, t_map *mapp);
void			change_param_helper(int key, t_map *mapp);
void			map_init(t_map *mapp);
void			manage(t_map *mapp);
void			parse_map(t_map *mapp, char *name);
void			copy_map(t_map *mapp);
void			rotate_x(t_map *mapp);
void			rotate_y(t_map *mapp);
void			shift_to(t_map *mapp);
void			shift_from(t_map *mapp);
void			center(t_map *mapp);
void			del_map(t_map mapp, t_coord **map);
void			scale_map(t_map *mapp);
void			normalize(t_map *mapp);
void			put_pixel_to_image(t_map *mapp, int x, \
									int y, int color);
void			draw_map(t_map mapp);
void			draw_line(t_map mapp, t_coord c0, t_coord c1);
void			draw_up(t_map mapp, t_xy c0, t_xy c1);
void			draw_down(t_map mapp, t_xy c0, t_xy c1);
void			put_controls(t_map *mapp);
int				exit_x(void *par);
void			put_keys(int key);

#endif
