/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 08:03:45 by jonnavar          #+#    #+#             */
/*   Updated: 2023/11/14 08:04:03 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_list_new(void *data)
{
	t_list	*pointer;

	pointer = (t_list *) ft_calloc(1, sizeof(t_list));
	if (!pointer)
		return ((void *) 0);
	pointer->data = data;
	pointer->next_node = NULL;
	return (pointer);
}
