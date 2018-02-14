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

void draw_map(t_mlx *mlx, t_coord *coord0, t_coord *coord1)
{
	int y;
	int x;

	y = (coord1->crd.y - coord0->crd.y) < 0 ? -(coord1->crd.y - coord0->crd.y)
										: (coord0->crd.y - coord0->crd.y);
	x = (coord1->crd.x - coord0->crd.x) < 0 ? -(coord1->crd.x - coord0->crd.x)
										: (coord1->crd.x - coord0->crd.x);
	if (x > y)
	{
		if (coord0->crd.x > coord1->crd.x)
			draw_down(mlx, coord1->crd, coord0->crd);
		else
			draw_down(mlx, coord0->crd, coord1->crd);
	}
	else
	{
		if (coord0->crd.y > coord1->crd.y)
			draw_up(mlx, coord1->crd, coord0->crd);
		else
			draw_up(mlx, coord0->crd, coord1->crd);
	}
}

void	draw_down(t_mlx *mlx, t_xy c0, t_xy c1)
{
	int dx;
	int dy;
	int i;
	int D;

	dx = c1.x - c0.x;
	dy = c1.y - c0.y;
	i = 1;
	if (dy < 0)
	{
		i = -1;
		dy = -dy;
	}
	D = 2 * dy - dx;
	while (c0.x < c1.x)
	{
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, c0.x,
					  c0.y, mlx->color);
		if (D > 0)
		{
			c0.y = c0.y + i;
			D = D - 2 * dx;
		}
		D = D + 2 * dy;
		c0.x++;
		mlx->color--;
	}
}

void	draw_up(t_mlx *mlx, t_xy c0, t_xy c1)
{
	int dx;
	int dy;
	int i;
	int D;

	dx = c1.x - c0.x;
	dy = c1.y - c0.y;
	i = 1;
	if (dx < 0)
	{
		i = -1;
		dx = -dx;
	}
	D = 2 * dx - dy;
	while (c0.y < c1.y)
	{
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, c0.x,
					  c0.y, mlx->color);
		if (D > 0)
		{
			c0.x = c0.x + i;
			D = D - 2 * dy;
		}
		D = D + 2 * dx;
		c0.y++;
		mlx->color--;
	}
}
