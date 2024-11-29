/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:01:23 by jonnavar          #+#    #+#             */
/*   Updated: 2024/01/25 16:04:12 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_pf_str(va_list args, int *count)
{
	char		*string;
	size_t		length;

	string = va_arg(args, char *);
	length = ft_strlen(string);
	ft_putstr_fd(string, 1);
	*count += length;
}
