/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 17:55:17 by vferreir          #+#    #+#             */
/*   Updated: 2018/04/09 17:55:18 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void draw_colonne(t_mlx *mlx, int colonne, int i)
{
  int x;

  x = 0;
  while (x < colonne / 2)
  {
    ft_put_pixel(mlx, i, SCREEN_HEIGHT / 2 + x, 0xFFFFFF);
    ft_put_pixel(mlx, i, SCREEN_HEIGHT / 2 - x, 0xFFFFFF);
    x++;
  }

  while (x <= SCREEN_HEIGHT)
  {
//    ft_put_pixel(mlx, i, SCREEN_HEIGHT / 2 + x, 0xB3B191);
    ft_put_pixel(mlx, i, SCREEN_HEIGHT / 2 - x, 0x00BFFF);
    x++;
  }

}
