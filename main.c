#include "fdf.h"

int deal_key(int key, t_mlx *mlx)
{
	ft_printf("%s\n", key == 53 ? "ESC" : "key");
	if (key == 53)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		exit(1);
	}
	return (0);
}

int main(int argc, char **argv)
{
	t_mlx	mlx;
	t_coord **map;
	t_coord	coord0;
	t_coord coord1;
	int x;
	int y;
	int dx;
	int dy;

	if (argc != 2)
	{
		ft_printf("Usege: ... for %s\n", argv[1]);
		return (0);
	}
	map = parse_map(argv[1]);
	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, 500, 500, "mlx");
	x = 10;
	y = 10;
	dx = 40;
	dy = 15;
	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, 500, 500, "mlx");
	mlx.color = 255;
	coord0.crd.x = x + dx;
	coord0.crd.y = y + dy;
	coord1.crd.x = x + dx * 2;
	coord1.crd.y = y + dy * 2;
	draw_map(&mlx, &coord0, &coord1);
	coord0.crd.x = x + dx * 2;
	coord0.crd.y = y + dy * 2;
	coord1.crd.x = x + dx * 3 + 15;
	coord1.crd.y = y + dy * 3 - 15;
	draw_map(&mlx, &coord0, &coord1);
	coord0.crd.x = x + dx * 3 + 15;
	coord0.crd.y = y + dy * 3 - 15;
	coord1.crd.x = x + dx * 4;
	coord1.crd.y = y + dy * 4;
	draw_map(&mlx, &coord0, &coord1);
	mlx_key_hook(mlx.win_ptr, deal_key, &mlx);
	mlx_loop(mlx.mlx_ptr);

	return 0;
}

/*
	x = 10;
	y = 10;
	dx = 40;
	dy = 15;
	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, 500, 500, "mlx");
	mlx.color = 255;
	coord.c0.x = x + dx;
	coord.c0.y = y + dy;
	coord.c1.x = x + dx * 2;
	coord.c1.y = y + dy * 2;
	draw_map(&mlx, &coord);
	coord.c0.x = x + dx * 2;
	coord.c0.y = y + dy * 2;
	coord.c1.x = x + dx * 3 + 15;
	coord.c1.y = y + dy * 3 - 15;
	draw_map(&mlx, &coord);
	coord.c0.x = x + dx * 3 + 15;
	coord.c0.y = y + dy * 3 - 15;
	coord.c1.x = x + dx * 4;
	coord.c1.y = y + dy * 4;
	draw_map(&mlx, &coord);
 */