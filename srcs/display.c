/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 17:55:17 by vferreir          #+#    #+#             */
/*   Updated: 2018/06/01 17:02:00 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	mode_normal(t_map *map, int col, int x, int tex)
{
	double		diviseur;
	int			t;
	int			y;
	int			var;

	diviseur = (double)col / 32;
	var = (SCREEN_HEIGHT - col) / 2;
	t = (col > SCREEN_HEIGHT) ? (col - SCREEN_HEIGHT) / 2 : 0;
	y = -1;
	while (++y < SCREEN_HEIGHT)
	{
		if (y < var)
			ft_put_pixel(map->mlx, x, y, 0x00BFFF);
		else if (y >= SCREEN_HEIGHT - var)
			ft_put_pixel(map->mlx, x, y, 0xB3B191);
		else
		{
			ft_put_pixel(map->mlx, x, y, ft_take_pixel(map->texture[tex],
						map->offset, t / diviseur, 0));
			t++;
		}
	}
}

void	mode_couleur(t_map *map, int col, int x, int tex)
{
	int couleur[4];
	int y;
	int var;

	couleur[0] = 0x00FFFF;
	couleur[1] = 0xFFFF00;
	couleur[2] = 0xA4405B;
	couleur[3] = 0xA44000;
	var = (SCREEN_HEIGHT - col) / 2;
	y = -1;
	while (++y < SCREEN_HEIGHT)
	{
		if (y < var)
			ft_put_pixel(map->mlx, x, y, 0x00BFFF);
		else if (y > SCREEN_HEIGHT - var)
			ft_put_pixel(map->mlx, x, y, 0xB3B191);
		else
			ft_put_pixel(map->mlx, x, y, couleur[tex]);
	}
}

void	mode_psychedelique(t_map *map, int col, int x, int tex)
{
	int couleur[4];
	int y;
	int start;

	couleur[0] = 0x00FFFF;
	couleur[1] = 0xFFFF00;
	couleur[2] = 0xA4405B;
	couleur[3] = 0xA44000;
	if (col >= SCREEN_HEIGHT)
		col = SCREEN_HEIGHT - 1;
	start = SCREEN_HEIGHT / 2 - col / 2;
	y = -1;
	while (++y < col)
	{
		ft_put_pixel(map->mlx, x, start, couleur[tex]);
		start++;
	}
}

void	draw_colonne(t_map *map, int col, int x)
{
	if (map->mode == 1)
		mode_normal(map, col, x, map->tex);
	else if (map->mode == 2)
		mode_couleur(map, col, x, map->tex);
	else if (map->mode == 3)
		mode_psychedelique(map, col, x, map->tex);
}
