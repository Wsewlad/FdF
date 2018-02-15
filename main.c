#include "fdf.h"

int deal_key(int key, t_mlx *mlx)
{
	t_coord **map;

	ft_printf("%s\n", key == 53 ? "ESC" : "key");
	if (key == 53)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		exit(1);
	}
	else if (key == 123)
	{
		mlx->mod.strt_x += 10;
		mlx->mod.nl = 10;
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		map = parse_map(mlx);
		draw_map(map, mlx);
	}
	else if (key == 124)
	{
		mlx->mod.strt_x -= 10;
		mlx->mod.nl = 10;
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		map = parse_map(mlx);
		draw_map(map, mlx);
	}
	else if (key == 126)
	{
		mlx->mod.altd++;
		mlx->mod.nl = 10;
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		map = parse_map(mlx);
		draw_map(map, mlx);
	}
	else if (key == 125)
	{
		mlx->mod.altd--;
		mlx->mod.nl = 10;
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		map = parse_map(mlx);
		draw_map(map, mlx);
	}
	/*if (key == 115)
	{
		mlx->mod.x += 1;
		mlx->mod.nl = 10;
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		map = parse_map(mlx);
		draw_map(map, mlx);
	}
	if (key == 119)
	{
		mlx->mod.x -= 1;
		mlx->mod.nl = 10;
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		map = parse_map(mlx);
		draw_map(map, mlx);
	}*/
	return (0);
}

int main(int argc, char **argv)
{
	t_mlx	mlx;
	t_coord **map;

	if (argc != 2)
	{
		ft_printf("Usege: ... for %s\n", argv[1]);
		return (0);
	}
	mlx.map_name = argv[1];
	mlx.mod.nl = 10;
	mlx.mod.strt_x = 200;
	mlx.mod.strt_y = 100;
	//mlx.mod.x = 1;
	//mlx.mod.y = 1;
	mlx.mod.altd = 1;
	map = parse_map(&mlx);
	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, mlx.wind_x, mlx.wind_y, "mlx");
	mlx.color = 0xffffff;
	draw_map(map, &mlx);
	mlx_key_hook(mlx.win_ptr, deal_key, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return 0;
}