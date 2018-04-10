/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 14:34:53 by vferreir          #+#    #+#             */
/*   Updated: 2018/04/03 21:07:04 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	initialize(t_list *ptr)
{
	ptr->name_proprio = NULL;
	ptr->name_groupe = NULL;
	ptr->name_link = NULL;
	ptr->next = NULL;
	ptr->nb_block = 0;
	ptr->time = 0;
	ptr->size_total = 0;
	ptr->protection = 0;
	ptr->size_name = 0;
	ptr->nb_lien = 0;
	ptr->type = 0;
	ptr->add_slash = 0;
}

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*ptr;

	if (!(ptr = malloc(sizeof(t_list))))
		return (0);
	if (!(ptr->content = malloc(content_size)))
		return (0);
	if (content != NULL)
	{
		ptr->content = ft_memcpy(ptr->content, content, content_size);
		ptr->content_size = content_size;
	}
	else
	{
		ptr->content = NULL;
		ptr->content_size = 0;
	}
	initialize(ptr);
	return (ptr);
}
