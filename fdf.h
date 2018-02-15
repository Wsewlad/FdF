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

#include "libft.h"
#include <mlx.h>

typedef struct	s_mod
{
	int 		strt_x;
	int 		strt_y;
	int 		nl;
	int 		altd;
}				t_mod;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	int 		color;
	int 		col;
	int			rows;
	int 		wind_x;
	int 		wind_y;
	char 		*map_name;
	t_mod		mod;
}				t_mlx;

typedef struct	s_xy
{
	int 		x;
	int 		y;
}				t_xy;

typedef struct	s_coord
{
	t_xy		crd;
}				t_coord;

void			draw_line(t_mlx *mlx, t_coord *coord0, t_coord *coord1);
void			draw_up(t_mlx *mlx, t_xy c0, t_xy c1);
void			draw_down(t_mlx *mlx, t_xy c0, t_xy c1);
t_coord			**parse_map(t_mlx *mlx);
void			draw_map(t_coord **map, t_mlx *mlx);

#endif