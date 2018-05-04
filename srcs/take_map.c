/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 15:38:11 by vferreir          #+#    #+#             */
/*   Updated: 2018/05/04 17:56:56 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int take_map(t_map *map, char *name)
{
	char *line;
	char **ret;
	int fd;
	int i;
	int j;

	fd = open(name, O_RDONLY);
	map->carte = malloc(sizeof(char *) * 10000);
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		map->carte[i] = malloc(sizeof(char) * 10000);
		ret = ft_strsplit(line, ' ');
		j = -1;
		while (ret[++j])
			map->carte[i][j] = ret[j][0];
		map->carte_x = j;
		i++;
		j = -1;
		while (ret[++j])
			free(ret[j]);
		free(ret);
	}
	map->carte_y = i;
	return (0);
}
