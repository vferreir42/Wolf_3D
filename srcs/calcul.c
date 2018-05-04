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

static double size_colonne(double dist_hor, double dist_ver)
{
	if (dist_hor == -1 && dist_ver == -1)
		return (-1);
	if (dist_hor == -1)
		return ((DISTANCE * 64) / dist_ver);
	if (dist_ver == -1)
		return ((DISTANCE * 64) / dist_hor);
	if (dist_hor > dist_ver)
		return ((DISTANCE * 64) / dist_ver);
	else
		return ((DISTANCE * 64) / dist_hor);
}

double modulo_xbox(double angle)
{
	double rest;

	rest = angle - (int)angle;
	angle = (int)angle % 360 + rest;
	return (angle);
}

static double distance_horizontale(t_map *map, char **carte, double angle)
{
	double x1;
	double y1;
	double y_a;
	double x_a;

	angle = modulo_xbox(angle);
	if ((angle >= 0 && angle <= 180) || angle <= -180)
		y1 = (floor(map->pos_y / SIZE) * 64) - 1;
	else
		y1 = (floor(map->pos_y / SIZE) * 64) + 64;

	x1 = -1;
	if ((angle >= 0 && angle <= 180) || angle <= -180)
		y_a = -64;
	else
		y_a = 64;
	x_a = -y_a / tan(angle * PI / 180);

	while (1)
	{
		if (x1 == -1)
			x1 = map->pos_x + (map->pos_y - y1) / tan(angle * PI / 180);
		if (floor(y1 / 64) >= 0 && floor(y1 / 64) < map->carte_y
				&& floor(x1 / 64) >= 0 && floor(x1 / 64) < map->carte_x)
		{
			if (carte[(int)floor(y1 / 64)][(int)floor(x1 / 64)] == '1')
				return (fabs((map->pos_x - x1) / cos(angle * PI / 180)) * cos((angle - map->angle) * PI / 180));
		}
		else
			return (-1);
		y1 += y_a;
		x1 += x_a;
	}
}

static double distance_verticale(t_map *map, char **carte, double angle)
{
	double x1;
	double y1;
	double y_a;
	double x_a;

	angle = modulo_xbox(angle);
	if ((angle >= 90 && angle <= 270) || (angle <= -90 && angle >= -270))
		x1 = (floor(map->pos_x / SIZE) * 64) - 1;
	else
		x1 = (floor(map->pos_x / SIZE) * 64) + 64;

	y1 = -1;
	if ((angle >= 90 && angle <= 270) || (angle <= -90 && angle >= -270))
		x_a = -64;
	else
		x_a = 64;
	y_a = -x_a * tan(angle * PI / 180);

	while (1)
	{
		if (y1 == -1)
			y1 = map->pos_y + (map->pos_x - x1) * tan(angle * PI / 180);
		if (floor(y1 / 64) >= 0 && floor(y1 / 64) < map->carte_y
				&& floor(x1 / 64) >= 0 && floor(x1 / 64) < map->carte_x)
		{
			if (carte[(int)floor(y1 / 64)][(int)floor(x1 / 64)] == '1')
				return (fabs((map->pos_x - x1) / cos(angle * PI / 180)) * cos((angle - map->angle) * PI / 180));
		}
		else
			return (-1);
		y1 += y_a;
		x1 += x_a;
	}
}

void test(t_map *map)
{
	int i;
	int colonne;
	double dist_hor = -1;
	double dist_ver = -1;

	map->angle %= 360;
	i = -1;
	while (++i < SCREEN_WIDTH)
	{
		dist_hor = distance_horizontale(map, map->carte, map->angle + 30 - (double)i * 60 / SCREEN_WIDTH);
		dist_ver = distance_verticale(map, map->carte, map->angle + 30 - (double)i * 60 / SCREEN_WIDTH);
		colonne = size_colonne(dist_hor, dist_ver);
		draw_colonne(map->mlx, colonne, i);
	}
	mini_map(map);
}
