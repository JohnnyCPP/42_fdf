/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 20:10:23 by jonnavar          #+#    #+#             */
/*   Updated: 2023/10/30 20:10:36 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static	void	ft_add_value(const char *value, int *index, int *buffer)
{
	int	digit;

	digit = value[*index] - '0';
	*buffer *= 10;
	*buffer += digit;
	(*index)++;
}

int	ft_atoi(const char *value)
{
	int	index;
	int	buffer;
	int	sign;

	if (!value)
		return (0);
	index = 0;
	buffer = 0;
	sign = 1;
	while (ft_isspace(value[index]))
		index ++;
	if (value[index] == '-')
		sign *= -1;
	while (ft_issign(value[index]))
		index ++;
	while (ft_isdigit(value[index]))
		ft_add_value(value, &index, &buffer);
	if (value[index] == '\0')
		return (sign * buffer);
	return (0);
}
