/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:23:10 by jonnavar          #+#    #+#             */
/*   Updated: 2023/11/13 09:25:06 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(const char *string, char (*function)(unsigned int, char))
{
	unsigned int	index;
	char			*pointer;
	char			result;

	if (!string || !function)
		return ((void *) 0);
	index = 0;
	pointer = (char *) ft_calloc(ft_strlen(string) + 1, sizeof(char));
	while (string[index])
	{
		result = (*function)(index, string[index]);
		pointer[index ++] = result;
	}
	return (pointer);
}
