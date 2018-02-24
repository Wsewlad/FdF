/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 22:42:05 by vfil              #+#    #+#             */
/*   Updated: 2018/02/23 22:42:07 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	change_param_helper(int key, t_map *mapp)
{
	if (key == 126)
		mapp->start_y -= 10;
	else if (key == 125)
		mapp->start_y += 10;
	else if (key == 123)
		mapp->start_x -= 10;
	else if (key == 124)
		mapp->start_x += 10;
	else if (key == 49)
		mapp->is_color += rand();
}
