/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 21:06:10 by jonnavar          #+#    #+#             */
/*   Updated: 2023/10/08 21:10:04 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t length)
{
	size_t	index;

	if (!destination && !source)
		return (destination);
	index = 0;
	while (index < length)
	{
		((char *) destination)[index] = ((char *) source)[index];
		index ++;
	}
	return (destination);
}
