/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bunus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 16:46:18 by vfil              #+#    #+#             */
/*   Updated: 2018/02/24 16:31:58 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_controls_helper(t_map *mapp)
{
	mlx_string_put(mapp->mlx_ptr, mapp->win_ptr, mapp->win_x - 900, \
	mapp->win_y - 250 + 25, 0xE4CFA6, "CHANGE COLOR (random)");
	mlx_string_put(mapp->mlx_ptr, mapp->win_ptr, mapp->win_x - 900, \
	mapp->win_y - 250 + 60, 0xE4CFA6, "       SPACE");
	mlx_string_put(mapp->mlx_ptr, mapp->win_ptr, mapp->win_x - 600, \
	mapp->win_y - 250 + 25, 0xE4CFA6, "MOVE IMG (arrows)");
	mlx_string_put(mapp->mlx_ptr, mapp->win_ptr, mapp->win_x - 600, \
	mapp->win_y - 250 + 60, 0xE4CFA6, "        UP");
	mlx_string_put(mapp->mlx_ptr, mapp->win_ptr, mapp->win_x - 600, \
	mapp->win_y - 250 + 85, 0xE4CFA6, "  LEFT      RIGHT");
	mlx_string_put(mapp->mlx_ptr, mapp->win_ptr, mapp->win_x - 600, \
	mapp->win_y - 250 + 110, 0xE4CFA6, "       DOWN");
}

void	put_controls(t_map *mapp)
{
	mlx_string_put(mapp->mlx_ptr, mapp->win_ptr, mapp->win_x - 140, \
	mapp->win_y - 225, 0xE4CFA6, "    ALTD");
	mlx_string_put(mapp->mlx_ptr, mapp->win_ptr, mapp->win_x - 140, \
	mapp->win_y - 200, 0xE4CFA6, "    /  *");
	mlx_string_put(mapp->mlx_ptr, mapp->win_ptr, mapp->win_x - 100, \
	mapp->win_y - 165, 0xE4CFA6, "ZOOM");
	mlx_string_put(mapp->mlx_ptr, mapp->win_ptr, mapp->win_x - 100, \
	mapp->win_y - 140, 0xE4CFA6, "  -");
	mlx_string_put(mapp->mlx_ptr, mapp->win_ptr, mapp->win_x - 100, \
	mapp->win_y - 115, 0xE4CFA6, "  +");
	mlx_string_put(mapp->mlx_ptr, mapp->win_ptr, mapp->win_x - 350, \
	mapp->win_y - 270, 0xE4CFA6, " ROTATE IMG (numpad)");
	mlx_string_put(mapp->mlx_ptr, mapp->win_ptr, mapp->win_x - 350, \
	mapp->win_y - 250 + 25, 0xE4CFA6, "         UP");
	mlx_string_put(mapp->mlx_ptr, mapp->win_ptr, mapp->win_x - 350, \
	mapp->win_y - 250 + 60, 0xE4CFA6, "         8");
	mlx_string_put(mapp->mlx_ptr, mapp->win_ptr, mapp->win_x - 350, \
	mapp->win_y - 250 + 85, 0xE4CFA6, "LEFT  4     6  RIGHT");
	mlx_string_put(mapp->mlx_ptr, mapp->win_ptr, mapp->win_x - 350, \
	mapp->win_y - 250 + 110, 0xE4CFA6, "         2");
	mlx_string_put(mapp->mlx_ptr, mapp->win_ptr, mapp->win_x - 350, \
	mapp->win_y - 250 + 145, 0xE4CFA6, "        DOWN");
	put_controls_helper(mapp);
}

int		exit_x(void *par)
{
	par = NULL;
	exit(1);
	return (0);
}

void	put_keys_help(int key)
{
	if (key == 123)
		ft_printf("{mag}MOVE {bld}LEFT{eoc}\n");
	else if (key == 124)
		ft_printf("{cyn}MOVE {bld}RIGHT{eoc}\n");
	else
		ft_printf("{red}%d{eoc}\n", key);
}

void	put_keys(int key)
{
	if (key == 53)
		ft_printf("{red}{bld}ESCAPE{eoc}\n");
	if (key == 69)
		ft_printf("{blu}SCALE +{eoc}\n");
	else if (key == 78)
		ft_printf("{yel}SCALE -{eoc}\n");
	else if (key == 84)
		ft_printf("{yel}ROTATE {bld}DOWN{eoc}\n");
	else if (key == 91)
		ft_printf("{blu}ROTATE {bld}UP{eoc}\n");
	else if (key == 88)
		ft_printf("{cyn}ROTATE {bld}RIGHT{eoc}\n");
	else if (key == 86)
		ft_printf("{mag}ROTATE {bld}LEFT{eoc}\n");
	else if (key == 67)
		ft_printf("{blu}ALITUDE +{eoc}\n");
	else if (key == 75)
		ft_printf("{yel}ALITUDE -{eoc}\n");
	else if (key == 126)
		ft_printf("{blu}MOVE {bld}UP{eoc}\n");
	else if (key == 125)
		ft_printf("{yel}MOVE {bld}DOWN{eoc}\n");
	else
		put_keys_help(key);
}
