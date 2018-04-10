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

int main(void)
{
  char **carte;
  t_map *map;

  if (!(map = malloc(sizeof(t_map))))
    return (0);
  if (!(map->mlx = malloc(sizeof(t_mlx))))
    return (0);

  initialisation_minilibix(map);
  map->pos_x = 96;
  map->pos_y = 224;
  map->angle = 90;
  test(map);


  mlx_put_image_to_window(map->mlx->mlx, map->mlx->windows, map->mlx->image, 0, 0);
  mlx_key_hook(map->mlx->windows, &my_key_funct, map);
  mlx_loop(map->mlx);
  return (0);
}
