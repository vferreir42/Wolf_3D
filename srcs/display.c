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

	x = 0;
	if (v->up == 1)
		couleur = 0xFFFFFF;
	if (v->bottom == 1)
		couleur = 0xFFFF00;
	if (v->right == 1)
		couleur = 0xA4405B;
	if (v->left == 1)
		couleur = 0xA44000;
	while (x < colonne / 2)
	{
		ft_put_pixel(map->mlx, i, SCREEN_HEIGHT / 2 + x + map->hauteur, couleur);
		ft_put_pixel(map->mlx, i, SCREEN_HEIGHT / 2 - x + map->hauteur, couleur);
		x++;
	}
	while (x < SCREEN_HEIGHT)
	{
		ft_put_pixel(map->mlx, i, SCREEN_HEIGHT / 2 + x + map->hauteur, 0xB3B191);
		ft_put_pixel(map->mlx, i, SCREEN_HEIGHT / 2 - x + map->hauteur, 0x00BFFF);
		x++;
	}
}
