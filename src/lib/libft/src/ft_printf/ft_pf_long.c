/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:01:23 by jonnavar          #+#    #+#             */
/*   Updated: 2024/01/25 16:04:12 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_pf_long(va_list args, int *count)
{
	long	value;
	char	*string;
	int		length;

	value = va_arg(args, long);
	string = ft_ltoa(value);
	ft_putstr_fd(string, 1);
	length = ft_strlen(string);
	*count += length;
	free(string);
}
