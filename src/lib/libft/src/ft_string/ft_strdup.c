/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 20:10:23 by jonnavar          #+#    #+#             */
/*   Updated: 2023/10/31 20:43:12 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *string)
{
	char	*pointer;
	size_t	length;

	if (!string)
		return ((void *) 0);
	length = ft_strlen(string) + 1;
	pointer = (char *) malloc(length * sizeof(char));
	ft_strlcpy(pointer, string, length);
	return (pointer);
}
