/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:55:21 by jonnavar          #+#    #+#             */
/*   Updated: 2023/10/02 17:56:00 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *buffer, int character, size_t length)
{
	size_t	index;

	index = 0;
	while (index < length)
	{
		((char *) buffer)[index] = character;
		index ++;
	}
	return (buffer);
}
