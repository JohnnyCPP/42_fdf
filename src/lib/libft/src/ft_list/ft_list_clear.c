/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 08:03:45 by jonnavar          #+#    #+#             */
/*   Updated: 2023/11/14 08:04:03 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_list_clear(t_list **list, void (*function)(void *))
{
	t_list	*pointer;
	t_list	*auxiliar;

	if (!list || !function)
		return ;
	pointer = *list;
	auxiliar = pointer->next_node;
	while (pointer)
	{
		(*function)(pointer->data);
		free(pointer);
		pointer = auxiliar;
		if (auxiliar)
			auxiliar = auxiliar->next_node;
	}
	*list = (void *) 0;
}
