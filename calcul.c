/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 18:19:08 by vferreir          #+#    #+#             */
/*   Updated: 2018/04/09 18:19:09 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static int size_colonne(float dist_hor)
{
  int colonne;

  colonne = (277 * 64) / (int)dist_hor;
  return (colonne);
}

static double distance_horizontale(t_map *map, char **carte, double angle)
{
  double x1;
  double y1;
  double y_a;
  double x_a;

  if (angle >= 0 && angle <= 180)
    y1 = (floor(map->pos_y / SIZE) * 64) - 1;
  else
    y1 = (floor(map->pos_y / SIZE) * 64) + 64;

  x1 = -1;
  if (angle >= 0 && angle <= 180)
    y_a = -64;
  else
    y_a = 64;
  x_a = 64 / tan(angle * PI / 180);

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

void test(t_map *map)
{
  char *carte[] = {"111101", "000000", "000000", "000000", "000000", "000000", "1111111"};

  for (int i = 0; i < 4; i++)
    printf("%s\n", carte[i]);
  printf("\n");
  map->carte_x = 6;
  map->carte_y = 7;

  int i;
  double dist_hor;
  double dist_ver;
  double dist;
  int colonne;

  i = -1;
  while (++i < 320)
  {
    dist_hor = distance_horizontale(map, carte, map->angle + 30 - (float)i * 60 / 320);
    colonne = size_colonne(dist_hor);
    if (colonne >= 0)
    {
      printf("%f => Colonne : %d\n",  map->angle + 30 - i * 60 / 320, colonne);
      draw_colonne(map->mlx, colonne, i);
    }
  }

}
