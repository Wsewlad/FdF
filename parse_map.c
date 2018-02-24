/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 18:03:13 by vfil              #+#    #+#             */
/*   Updated: 2018/02/24 16:40:26 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	count_rows(char *name)
{
	int		rows;
	int		fd;
	int		ret;
	char	c;

	rows = 0;
	fd = open(name, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("{red}File doesn't exist %S{eoc}\n", L"¯\\_(ツ)_/¯");
		exit(1);
	}
	while ((ret = read(fd, &c, 1)) && ret != -1)
	{
		if (c == '\n')
			rows++;
	}
	close(fd);
	if (!rows)
	{
		ft_printf("{red}File is incorrect %S{eoc}\n", L"¯\\_(ツ)_/¯");
		exit(1);
	}
	return (rows);
}

static int	hex2dec(char *hex)
{
	unsigned int	res;
	unsigned int	i;
	unsigned int	j;
	const char		hx[] = "0123456789abcdefABCDEF";

	i = 0;
	res = 0;
	while (hex[i])
	{
		j = 0;
		while (hx[j] != hex[i])
			j++;
		j = j > 15 ? j - 6 : j;
		res = res * 16 + j;
		i++;
	}
	return (res);
}

static void	get_altd_color(char **prsd_line, t_map *mapp, int i, int j)
{
	char	*hex;

	mapp->map0[i][j].crd.z = ft_atoi(prsd_line[j]);
	if ((hex = ft_strstr(prsd_line[j], ",0x")) ||
			(hex = ft_strstr(prsd_line[j], ",0X")))
	{
		mapp->map0[i][j].crd.color = hex2dec(hex + 3);
		mapp->is_color = 0;
	}
	else
		mapp->map0[i][j].crd.color = 0xffffff;
}

static void	split_coord(char **prsd_line, t_map *mapp, int i)
{
	static int	first_len;
	int			j;

	mapp->columns = 0;
	while (prsd_line[mapp->columns])
		mapp->columns++;
	if (!first_len)
		first_len = mapp->columns;
	if (mapp->columns != first_len)
	{
		ft_printf("{red}Found wrong line length. Exiting.{eoc}\n");
		exit(1);
	}
	mapp->map0[i] = (t_coord*)malloc(sizeof(t_coord) * (mapp->columns));
	j = 0;
	while (j < mapp->columns)
	{
		mapp->map0[i][j].crd.x = j;
		mapp->map0[i][j].crd.y = i;
		get_altd_color(prsd_line, mapp, i, j);
		j++;
	}
}

void		parse_map(t_map *mapp, char *name)
{
	int		fd;
	int		i;
	char	*line;
	char	**prsd_line;

	mapp->rows = count_rows(name);
	mapp->map0 = (t_coord**)malloc(sizeof(t_coord*) * (mapp->rows));
	fd = open(name, O_RDONLY);
	i = 0;
	while ((get_next_line(fd, &line)) > 0)
	{
		prsd_line = ft_strsplit(line, ' ');
		split_coord(prsd_line, mapp, i);
		ft_strdel(&line);
		ft_arriter(prsd_line, &free);
		free(prsd_line);
		i++;
	}
	ft_strdel(&line);
	close(fd);
}
