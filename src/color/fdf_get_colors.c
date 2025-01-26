/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_get_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int	fdf_get_alpha(int color)
{
	return ((color >> BITS_TO_ALPHA) & HEX_COLOR_MASK);
}

int	fdf_get_red(int color)
{
	return ((color >> BITS_TO_RED) & HEX_COLOR_MASK);
}

int	fdf_get_green(int color)
{
	return ((color >> BITS_TO_GREEN) & HEX_COLOR_MASK);
}

int	fdf_get_blue(int color)
{
	return (color & HEX_COLOR_MASK);
}

int	fdf_new_color(int alpha, int red, int green, int blue)
{
	int	a_component;
	int	r_component;
	int	g_component;

	a_component = alpha << BITS_TO_ALPHA;
	r_component = red << BITS_TO_RED;
	g_component = green << BITS_TO_GREEN;
	return (a_component | r_component | g_component | blue);
}
