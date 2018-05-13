/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 16:03:17 by vferreir          #+#    #+#             */
/*   Updated: 2018/04/06 16:03:18 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_clean_image(t_map *map)
{
	free(map->mlx->data);
	map->mlx->image = mlx_new_image(map->mlx->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	map->mlx->data = mlx_get_data_addr(map->mlx->image,
			&map->mlx->bpp, &map->mlx->size_line, &map->mlx->endian);
}

void	ft_put_pixel(t_mlx *mlx, int x, int y, int couleur)
{
	int	r;
	int	g;
	int	b;

	if (y >= SCREEN_HEIGHT || y <= 0 || x < 0 || x > SCREEN_WIDTH)
		return ;
	r = (couleur & 16711680) >> 16;
	g = (couleur & 65280) >> 8;
	b = (couleur & 255);
	mlx->data[y * mlx->size_line + x * mlx->bpp / 8] = b;
	mlx->data[y * mlx->size_line + x * mlx->bpp / 8 + 1] = g;
	mlx->data[y * mlx->size_line + x * mlx->bpp / 8 + 2] = r;
}

void	initialisation_minilibix(t_map *map)
{
	map->mlx->mlx = mlx_init();
	map->mlx->windows = mlx_new_window(map->mlx->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "mlx_42");
	map->mlx->image = mlx_new_image(map->mlx->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	map->mlx->data = mlx_get_data_addr(map->mlx->image, &map->mlx->bpp, &map->mlx->size_line, &map->mlx->endian);


}
