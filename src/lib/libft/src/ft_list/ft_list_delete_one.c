/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_delete_one.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 08:03:45 by jonnavar          #+#    #+#             */
/*   Updated: 2023/11/14 08:04:03 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_list_delete_one(t_list *list, void (*function)(void *))
{
	if (!list)
		return ;
	(*function)(list->data);
	list->data = (void *) 0;
	free(list);
}
