/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_iterate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 08:03:45 by jonnavar          #+#    #+#             */
/*   Updated: 2023/11/14 08:04:03 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_list_iterate(t_list *list, void (*function)(void *))
{
	t_list	*pointer;

	if (!list || !function)
		return ;
	pointer = list;
	while (pointer)
	{
		(*function)(pointer->data);
		pointer = pointer->next_node;
	}
}
