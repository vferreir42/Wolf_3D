#include "wolf.h"

void print(t_map *map, int j, int x)
{
  int count_j;
  int count_x;

  count_j = j;
  if (j + 16 <= SCREEN_HEIGHT && x + 16 <= SCREEN_WIDTH)
  {
    while (++count_j < j + 16)
    {
      count_x = x;
      while (++count_x < x + 16)
        ft_put_pixel(map->mlx, count_x, count_j, 0xFFFFFF);
    }
  }
}

void print_direction(t_map *map, double angle, int i)
{
  int t;
  int x;
  int j;

  angle -= 30;
  t = 0;
  while (++t < 60)
  {
    j = cos(angle * PI / 180) * i;
    x = sin(angle * PI / 180) * i;
    ft_put_pixel(map->mlx, j + 88, 88 - x, 0xE8D630);
    angle += 1;
  }
}

void add_cross(t_map *map)
{
  int i;
  int j;
  int x;

  j = -1;
  while (++j < 6)
  {
    x = -1;
    while (++x < 6)
      ft_put_pixel(map->mlx, 85 + x, 85 + j, 0x850606);
  }
  i = -1;
  while (++i < 40)
    print_direction(map, map->angle, i);
}

void set_in_black(t_map *map)
{
  int j;
  int x;

  j = -1;
  while (++j < 177)
  {
    x = -1;
    while (++x < 177)
      ft_put_pixel(map->mlx, j, x, 0x000000);
  }
}

void mini_map(t_map *map)
{
  int x;
  int j;
  int count_j;
  int count_x;

  set_in_black(map);
  j = (int)floor(map->pos_y / SIZE);
  j -= 6;
  count_j = -1;
  while (++count_j < 11)
  {
    j++;
    if (j >= 0 && map->carte[(int)floor(map->pos_y / SIZE)])
    {
      x = (int)floor(map->pos_x / SIZE);
      x -= 6;
      count_x = -1;
      while (++count_x < 11)
      {
        x++;
        if (x >= 0 && map->carte[j][x] && map->carte[j][x] == '1')
            print(map, count_j * 16, count_x * 16);
      }
    }
  }
  add_cross(map);
}
