/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:01:23 by jonnavar          #+#    #+#             */
/*   Updated: 2024/01/25 16:04:12 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_pf_int(va_list args, int *count)
{
	int		value;
	char	*string;
	int		length;

	value = va_arg(args, int);
	string = ft_itoa(value);
	if (!string)
		return ;
	ft_putstr_fd(string, 1);
	length = ft_strlen(string);
	*count += length;
	free(string);
}
