/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 21:49:23 by vfil              #+#    #+#             */
/*   Updated: 2018/02/21 21:49:26 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	shift_to(t_map *mapp)
{
	int i;
	int j;

	i = 0;
	while (i < mapp->rows)
	{
		j = 0;
		while (j < mapp->columns)
		{
			mapp->map1[i][j].crd.x -= mapp->columns / 2;
			mapp->map1[i][j].crd.y -= mapp->rows / 2;
			j++;
		}
		i++;
	}
}

void	shift_from(t_map *mapp)
{
	int i;
	int j;

	i = 0;
	while (i < mapp->rows)
	{
		j = 0;
		while (j < mapp->columns)
		{
			mapp->map1[i][j].crd.x += mapp->columns / 2;
			mapp->map1[i][j].crd.y += mapp->rows / 2;
			j++;
		}
		i++;
	}
}
