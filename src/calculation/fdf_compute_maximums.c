/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_compute_maximums.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

static	void	fdf_maximum_of(t_pixel *pixels, int l, int *max_x, int *max_y)
{
	int	pixel;
	int	x;
	int	y;

	if (!pixels || !l)
		return ;
	pixel = 0;
	while (pixel < l)
	{
		x = pixels[pixel].x_2d;
		y = pixels[pixel].y_2d;
		if (x > *max_x)
			*max_x = x;
		if (y > *max_y)
			*max_y = y;
		pixel ++;
	}
}

void	fdf_compute_maximums(t_data data, int *max_x, int *max_y)
{
	t_row	*rows;
	t_pixel	*pixels;
	int		row;

	if (!data.matrix || !data.matrix->length || !data.matrix->rows[0].length)
		return ;
	rows = data.matrix->rows;
	row = 0;
	*max_x = rows[0].pixels[0].x_2d;
	*max_y = rows[0].pixels[0].y_2d;
	while (row < data.matrix->length)
	{
		pixels = rows[row].pixels;
		fdf_maximum_of(pixels, rows[row].length, max_x, max_y);
		row ++;
	}
}
