/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 17:55:17 by vferreir          #+#    #+#             */
/*   Updated: 2018/05/04 17:56:50 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void draw_colonne(t_v *v, t_map *map, int colonne, int i)
{
	int x;
	int couleur;
	int var;

	x = -1;
	if (v->up == 1)
		couleur = 0xFFFFFF;
	else if (v->bottom == 1)
		couleur = 0xFFFF00;
	else if (v->right == 1)
		couleur = 0xA4405B;
	else if (v->left == 1)
		couleur = 0xA44000;
	var = SCREEN_HEIGHT / 2 + map->hauteur;
	while (++x < colonne / 2 && x < SCREEN_HEIGHT)
	{
		ft_put_pixel(map->mlx, i, var + x, couleur);
		ft_put_pixel(map->mlx, i, var - x, couleur);
	}
	while (x < SCREEN_HEIGHT)
	{
		ft_put_pixel(map->mlx, i, var + x, 0xB3B191);
		ft_put_pixel(map->mlx, i, var - x, 0x00BFFF);
		x++;
	}
}
