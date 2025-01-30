/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_conical_projection.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

static	void	fdf_apply_conical(t_pixel *pixels, int length, double focal)
{
	int	x;
	int	y;
	int	z;
	int	pixel;

	if (!pixels || !length)
		return ;
	pixel = 0;
	while (pixel < length)
	{
		x = pixels[pixel].x;
		y = pixels[pixel].y;
		z = pixels[pixel].z;
		if (z + focal <= 0)
			return ;
		pixels[pixel].x_2d = ((double) x * focal) / ((double) z + focal);
		pixels[pixel].y_2d = ((double) y * focal) / ((double) z + focal);
		pixel ++;
	}
}

void	fdf_apply_conical_formula(t_matrix *matrix, double focal_length)
{
	t_row	*rows;
	t_pixel	*pixels;
	int		length;
	int		row;

	if (!matrix || !matrix->length)
		return ;
	rows = matrix->rows;
	row = 0;
	while (row < matrix->length)
	{
		length = rows[row].length;
		pixels = rows[row].pixels;
		fdf_apply_conical(pixels, length, focal_length);
		row ++;
	}
}
