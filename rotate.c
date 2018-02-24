/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 21:33:58 by vfil              #+#    #+#             */
/*   Updated: 2018/02/21 21:34:00 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(t_map *mapp)
{
	int i;
	int j;

	i = 0;
	while (i < mapp->rows)
	{
		j = 0;
		while (j < mapp->columns)
		{
			mapp->map1[i][j].crd.x = mapp->map1[i][j].crd.x;
			mapp->map1[i][j].crd.y = mapp->map1[i][j].crd.y * cos(mapp->x) +
					mapp->map1[i][j].crd.z * sin(mapp->x);
			mapp->map1[i][j].crd.z = -(mapp->map1[i][j].crd.y) * sin(mapp->x) +
					mapp->map1[i][j].crd.z * cos(mapp->x);
			j++;
		}
		i++;
	}
}

void	rotate_y(t_map *mapp)
{
	int i;
	int j;

	i = 0;
	while (i < mapp->rows)
	{
		j = 0;
		while (j < mapp->columns)
		{
			mapp->map1[i][j].crd.x = mapp->map1[i][j].crd.x * cos(mapp->y) +
					mapp->map1[i][j].crd.z * sin(mapp->y);
			mapp->map1[i][j].crd.y = mapp->map1[i][j].crd.y;
			mapp->map1[i][j].crd.z = -(mapp->map1[i][j].crd.x) * sin(mapp->y) +
					mapp->map1[i][j].crd.z * cos(mapp->y);
			j++;
		}
		i++;
	}
}
