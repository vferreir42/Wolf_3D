/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_fonction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 16:19:44 by vferreir          #+#    #+#             */
/*   Updated: 2018/04/06 16:19:45 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int			my_key_funct(int keycode, t_map *map)
{
	if (keycode == ESC_KEY)
		exit(0);
	if (keycode == RIGHT_KEY)
	{
		ft_clean_image(map);
		map->angle -= 1;
		test(map);
		mlx_put_image_to_window(map->mlx->mlx, map->mlx->windows, map->mlx->image, 0, 0);
	}
	return (0);
}
