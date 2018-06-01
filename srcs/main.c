/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 15:32:20 by vferreir          #+#    #+#             */
/*   Updated: 2018/06/01 14:45:37 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int	motion_hook(int x, int y, t_map *map)
{
	if (x >= 0 && y >= 0 && x <= SCREEN_WIDTH && y <= SCREEN_HEIGHT)
	{
		y = (SCREEN_HEIGHT / 2) - y;
		map->hauteur = y;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	*map;

	map = NULL;
	if (argc != 2 || !argv[1])
	{
		write(1, "usage: ./wolf_3D <name_map>\n", 28);
		return (-1);
	}
	if (!(map = malloc(sizeof(t_map))))
		return (-1);
	initialisation_map(map, argv[1]);
	initialisation_minilibix(map);
	initialisation_texture(map);
	mlx_do_key_autorepeatoff(map->mlx);
	mlx_loop_hook(map->mlx->mlx, &loop_hook, map);
	mlx_hook(map->mlx->windows, KEYPRESS, KEYPRESSMASK, &fct_key, map);
	mlx_hook(map->mlx->windows,
		MOTIONNOTIFY, POINTERMOTIONMASK, &motion_hook, map);
	mlx_key_hook(map->mlx->windows, &fct_key, map);
	mlx_loop(map->mlx->mlx);
	return (0);
}
