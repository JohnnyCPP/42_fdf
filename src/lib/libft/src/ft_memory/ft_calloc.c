/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 20:10:23 by jonnavar          #+#    #+#             */
/*   Updated: 2023/10/31 20:25:03 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t amount, size_t size)
{
	void	*pointer;
	size_t	index;

	index = 0;
	pointer = malloc(amount * size);
	if (pointer == 0)
		return ((void *) 0);
	while (index < amount)
		((char *) pointer)[index ++] = 0;
	return (pointer);
}
