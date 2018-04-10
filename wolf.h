/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 16:04:36 by vferreir          #+#    #+#             */
/*   Updated: 2018/04/06 16:04:37 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "mlx_keycode.h"
# include "mlx.h"
# include "libft.h"
# include <stdlib.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# define SCREEN_WIDTH 320
# define SCREEN_HEIGHT 200
# define PI 3.14159265
# define DISTANCE 277
# define SIZE 64



#include <stdio.h>

typedef struct	s_mlx
{
	void		*mlx;
	void		*windows;
	void		*image;
	void		*image_menu;
	char		*data_menu;
	char		*data;
	int			endian;
	int			bpp;
	int			size_line;
}				t_mlx;

typedef struct	s_map
{
	t_mlx *mlx;
	int			key_hook[300];
	double pos_x;
	double pos_y;
	double angle;
	int carte_x;
	int carte_y;
}				         t_map;

void 			test(t_map *map);
int				motion_hook(int x, int y, t_map *map);
void			initialisation_minilibix(t_map *map);
void			ft_put_pixel(t_mlx *mlx, int x, int y, int couleur);
void			ft_clean_image(t_map *map);
int				my_key_funct(int keycode, t_map *map);
int				my_mouse_funct(int keycode, int pos_x, int pos_y, t_map *map);
void draw_colonne(t_mlx *mlx, int colonne, int i);
