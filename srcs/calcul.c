/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 18:19:08 by vferreir          #+#    #+#             */
/*   Updated: 2018/05/04 17:57:09 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

double modulo_xbox(double angle)
{
	double rest;

	rest = angle - (int)angle;
	angle = (int)angle % 360 + rest;
	if (angle < 0)
		angle += 360;
	return (angle);
}

static int size_colonne(t_v *v, double dist_hor, double dist_ver)
{
	v->up = 0;
	v->bottom = 0;
	v->right = 0;
	v->left = 0;
	if (dist_hor)
		dist_hor = (DISTANCE * SIZE) / dist_hor;
	if (dist_ver)
		dist_ver = (DISTANCE * SIZE) / dist_ver;
	if (dist_hor > dist_ver)
	{
		if (v->angle < 180)
			v->up = 1;
		else
			v->bottom = 1;
		return ((int)dist_hor);
	}
	else
	{
		if (v->angle >= 90 && v->angle <= 270)
			v->right = 1;
		else
			v->left = 1;
		return ((int)dist_ver);
	}
}

static double distance_horizontale(t_v *v, t_map *map, char **carte)
{
	double x1;
	double y1;

	if (v->angle >= 0 && v->angle <= 180)
	{
		y1 = (floor(map->pos_y / SIZE) * 64) - 0.0001;
		v->step_y = -64;
	}
	else
	{
		y1 = (floor(map->pos_y / SIZE) * 64) + 64;
		v->step_y = 64;
	}
	v->step_x = -v->step_y / tan(v->angle * DEGREE);
	x1 = map->pos_x + (map->pos_y - y1) / tan(v->angle * DEGREE);
	while (1)
	{
		if (floor(y1 / 64) < 0 || floor(y1 / 64) >= map->carte_y
				|| floor(x1 / 64) < 0 || floor(x1 / 64) >= map->carte_x)
			return (0);
		else if (carte[(int)(y1 / 64)][(int)(x1 / 64)] == '1')
				return (fabs((map->pos_x - x1) / cos(v->angle * DEGREE)) * cos((v->angle - map->angle) * DEGREE));
		y1 += v->step_y;
		x1 += v->step_x;
	}
}

static double distance_verticale(t_v *v, t_map *map, char **carte)
{
	double x1;
	double y1;

	if (v->angle >= 90 && v->angle <= 270)
	{
		x1 = (floor(map->pos_x / SIZE) * 64) - 0.0001;
		v->step_x = -64;
	}
	else
	{
		x1 = (floor(map->pos_x / SIZE) * 64) + 64;
		v->step_x = 64;
	}
	v->step_y = -v->step_x * tan(v->angle * DEGREE);
	y1 = map->pos_y + (map->pos_x - x1) * tan(v->angle * DEGREE);
	while (1)
	{
		if (floor(y1 / 64) < 0 || floor(y1 / 64) >= map->carte_y
				|| floor(x1 / 64) < 0 || floor(x1 / 64) >= map->carte_x)
			return (0);
		else if (carte[(int)(y1 / 64)][(int)(x1 / 64)] == '1')
				return (fabs((map->pos_x - x1) / cos(v->angle * DEGREE)) * cos((v->angle - map->angle) * DEGREE));
		y1 += v->step_y;
		x1 += v->step_x;
	}
}

void test(t_map *map)
{
	t_v v;
	int i;
	int colonne;
	double dist_hor = -1;
	double dist_ver = -1;

	map->angle %= 360;
	i = -1;
	while (++i < SCREEN_WIDTH)
	{
		v.angle = modulo_xbox(map->angle + 30 - (double)i * 60 / SCREEN_WIDTH);
		dist_hor = distance_horizontale(&v, map, map->carte);
		dist_ver = distance_verticale(&v, map, map->carte);
		colonne = size_colonne(&v, dist_hor, dist_ver);
		draw_colonne(&v, map, colonne, i);
	}
	mini_map(map);
}
