/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_round.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int	fdf_round(const double value)
{
	double	rounded;

	rounded = value + ROUND_NEAREST_INT;
	if (rounded > (double) INT_MAX)
		return (INT_MAX);
	if (rounded < (double) INT_MIN)
		return (INT_MIN);
	return ((int) rounded);
}
