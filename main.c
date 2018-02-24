/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 16:43:41 by vfil              #+#    #+#             */
/*   Updated: 2018/02/24 16:58:00 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	change_param(int key, t_map *mapp)
{
	if (key == 69)
		mapp->scale++;
	else if (key == 78)
		mapp->scale = mapp->scale > 0 ? mapp->scale - 1 : 0;
	else if (key == 84)
		mapp->x += 0.1;
	else if (key == 91)
		mapp->x -= 0.1;
	else if (key == 88)
		mapp->y += 0.1;
	else if (key == 86)
		mapp->y -= 0.1;
	else if (key == 67)
		mapp->z += 0.01;
	else if (key == 75)
		mapp->z = mapp->z > 0.01 ? mapp->z - 0.01 : 0.01;
	else
		change_param_helper(key, mapp);
}

int		deal_key(int key, t_map *mapp)
{
	put_keys(key);
	if (key == 53)
	{
		mlx_destroy_window(mapp->mlx_ptr, mapp->win_ptr);
		exit(1);
	}
	change_param(key, mapp);
	mlx_clear_window(mapp->mlx_ptr, mapp->win_ptr);
	manage(mapp);
	return (0);
}

void	map_init(t_map *mapp)
{
	mapp->win_x = 1524;
	mapp->win_y = 1024;
	mapp->mlx_ptr = mlx_init();
	mapp->win_ptr = mlx_new_window(mapp->mlx_ptr, mapp->win_x, \
	mapp->win_y, "FdF");
	mapp->img_ptr = mlx_new_image(mapp->mlx_ptr, mapp->win_x, mapp->win_y);
	mapp->scale = 20;
	mapp->start_x = 0;
	mapp->start_y = 0;
	mapp->z = 0.01;
	mapp->x = 5.70;
	mapp->y = -6.50;
	mapp->is_color = 0x00ffff;
}

void	manage(t_map *mapp)
{
	mlx_destroy_image(mapp->mlx_ptr, mapp->img_ptr);
	mapp->img_ptr = mlx_new_image(mapp->mlx_ptr, mapp->win_x, mapp->win_y);
	del_map(*mapp, mapp->map1);
	copy_map(mapp);
	shift_to(mapp);
	rotate_x(mapp);
	rotate_y(mapp);
	shift_from(mapp);
	scale_map(mapp);
	center(mapp);
	draw_map(*mapp);
	mlx_put_image_to_window(mapp->mlx_ptr, mapp->win_ptr, mapp->img_ptr, 0, 0);
	put_controls(mapp);
}

int		main(int argc, char **argv)
{
	t_map		mapp;
	const char	*l = setlocale(LC_ALL, "");

	if (argc != 2 && l)
	{
		ft_printf("{red}Usege: ./fdf %s{eoc}\n", argv[1] ? argv[1] : \
				"file_name.fdf");
		return (0);
	}
	map_init(&mapp);
	parse_map(&mapp, argv[1]);
	normalize(&mapp);
	copy_map(&mapp);
	manage(&mapp);
	mlx_hook(mapp.win_ptr, 2, 5, deal_key, &mapp);
	mlx_hook(mapp.win_ptr, 17, 1L << 17, exit_x, 0);
	mlx_loop(mapp.mlx_ptr);
	return (0);
}
