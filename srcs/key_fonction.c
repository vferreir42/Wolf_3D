/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_fonction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 16:19:44 by vferreir          #+#    #+#             */
/*   Updated: 2018/04/12 15:23:49 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void move_w(t_map *map)
{
	int x;
	int y;

	x = map->pos_x + cos(map->angle * DEGREE) * VITESSE;
	y = map->pos_y - sin(map->angle * DEGREE) * VITESSE;

	//if (x >= 0 && y >= 0 && x / SIZE < map->carte_x && y / SIZE < map->carte_y
	//	&& map->carte[(int)(y / SIZE)][(int)(x / SIZE)] == '0')
	//{
		map->pos_x = x;
		map->pos_y = y;
	//}

}

void move_s(t_map *map)
{
	int x;
	int y;

	x = map->pos_x - cos(map->angle * DEGREE) * VITESSE;
	y = map->pos_y + sin(map->angle * DEGREE) * VITESSE;
	if (x >= 0 && y >= 0 && x / SIZE < map->carte_x && y / SIZE < map->carte_y
		&& map->carte[(int)(y / SIZE)][(int)(x / SIZE)] == '0')
		{
			map->pos_x = x;
			map->pos_y = y;
		}
}

int loop_hook(t_map *map)
{
	map->last_frame = clock();
	if (map->next_frame > map->last_frame)
		return (0);
//	printf("loop_hook\n");
	map->next_frame = map->last_frame + (CLOCKS_PER_SEC / 30);
	if (map->move_a)
		map->angle += ROTATION;
	if (map->move_d)
		map->angle -= ROTATION;
	if (map->move_w)
		move_w(map);
	if (map->move_s)
		move_s(map);
	test(map);
	mlx_put_image_to_window(map->mlx->mlx, map->mlx->windows, map->mlx->image, 0, 0);
	return (0);
}

void change(int keycode, t_map *map)
{
	if (keycode == D_KEY)
		map->move_d = !map->move_d;
	else if (keycode == A_KEY)
		map->move_a = !map->move_a;
	else if (keycode == W_KEY)
		map->move_w = !map->move_w;
	else if (keycode == S_KEY)
		map->move_s = !map->move_s;
//	else if (map->key_hook[UP_KEY])
//		map->hauteur += 5;
//	else if (map->key_hook[DOWN_KEY])
//		map->hauteur -= 5;
}

int			fct_key(int keycode, t_map *map)
{
	change(keycode, map);
	return (0);
}

int			my_key_funct(int keycode, t_map *map)
{
	change(keycode, map);
	return (0);
}
