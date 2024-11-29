/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 20:05:35 by jonnavar          #+#    #+#             */
/*   Updated: 2023/11/01 20:14:24 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(const char *string, const char *to_join)
{
	char	*pointer;
	size_t	length;
	size_t	join_length;

	if (!string || !to_join)
		return ((void *) 0);
	length = ft_strlen(string);
	join_length = ft_strlen(to_join);
	pointer = (char *) ft_calloc(length + join_length, sizeof(char));
	if (!pointer)
		return ((void *) 0);
	ft_memcpy(pointer, string, length);
	ft_memcpy(pointer + length, to_join, join_length);
	return (pointer);
}
