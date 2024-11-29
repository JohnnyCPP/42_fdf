/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:01:23 by jonnavar          #+#    #+#             */
/*   Updated: 2024/01/25 16:04:12 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_pf_char(va_list args, int *count)
{
	char	character;

	character = va_arg(args, int);
	ft_putchar_fd(character, 1);
	(*count)++;
}
