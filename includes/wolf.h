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
#include <fcntl.h>


# define SCREEN_WIDTH 1280
# define SCREEN_HEIGHT 720
# define PI 3.14159265
# define DEGREE 3.14159265 / 180
# define DISTANCE 1108
# define SIZE 64
# define VITESSE 16
# define ROTATION 4

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
	char **carte;
	double pos_x;
	double pos_y;
	int angle;
	int carte_x;
	int carte_y;
}				         t_map;

typedef struct s_v
{
	double angle;
	double pos_x;
	double pos_y;
	double step_x;
	double step_y;
	int		up;
	int		bottom;
	int		right;
	int		left;
}								t_v;


void mini_map(t_map *map);
int take_map(t_map *map, char *name);
void 			test(t_map *map);
int				motion_hook(int x, int y, t_map *map);
void			initialisation_minilibix(t_map *map);
void			ft_put_pixel(t_mlx *mlx, int x, int y, int couleur);
void			ft_clean_image(t_map *map);
int				my_key_funct(int keycode, t_map *map);
int				my_mouse_funct(int keycode, int pos_x, int pos_y, t_map *map);
void draw_colonne(t_v *v, t_mlx *mlx, int colonne, int i);
void	set_value(t_map *map);
int			fct_key(int keycode, t_map *map);
int do_change(t_map *map);
