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

int main(int argc, char **argv)
{
  t_map *map;

  if (argc != 2)
  {
    printf("usage: ./wolf_3D <name_map>\n");
    exit (0);
  }

  if (!(map = malloc(sizeof(t_map))))
    return (0);
  if (!(map->mlx = malloc(sizeof(t_mlx))))
    return (0);

  if (argv[1])
    take_map(map, argv[1]);

  initialisation_minilibix(map);
  map->pos_x = 96;
  map->pos_y = 224;
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
