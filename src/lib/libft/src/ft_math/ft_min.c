/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:55:21 by jonnavar          #+#    #+#             */
/*   Updated: 2023/10/02 17:56:00 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_dmin(const double a, const double b)
{
	if (a < b)
		return (a);
	return (b);
}

float	ft_fmin(const float a, const float b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ft_imin(const int a, const int b)
{
	if (a < b)
		return (a);
	return (b);
}
