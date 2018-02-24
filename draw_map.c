/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 17:54:09 by vfil              #+#    #+#             */
/*   Updated: 2018/02/14 17:54:11 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_map(t_map mapp)
{
	int i;
	int j;

	i = 0;
	while (i < mapp.rows)
	{
		j = 0;
		while (j < mapp.columns - 1)
		{
			draw_line(mapp, mapp.map1[i][j], mapp.map1[i][j + 1]);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < mapp.rows - 1)
	{
		j = 0;
		while (j < mapp.columns)
		{
			draw_line(mapp, mapp.map1[i][j], mapp.map1[i + 1][j]);
			j++;
		}
		i++;
	}
}

void	draw_line(t_map mapp, t_coord c0, t_coord c1)
{
	double y;
	double x;

	y = c1.crd.y - c0.crd.y;
	y = y < 0 ? -y : y;
	x = c1.crd.x - c0.crd.x;
	x = x < 0 ? -x : x;
	if (x > y)
	{
		if (c0.crd.x > c1.crd.x)
			draw_down(mapp, c1.crd, c0.crd);
		else
			draw_down(mapp, c0.crd, c1.crd);
	}
	else
	{
		if (c0.crd.y > c1.crd.y)
			draw_up(mapp, c1.crd, c0.crd);
		else
			draw_up(mapp, c0.crd, c1.crd);
	}
}

void	draw_down(t_map mapp, t_xy c0, t_xy c1)
{
	int	dx;
	int	dy;
	int	i;
	int	d;

	dx = c1.x - c0.x;
	dy = c1.y - c0.y;
	i = 1;
	if (dy < 0)
	{
		i = -1;
		dy = -dy;
	}
	d = 2 * dy - dx;
	while (c0.x < c1.x)
	{
		put_pixel_to_image(&mapp, c0.x, c0.y, c0.color);
		if (d > 0)
		{
			c0.y = c0.y + i;
			d = d - 2 * dx;
		}
		d = d + 2 * dy;
		c0.x++;
	}
}

void	draw_up(t_map mapp, t_xy c0, t_xy c1)
{
	int dx;
	int dy;
	int i;
	int d;

	dx = c1.x - c0.x;
	dy = c1.y - c0.y;
	i = 1;
	if (dx < 0)
	{
		i = -1;
		dx = -dx;
	}
	d = 2 * dx - dy;
	while (c0.y < c1.y)
	{
		put_pixel_to_image(&mapp, c0.x, c0.y, c0.color);
		if (d > 0)
		{
			c0.x = c0.x + i;
			d = d - 2 * dy;
		}
		d = d + 2 * dx;
		c0.y++;
	}
}

void	put_pixel_to_image(t_map *mapp, int x, int y, int color)
{
	int *data;
	int bits_per_pixel;
	int size_line;
	int endian;

	data = (int *)mlx_get_data_addr(mapp->img_ptr, &bits_per_pixel, \
	&size_line, &endian);
	if (x < mapp->win_x && y < mapp->win_y && x > 0 && y > 0)
		data[x + y * size_line / 4] = color;
}
