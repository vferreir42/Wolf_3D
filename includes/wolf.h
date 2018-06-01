/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 16:04:36 by vferreir          #+#    #+#             */
/*   Updated: 2018/06/01 17:39:47 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "mlx_keycode.h"
# include "mlx.h"
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <time.h>
# include <fcntl.h>

# define SCREEN_WIDTH 1280
# define SCREEN_HEIGHT 720
# define PI 3.14159265
# define DEGREE 3.14159265 / 180
# define DISTANCE 1108
# define SIZE 64
# define VITESSE 8
# define ROTATION 4

typedef struct	s_mlx
{
	void		*mlx;
	void		*windows;
	void		*image;
	char		*data;
	int			endian;
	int			bpp;
	int			size_line;
}				t_mlx;

typedef struct	s_image
{
	void		*image;
	char		*data;
	int			size_line;
	int			bpp;
	int			endian;
	int			width;
	int			height;
}				t_image;

typedef struct	s_map
{
	t_mlx		*mlx;
	t_image		*texture[4];
	int			key_hook[300];
	char		**carte;
	double		pos_x;
	double		pos_y;
	int			mode;
	int			tex;
	int			hauteur;
	int			angle;
	int			offset_hor;
	int			offset_ver;
	int			offset;
	int			carte_x;
	int			carte_y;
	int			move_a;
	int			move_w;
	int			move_s;
	int			move_d;
	clock_t		last_frame;
	clock_t		next_frame;
}				t_map;

typedef struct	s_v
{
	double		angle;
	double		pos_x;
	double		pos_y;
	double		step_x;
	double		step_y;
	double		rest;
}				t_v;

typedef struct	s_lst
{
	char			*content;
	struct s_lst	*next;
}				t_lst;

void			mini_map(t_map *map);
int				initialisation_map(t_map *map, char *name);
void			initialisation_minilibix(t_map *map);
void			initialisation_texture(t_map *map);

int				ft_take_pixel(t_image *img, int x, int y, int dist);
void			calcul_colonne(t_map *map);
void			draw_colonne(t_map *map, int colonne, int i);

int				loop_hook(t_map *map);
int				motion_hook(int x, int y, t_map *map);
void			ft_put_pixel(t_mlx *mlx, int x, int y, int couleur);
int				my_mouse_funct(int keycode, int pos_x, int pos_y, t_map *map);
int				fct_key(int keycode, t_map *map);

#endif
