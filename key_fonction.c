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
	else if (keycode == RIGHT_KEY)
		map->key_hook[keycode] = 1;
	else if (keycode == LEFT_KEY)
		map->key_hook[keycode] = 1;
	return (0);
}

int do_change(t_map *map)
{
	if (map->key_hook[RIGHT_KEY])
		map->angle -= 10;
	else if (map->key_hook[LEFT_KEY])
		map->angle += 10;
	else if (map->key_hook[UP_KEY])
	{
		map->angle %= 360;
		map->pos_x += cos(map->angle * PI / 180) * VITESSE;
		map->pos_y -= sin(map->angle * PI / 180) * VITESSE;
	}
	else if (map->key_hook[DOWN_KEY])
	{
		map->angle %= 360;
		map->pos_x -= cos(map->angle * PI / 180) * VITESSE;
		map->pos_y += sin(map->angle * PI / 180) * VITESSE;
	}
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
	if (keycode == UP_KEY || keycode == DOWN_KEY || keycode == LEFT_KEY || keycode == RIGHT_KEY)
		map->key_hook[keycode] = 0;
	return (0);
}
