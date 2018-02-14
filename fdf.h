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

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	int 		color;
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

void			draw_map(t_mlx *mlx, t_coord *coord0, t_coord *coord1);
void			draw_up(t_mlx *mlx, t_xy c0, t_xy c1);
void			draw_down(t_mlx *mlx, t_xy c0, t_xy c1);
t_coord			**parse_map(char *name);
#endif