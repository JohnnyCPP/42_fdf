/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_scaling.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

static	void	fdf_safely_scale(int *axis, const double factor)
{
	if (fdf_is_product_safe((const double) *axis, factor))
		*axis = fdf_round(*axis * factor);
	else
	{
		if (*axis > 0)
			*axis = INT_MAX;
		else
			*axis = INT_MIN;
	}
}

static	void	fdf_scale_pixels(t_pixel *pixels, int len, const double factor)
{
	int	pixel;

	if (!pixels || !len)
		return ;
	pixel = 0;
	while (pixel < len)
	{
		fdf_safely_scale(&pixels[pixel].x_2d, factor);
		fdf_safely_scale(&pixels[pixel].y_2d, factor);
		pixel ++;
	}
}

void	fdf_apply_scaling(t_data *data, const double scaling_factor)
{
	t_row	*rows;
	t_pixel	*pixels;
	int		row;

	if (!data || !data->matrix || !data->matrix->length)
		return ;
	rows = data->matrix->rows;
	row = 0;
	while (row < data->matrix->length)
	{
		pixels = rows[row].pixels;
		fdf_scale_pixels(pixels, rows[row].length, scaling_factor);
		row ++;
	}
}
