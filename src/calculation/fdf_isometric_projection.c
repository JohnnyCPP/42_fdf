/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_isometric_projection.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

static	double	fdf_to_radians(const double degrees)
{
	return (degrees * (M_PI / 180));
}

void	fdf_isometric_projection(int *x, int *y, const int z)
{
	double	delta;
	double	sum;
	double	cosine;
	double	sine;
	double	radians;

	delta = *x - *y;
	sum = *x + *y;
	radians = fdf_to_radians(30.0);
	cosine = cos(radians);
	sine = sin(radians);
	*x = (int)(delta * cosine + 0.5);
	*y = (int)(sum * sine - z + 0.5);
}

static	void	fdf_apply_isometric(t_pixel *pixels, const int length)
{
	int	*x;
	int	*y;
	int	z;
	int	pixel;

	pixel = 0;
	while (pixel < length)
	{
		x = &pixels[pixel].x;
		y = &pixels[pixel].y;
		z = pixels[pixel].z;
		fdf_isometric_projection(x, y, z);
		pixel ++;
	}
}

void	fdf_apply_projection_formula(t_matrix *matrix)
{
	t_row	*rows;
	t_pixel	*pixels;
	int		length;
	int		row;

	rows = matrix->rows;
	row = 0;
	while (row < matrix->length)
	{
		length = rows[row].length;
		pixels = rows[row].pixels;
		fdf_apply_isometric(pixels, length);
		row ++;
	}
}
