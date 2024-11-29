/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 08:03:45 by jonnavar          #+#    #+#             */
/*   Updated: 2023/11/14 08:04:03 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_list_map(t_list *list, void *(*f)(void *), void (*d)(void *))
{
	t_list	*pointer;
	t_list	*ptr_first_node;

	if (!list || !f || !d)
		return ((void *) 0);
	ptr_first_node = (void *) 0;
	while (list)
	{
		pointer = ft_list_new((*f)(list->data));
		if (!pointer)
		{
			ft_list_clear(&ptr_first_node, d);
			return ((void *) 0);
		}
		ft_list_add_back(&ptr_first_node, pointer);
		list = list->next_node;
	}
	return (pointer);
}
