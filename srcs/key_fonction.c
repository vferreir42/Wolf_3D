/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_fonction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 16:19:44 by vferreir          #+#    #+#             */
/*   Updated: 2018/04/12 15:23:49 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	set_value(t_map *map)
{
	int i;

	i = -1;
	while (++i < 300)
		map->key_hook[i] = 0;
}

int			fct_key(int keycode, t_map *map)
{
	if (keycode == UP_KEY)
		map->key_hook[keycode] = 1;
	else if (keycode == DOWN_KEY)
		map->key_hook[keycode] = 1;
	else if (keycode == A_KEY)
		map->key_hook[keycode] = 1;
	else if (keycode == D_KEY)
		map->key_hook[keycode] = 1;
	else if (keycode == W_KEY)
		map->key_hook[keycode] = 1;
	else if (keycode == S_KEY)
		map->key_hook[keycode] = 1;
	return (0);
}

int do_change(t_map *map)
{
	double x;
	double y;

	if (map->key_hook[D_KEY])
		map->angle -= ROTATION;
	else if (map->key_hook[A_KEY])
		map->angle += ROTATION;
	else if (map->key_hook[W_KEY])
	{
		x = map->pos_x + cos(map->angle * DEGREE) * VITESSE;
		y = map->pos_y - sin(map->angle * DEGREE) * VITESSE;
		if (x >= 0 && y >= 0 && x / SIZE < map->carte_x && y / SIZE < map->carte_y
			&& map->carte[(int)(y / SIZE)][(int)(x / SIZE)] == '0')
			{
				map->pos_x = x;
				map->pos_y = y;
			}
	}
	else if (map->key_hook[S_KEY])
	{
		x = map->pos_x - cos(map->angle * DEGREE) * VITESSE;
		y = map->pos_y + sin(map->angle * DEGREE) * VITESSE;
		if (x >= 0 && y >= 0 && x / SIZE < map->carte_x && y / SIZE < map->carte_y
			&& map->carte[(int)(y / SIZE)][(int)(x / SIZE)] == '0')
			{
				map->pos_x = x;
				map->pos_y = y;
			}
	}
	else if (map->key_hook[UP_KEY])
		map->hauteur += 5;
	else if (map->key_hook[DOWN_KEY])
		map->hauteur -= 5;
	else
		return (0);
	ft_clean_image(map);
	test(map);
	mlx_put_image_to_window(map->mlx->mlx, map->mlx->windows, map->mlx->image, 0, 0);
	return (0);
}

int			my_key_funct(int keycode, t_map *map)
{
	if (keycode == ESC_KEY)
		exit(0);
	if (keycode == UP_KEY || keycode == DOWN_KEY
		|| keycode == A_KEY || keycode == D_KEY
		|| keycode == W_KEY || keycode == S_KEY)
		map->key_hook[keycode] = 0;
	return (0);
}
