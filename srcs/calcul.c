/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 18:19:08 by vferreir          #+#    #+#             */
/*   Updated: 2018/06/01 17:11:16 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static int		size_col(t_map *map, t_v *v, double dist_hor, double dist_ver)
{
	if (dist_hor)
		dist_hor = (DISTANCE * SIZE) / dist_hor;
	if (dist_ver)
		dist_ver = (DISTANCE * SIZE) / dist_ver;
	if (dist_hor > dist_ver)
	{
		map->offset = map->offset_hor;
		if (v->angle < 180)
			map->tex = 0;
		else
			map->tex = 1;
		return ((int)dist_hor);
	}
	else
	{
		map->offset = map->offset_ver;
		if (v->angle >= 90 && v->angle <= 270)
			map->tex = 2;
		else
			map->tex = 3;
		return ((int)dist_ver);
	}
}

static double	distance_horizontale(t_v *v, t_map *map, char **carte)
{
	double x1;
	double y1;

	y1 = (v->angle >= 0 && v->angle <= 180) ? (floor(map->pos_y / SIZE)
	* 64) - 0.0001 : (floor(map->pos_y / SIZE) * 64) + 64;
	v->step_y = (v->angle >= 0 && v->angle <= 180) ? -64 : 64;
	v->step_x = -v->step_y / tan(v->angle * DEGREE);
	x1 = map->pos_x + (map->pos_y - y1) / tan(v->angle * DEGREE);
	while (1)
	{
		if (floor(y1 / 64) < 0 || floor(y1 / 64) >= map->carte_y
				|| floor(x1 / 64) < 0 || floor(x1 / 64) >= map->carte_x)
			return (0);
		else if (carte[(int)(y1 / 64)][(int)(x1 / 64)] == '1')
		{
			map->offset_hor = (int)x1 % 64;
			map->offset_hor /= 2;
			return (fabs((map->pos_x - x1) / cos(v->angle * DEGREE))
			* cos((v->angle - map->angle) * DEGREE));
		}
		y1 += v->step_y;
		x1 += v->step_x;
	}
}

static double	distance_verticale(t_v *v, t_map *map, char **carte)
{
	double x1;
	double y1;

	x1 = (v->angle >= 90 && v->angle <= 270) ? ((floor(map->pos_x / SIZE)
	* 64) - 0.0001) : ((floor(map->pos_x / SIZE) * 64) + 64);
	v->step_x = (v->angle >= 90 && v->angle <= 270) ? -64 : 64;
	v->step_y = -v->step_x * tan(v->angle * DEGREE);
	y1 = map->pos_y + (map->pos_x - x1) * tan(v->angle * DEGREE);
	while (1)
	{
		if (floor(y1 / 64) < 0 || floor(y1 / 64) >= map->carte_y
				|| floor(x1 / 64) < 0 || floor(x1 / 64) >= map->carte_x)
			return (0);
		else if (carte[(int)(y1 / 64)][(int)(x1 / 64)] == '1')
		{
			map->offset_ver = (int)y1 % 64;
			map->offset_ver /= 2;
			return (fabs((map->pos_x - x1) / cos(v->angle * DEGREE))
			* cos((v->angle - map->angle) * DEGREE));
		}
		y1 += v->step_y;
		x1 += v->step_x;
	}
}

void			calcul_colonne(t_map *map)
{
	t_v		v;
	int		i;
	int		colonne;
	double	dist_hor;
	double	dist_ver;

	dist_hor = -1;
	dist_ver = -1;
	map->angle %= 360;
	i = -1;
	while (++i < SCREEN_WIDTH)
	{
		v.angle = map->angle + 30 - (double)i * 60 / SCREEN_WIDTH;
		v.rest = v.angle - (int)v.angle;
		v.angle = (int)v.angle % 360 + v.rest;
		v.angle += (v.angle < 0) ? 360 : 0;
		dist_hor = distance_horizontale(&v, map, map->carte);
		dist_ver = distance_verticale(&v, map, map->carte);
		colonne = size_col(map, &v, dist_hor, dist_ver);
		draw_colonne(map, colonne, i);
	}
	mini_map(map);
}
