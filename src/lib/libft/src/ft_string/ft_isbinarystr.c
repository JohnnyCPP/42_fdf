/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isbinarystr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:55:21 by jonnavar          #+#    #+#             */
/*   Updated: 2023/10/02 17:56:00 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isbinarystr(const char *character)
{
	if (!character)
		return (0);
	while (*character)
	{
		if (!ft_isbinary(*character))
			return (0);
		character ++;
	}
	return (1);
}
