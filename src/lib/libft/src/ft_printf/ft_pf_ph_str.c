/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_ph_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:01:23 by jonnavar          #+#    #+#             */
/*   Updated: 2024/01/25 19:02:01 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_pf_ph_str(char const ph, va_list args, int *i, int *count)
{
	*i += 2;
	if (ph == 'c')
		ft_pf_char(args, count);
	else if (ph == 's')
		ft_pf_str(args, count);
	else
		ft_pf_ptr(args, count);
}
