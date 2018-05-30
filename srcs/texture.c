#include "wolf.h"

int ft_take_pixel(t_image *img, int x, int y, int dist)
{
	int size;
	int	r;
	int	g;
	int	b;

  if (x < 0 || y < 0 || x >= 32 || y  >= 32)
    return (0x000000);
	size = y * img->size_line + x * img->bpp / 8;
	b = (unsigned char)img->data[size] - dist;
	g = (unsigned char)img->data[size + 1] - dist;
	r = (unsigned char)img->data[size + 2] - dist;
	b = (b < 0) ? 0 : b;
	g = (g < 0) ? 0 : g;
	r = (r < 0) ? 0 : r;
	return (b | g << 8 | r << 16);
}

static t_image *load_image(t_mlx *mlx, char *name)
{
	t_image *img;

	img = NULL;
	if (!(img = malloc(sizeof(t_image))))
		exit (0);
	if (!(img->image = mlx_xpm_file_to_image(mlx,
		name, &img->width, &img->height)))
		exit (0);
	if (!(img->data = mlx_get_data_addr(img->image,
		&img->bpp, &img->size_line, &img->endian)))
		exit (0);
	return (img);
}

void initialisation_texture(t_map *map)
{
  map->texture[0] = load_image(map->mlx, "./texture/metal.xpm");
	map->texture[1] = load_image(map->mlx, "./texture/brick.xpm");
	map->texture[2] = load_image(map->mlx, "./texture/stone.xpm");
	map->texture[3] = load_image(map->mlx, "./texture/wood.xpm");
	if (!(map->mlx->image = mlx_new_image(map->mlx->mlx, SCREEN_WIDTH, SCREEN_HEIGHT)))
		exit(0);
	if (!(map->mlx->data = mlx_get_data_addr(map->mlx->image, &map->mlx->bpp, &map->mlx->size_line, &map->mlx->endian)))
		exit (0);
}
