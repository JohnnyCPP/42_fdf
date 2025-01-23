/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hex_to_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

static	int	fdf_is_hex(const char *hex)
{
	int	i;
	int	hex_length;

	if (!hex)
		return (0);
	i = 0;
	hex_length = HEX_COLOR_LENGTH;
	while (hex[i] != '\0')
	{
		if (!ft_ishex(hex[i]) || i >= hex_length)
			return (0);
		i ++;
	}
	if (i != hex_length)
		return (0);
	return (1);
}

int	fdf_to_int(const char *hex)
{
	unsigned int	result;
	unsigned int	digit;
	unsigned int	i;

	if (!fdf_is_hex(hex))
		return (-1);
	result = 0;
	i = 0;
	while (hex[i] != '\0')
	{
		if (ft_isdigit(hex[i]))
			digit = hex[i] - '0';
		else if ('A' <= hex[i] && hex[i] <= 'F')
			digit = hex[i] - 'A' + HEX_A;
		else if ('a' <= hex[i] && hex[i] <= 'a')
			digit = hex[i] - 'a' + HEX_A;
		result *= HEX_BASE;
		result += digit;
		i ++;
	}
	return (result);
}
