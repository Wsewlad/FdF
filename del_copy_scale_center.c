/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_copy_scale_center.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 21:59:28 by vfil              #+#    #+#             */
/*   Updated: 2018/02/21 21:59:30 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	del_map(t_map mapp, t_coord **map)
{
	int i;

	i = 0;
	while (i < mapp.rows)
		free(map[i++]);
	free(map);
}

void	copy_map(t_map *mapp)
{
	int i;
	int j;

	i = 0;
	mapp->map1 = (t_coord**)malloc(sizeof(t_coord*) * (mapp->rows));
	while (i < mapp->rows)
	{
		mapp->map1[i] = (t_coord*)malloc(sizeof(t_coord) * (mapp->columns));
		j = 0;
		while (j < mapp->columns)
		{
			mapp->map1[i][j].crd.x = mapp->map0[i][j].crd.x;
			mapp->map1[i][j].crd.y = mapp->map0[i][j].crd.y;
			mapp->map1[i][j].crd.z = mapp->map0[i][j].crd.z;
			mapp->map1[i][j].crd.color = mapp->map0[i][j].crd.color \
										+ mapp->is_color;
			mapp->map1[i][j].crd.x += mapp->map1[i][j].crd.z * -mapp->z;
			mapp->map1[i][j].crd.y += mapp->map1[i][j].crd.z * -mapp->z;
			j++;
		}
		i++;
	}
}

void	scale_map(t_map *mapp)
{
	int i;
	int j;

	i = 0;
	while (i < mapp->rows)
	{
		j = 0;
		while (j < mapp->columns)
		{
			mapp->map1[i][j].crd.x *= mapp->scale;
			mapp->map1[i][j].crd.y *= mapp->scale;
			j++;
		}
		i++;
	}
}

void	normalize(t_map *mapp)
{
	int	w_x;
	int	w_y;

	w_x = mapp->start_x + mapp->columns * mapp->scale;
	w_y = mapp->start_y + mapp->rows * mapp->scale;
	while (w_x >= mapp->win_x - 50 || w_y >= mapp->win_y - 50)
	{
		mapp->scale--;
		w_x = mapp->start_x + mapp->columns * mapp->scale;
		w_y = mapp->start_y + mapp->rows * mapp->scale;
	}
}

void	center(t_map *mapp)
{
	int i;
	int j;
	int x;
	int y;

	x = (mapp->win_x - mapp->columns * mapp->scale) / 2;
	y = (mapp->win_y - mapp->rows * mapp->scale) / 2;
	i = 0;
	while (i < mapp->rows)
	{
		j = 0;
		while (j < mapp->columns)
		{
			mapp->map1[i][j].crd.x += x + mapp->start_x;
			mapp->map1[i][j].crd.y += y + mapp->start_y;
			j++;
		}
		i++;
	}
}
