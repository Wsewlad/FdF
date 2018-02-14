/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 18:03:13 by vfil              #+#    #+#             */
/*   Updated: 2018/02/14 18:03:15 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	count_rows(char *name)
{
	int		rows;
	int		fd;
	int 	ret;
	char	c;
	ft_printf("name: %s\n", name);
	fd = open(name, O_RDONLY);
	ft_printf("fd: %d", fd);
	while ((ret = read(fd, &c, 1)) && ret != -1)
	{
		if (c == '\n')
			rows++;
	}
	close(fd);
	return (rows);
}

static void	split_int(char **line, t_coord	**map)
{
	char	**str;
	int		i;

	str = ft_strsplit(*line, ' ');
	ft_strdel(line);
	i = 0;
	while (str[i])
		i++;

}

t_coord		**parse_map(char *name)
{
	t_coord	**map;
	int		rows;
	int		fd;
	int		ret;
	char 	*line;

	rows = count_rows(name);
	map = (t_coord**)malloc(sizeof(t_coord*) * (rows + 1));
	fd = open(name, O_RDONLY);
	while ((ret = get_next_line(fd, &line)))
	{
		split_int(&line, map);
	}
	ft_printf("rows: %d\n", rows);
	return (map);
}
