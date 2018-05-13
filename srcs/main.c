/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 15:32:20 by vferreir          #+#    #+#             */
/*   Updated: 2018/05/04 17:48:13 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int			motion_hook(int x, int y, t_map *map)
{
	if (x >= 0 && y >= 0 && x <= SCREEN_WIDTH && y <= SCREEN_HEIGHT)
	{
		y = (SCREEN_HEIGHT / 2) - y;
		x = (SCREEN_WIDTH / 2) - x;
		x = x / 200;
		map->angle += x;
		map->hauteur = y;
		ft_clean_image(map);
		test(map);
		mlx_put_image_to_window(map->mlx->mlx, map->mlx->windows, map->mlx->image, 0, 0);
	}
	return (0);
}

int main(int argc, char **argv)
{
	t_map *map;

	if (argc != 2)
	{
		printf("usage: ./wolf_3D <name_map>\n");
		exit (0);
	}
	if (!(map = malloc(sizeof(t_map))))
		return (0);
	if (!(map->mlx = malloc(sizeof(t_mlx))))
		return (0);
	if (argv[1])
		take_map(map, argv[1]);

	initialisation_minilibix(map);
	map->pos_x = 160;
	map->pos_y = 224;
	map->angle = 60;
	map->hauteur = 0;

	test(map);
	set_value(map);

	mlx_put_image_to_window(map->mlx->mlx, map->mlx->windows, map->mlx->image, 0, 0);
	mlx_hook(map->mlx->windows, KEYPRESS, 0, &fct_key, map);
	mlx_loop_hook(map->mlx->mlx, &do_change, map);
	mlx_key_hook(map->mlx->windows, &my_key_funct, map);
	mlx_hook(map->mlx->windows, 6, POINTERMOTIONMASK, &motion_hook, map);
	mlx_loop(map->mlx);

	return (0);
}
