/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_interpolate_color.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

static	int	fdf_interpolation_formula(int s, int e, double f, int (*gc)(int))
{
	int	start_component;
	int	end_component;

	start_component = gc(s);
	end_component = gc(e);
	return (start_component + f * (end_component - start_component));
}

int	fdf_interpolate_color(int start, int end, double factor)
{
	int	alpha;
	int	red;
	int	green;
	int	blue;

	alpha = fdf_interpolation_formula(start, end, factor, fdf_get_alpha);
	red = fdf_interpolation_formula(start, end, factor, fdf_get_red);
	green = fdf_interpolation_formula(start, end, factor, fdf_get_green);
	blue = fdf_interpolation_formula(start, end, factor, fdf_get_blue);
	return (fdf_new_color(alpha, red, green, blue));
}
