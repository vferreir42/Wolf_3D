/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 15:38:11 by vferreir          #+#    #+#             */
/*   Updated: 2018/06/01 14:47:30 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static t_lst	*new_maillon(char *str)
{
	t_lst *new;

	new = NULL;
	if (!(new = malloc(sizeof(t_lst))))
		return (NULL);
	if (str == NULL)
		new->content = NULL;
	else
		new->content = ft_strdup(str);
	new->next = NULL;
	return (new);
}

static t_lst	*read_map(t_lst *new, int fd)
{
	t_lst	*tmp;
	char	*line;

	tmp = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (new == NULL)
		{
			if (!(new = new_maillon(line)))
				exit(0);
			tmp = new;
		}
		else
		{
			if (!(tmp->next = new_maillon(line)))
				exit(0);
			tmp = tmp->next;
		}
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return (new);
}

static void		parsing_map(t_map *map, t_lst *new)
{
	int count;
	int i;

	count = 0;
	map->carte_x = ft_strlen(new->content);
	while (new)
	{
		if ((int)ft_strlen(new->content) != map->carte_x)
			exit(0);
		i = -1;
		while (new->content[++i])
		{
			if (new->content[i] < '0' || new->content[i] > '2')
				exit(0);
		}
		count++;
		new = new->next;
	}
	map->carte_y = count;
}

static void		created_map(t_map *map, t_lst *new)
{
	int		i;
	t_lst	*tmp;

	if (!(map->carte = malloc(sizeof(char *) * (map->carte_y + 1))))
		exit(0);
	i = 0;
	while (new)
	{
		tmp = new;
		if (!(map->carte[i] = ft_strdup(new->content)))
			exit(0);
		ft_strdel(&new->content);
		new = new->next;
		free(tmp);
		i++;
	}
	map->carte[i] = NULL;
}

int				initialisation_map(t_map *map, char *name)
{
	t_lst	*new;
	int		fd;
	int		y;

	new = NULL;
	map->carte = NULL;
	if ((fd = open(name, O_RDONLY)) == -1)
		exit(0);
	if (!(new = read_map(new, fd)))
		exit(0);
	parsing_map(map, new);
	created_map(map, new);
	y = -1;
	while (map->carte[++y] && !ft_strchr(map->carte[y], '0'))
		;
	if (map->carte[y] && ft_strchr(map->carte[y], '0'))
	{
		map->pos_y = y * SIZE;
		map->pos_x = (ft_strlen(map->carte[y])
		- ft_strlen(ft_strchr(map->carte[y], '0'))) * SIZE;
	}
	else
		exit(0);
	close(fd);
	return (0);
}
