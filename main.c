/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 15:32:20 by vferreir          #+#    #+#             */
/*   Updated: 2018/04/06 15:32:21 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void print(t_map *map, int j, int x)
{
  int count_j;
  int count_x;

  count_j = j;
  if (j + 16 <= SCREEN_HEIGHT && x + 16 <= SCREEN_WIDTH)
  {
    while (++count_j < j + 16)
    {
      count_x = x;
      while (++count_x < x + 16)
        ft_put_pixel(map->mlx, count_x, count_j, 0xFFFFFF);
    }
  }

  j = -1;
  while (++j < 6)
  {
    x = -1;
    while (++x < 6)
    {
      ft_put_pixel(map->mlx, 77 + x, 77 + j, 0x850606);
    }
  }
}

void set_in_black(t_map *map)
{
  int j;
  int x;

  j = -1;
  while (++j < 160)
  {
    x = -1;
    while (++x < 160)
      ft_put_pixel(map->mlx, j, x, 0x000000);
  }
}

void bonus(t_map *map)
{
  int x;
  int j;
  int count_j;
  int count_x;

  set_in_black(map);
  j = (int)floor(map->pos_y / SIZE);
  j -= 6;
  count_j = -1;
  while (++count_j < 10)
  {
    j++;
    if (j >= 0 && map->carte[(int)floor(map->pos_y / SIZE)])
    {
      x = (int)floor(map->pos_x / SIZE);
      x -= 6;
      count_x = -1;
      while (++count_x < 10)
      {
        x++;
        if (x >= 0 && map->carte[j][x] && map->carte[j][x] == '1')
            print(map, count_j * 16, count_x * 16);
      }
    }
  }

}

int main(int argc, char **argv)
{
  t_map *map;

  if (!(map = malloc(sizeof(t_map))))
    return (0);
  if (!(map->mlx = malloc(sizeof(t_mlx))))
    return (0);

  if (argv[1])
    take_map(map, argv[1]);


  initialisation_minilibix(map);

  map->pos_x = 500;
  map->pos_y = 500;
  map->angle = 60;


  test(map);

  set_value(map);
  mlx_put_image_to_window(map->mlx->mlx, map->mlx->windows, map->mlx->image, 0, 0);
  mlx_hook(map->mlx->windows, KEYPRESS, 0, &fct_key, map);
  mlx_loop_hook(map->mlx->mlx, &do_change, map);
  mlx_key_hook(map->mlx->windows, &my_key_funct, map);
  mlx_loop(map->mlx);

  return (0);
}
