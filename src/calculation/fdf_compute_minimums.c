/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_compute_minimums.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

static	void	fdf_minimum_of(t_pixel *pixels, int l, int *min_x, int *min_y)
{
	int	pixel;
	int	x;
	int	y;

	if (!pixels || !l)
		return ;
	pixel = 0;
	while (pixel < l)
	{
		x = pixels[pixel].x;
		y = pixels[pixel].y;
		if (x < *min_x)
			*min_x = x;
		if (y < *min_y)
			*min_y = y;
		pixel ++;
	}
}

void	fdf_compute_minimums(t_data data, int *min_x, int *min_y)
{
	t_row	*rows;
	t_pixel	*pixels;
	int		row;

	if (!data.matrix || !data.matrix->length || !data.matrix->rows[0].length)
		return ;
	rows = data.matrix->rows;
	row = 0;
	*min_x = rows[0].pixels[0].x;
	*min_y = rows[0].pixels[0].y;
	while (row < data.matrix->length)
	{
		pixels = rows[row].pixels;
		fdf_minimum_of(pixels, rows[row].length, min_x, min_y);
		row ++;
	}
}
