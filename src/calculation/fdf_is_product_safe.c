/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_is_product_safe.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int	fdf_is_product_safe(const double a, const double b)
{
	double	absolute_of_a;
	double	absolute_of_b;

	if (a < 0)
		absolute_of_a = (double) -a;
	else
		absolute_of_a = (double) a;
	if (b < 0)
		absolute_of_b = (double) -b;
	else
		absolute_of_b = (double) b;
	if (absolute_of_a > (double) INT_MAX / absolute_of_b)
		return (0);
	return (1);
}
