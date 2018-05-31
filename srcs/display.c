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

void mode_normal(t_map *map, int colonne, int x, int tex)
{
	int y;
	int start;
	int couleur;
	double diviseur;

	if (colonne >= SCREEN_HEIGHT)
		colonne = SCREEN_HEIGHT - 1;
	diviseur = (double)colonne / 32;
	start = SCREEN_HEIGHT / 2 - colonne / 2;
	y = -1;
	while (++y < colonne)
	{
		couleur = ft_take_pixel(map->texture[tex], map->offset, y / diviseur, 0);
		ft_put_pixel(map->mlx, x, start, couleur);
		start++;
	}
	y = start - 1;
	while (++y < SCREEN_HEIGHT)
	{
		ft_put_pixel(map->mlx, x, y, 0xB3B191);
		ft_put_pixel(map->mlx, x, SCREEN_HEIGHT - y, 0x00BFFF);
	}
}

void mode_couleur(t_map *map, int colonne, int x, int tex)
{
	int couleur[4] = {0x00FFFF, 0xFFFF00, 0xA4405B, 0xA44000};
	int y;
	int start;

	if (colonne >= SCREEN_HEIGHT)
		colonne = SCREEN_HEIGHT - 1;
	start = SCREEN_HEIGHT / 2 - colonne / 2;
	y = -1;
	while (++y < colonne)
	{
		ft_put_pixel(map->mlx, x, start, couleur[tex]);
		start++;
	}
	y = start - 1;
	while (++y < SCREEN_HEIGHT)
	{
		ft_put_pixel(map->mlx, x, y, 0xB3B191);
		ft_put_pixel(map->mlx, x, SCREEN_HEIGHT - y, 0x00BFFF);
	}
}

void mode_psychedelique(t_map *map, int colonne, int x, int tex)
{
	int couleur[4] = {0x00FFFF, 0xFFFF00, 0xA4405B, 0xA44000};
	int y;
	int start;

	if (colonne >= SCREEN_HEIGHT)
		colonne = SCREEN_HEIGHT - 1;
	start = SCREEN_HEIGHT / 2 - colonne / 2;
	y = -1;
	while (++y < colonne)
	{
		ft_put_pixel(map->mlx, x, start, couleur[tex]);
		start++;
	}
}

void draw_colonne(t_map *map, int colonne, int x)
{
	if (map->mode == 1)
		mode_normal(map, colonne, x, map->tex);
	else if (map->mode == 2)
		mode_couleur(map, colonne, x, map->tex);
	else if (map->mode == 3)
		mode_psychedelique(map, colonne, x, map->tex);
}
