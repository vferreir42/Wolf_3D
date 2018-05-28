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
		test(map);
		mlx_put_image_to_window(map->mlx->mlx, map->mlx->windows, map->mlx->image, 0, 0);
	}
	return (0);
}

int main(int argc, char **argv)
{
	t_map *map;

	if (argc != 2 || !argv[1])
	{
		printf("usage: ./wolf_3D <name_map>\n");
		exit (0);
	}
	if (!(map = malloc(sizeof(t_map))))
		return (0);
	initialisation_map(map, argv[1]);
	initialisation_minilibix(map);

	mlx_do_key_autorepeatoff(map->mlx);
	mlx_loop_hook(map->mlx->mlx, &loop_hook, map);
	mlx_hook(map->mlx->windows, KEYPRESS, KEYPRESSMASK, &fct_key, map);
	mlx_key_hook(map->mlx->windows, &my_key_funct, map);


//	mlx_hook(map->mlx->windows, 6, POINTERMOTIONMASK, &motion_hook, map);
	mlx_loop(map->mlx);

	return (0);
}
