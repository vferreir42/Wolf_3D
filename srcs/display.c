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

void draw_colonne(t_mlx *mlx, int colonne, int i)
{
	int x;

	x = 0;
	while (x < colonne / 2 && x >= 0 && x < SCREEN_HEIGHT)
	{
		ft_put_pixel(mlx, i, SCREEN_HEIGHT / 2 + x, 0xFFFFFF);
		ft_put_pixel(mlx, i, SCREEN_HEIGHT / 2 - x, 0xFFFFFF);
		x++;
	}
	while (SCREEN_HEIGHT / 2 + x < SCREEN_HEIGHT && SCREEN_HEIGHT / 2 - x >= 0)
	{
		ft_put_pixel(mlx, i, SCREEN_HEIGHT / 2 + x, 0xB3B191);
		ft_put_pixel(mlx, i, SCREEN_HEIGHT / 2 - x, 0x00BFFF);
		x++;
	}
}
