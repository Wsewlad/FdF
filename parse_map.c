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
	fd = open(name, O_RDONLY);
	while ((ret = read(fd, &c, 1)) && ret != -1)
	{
		if (c == '\n')
			rows++;
	}
	close(fd);
	return (rows);
}

static int count_col(char *line)
{
	int	i;
	int	in;
	int	len;

	i = 0;
	len = 0;
	while (line[i])
	{
		in = 0;
		while (line[i] && line[i] != ' ')
		{
			if (!in)
				len++;
			in = 1;
			i++;
		}
		if (line[i])
			i++;
	}
	return (len);
}

static void	set_coord(t_coord *map, char *line, int col, t_mlx mlx)
{
	int dx;
	int dy;
	int i;

	dx = mlx.mod.strt_x - mlx.mod.nl;
	dy = mlx.mod.strt_y + mlx.mod.nl;
	i = 0;
	while (i < col)
	{
		map[i].crd.x = dx + 25 * i + ft_atoi(line) * mlx.mod.altd;
		map[i].crd.y = dy + 5 * i - ft_atoi(line) * (mlx.mod.altd * 5);
		i++;
		line++;
		while (*(line + 1) && *line != ' ')
			line++;
		line++;
	}
	ft_printf("\n");
}

static void	split_int(char *line, t_coord **map, int i, t_mlx mlx)
{
	static int	first_len;

	if (!first_len)
		first_len = mlx.col;
	if (mlx.col != first_len)
	{
		ft_printf("Found wrong line length. Exiting.\n");
		exit(1);
	}
	map[i] = (t_coord*)malloc(sizeof(t_coord) * (mlx.col + 1));
	set_coord(map[i], line, mlx.col, mlx);
}

t_coord		**parse_map(t_mlx *mlx)
{
	t_coord	**map;
	int		rows;
	int		fd;
	int		i;
	char 	*line;

	i = 0;
	rows = count_rows(mlx->map_name);
	mlx->rows = rows;
	map = (t_coord**)malloc(sizeof(t_coord*) * (rows + 1));
	fd = open(mlx->map_name, O_RDONLY);
	while (i < rows && (get_next_line(fd, &line)))
	{
		mlx->col = count_col(line);
		mlx->mod.nl += 10;
		split_int(line, map, i, *mlx);
		ft_strdel(&line);
		i++;
	}
	map[i] = 0;
	close(fd);
	mlx->wind_x = 1000;
	mlx->wind_y = 1000;
	return (map);
}
