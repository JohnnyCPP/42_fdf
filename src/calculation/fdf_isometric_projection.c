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
	return (degrees * (M_PI / PI_RADIAN_DEGREES));
}

void	fdf_isometric_projection(t_pixel *pixel, int x, int y, int z)
{
	double	delta;
	double	sum;
	double	cosine;
	double	sine;
	double	radians;

	delta = x - y;
	sum = x + y;
	radians = fdf_to_radians(ISOMETRIC_CONV_ROT_ANG);
	cosine = cos(radians);
	sine = sin(radians);
	pixel->x_2d = fdf_round(delta * cosine);
	pixel->y_2d = fdf_round(sum * sine - (double) z);
}

static	void	fdf_apply_isometric(t_pixel *pixels, const int length)
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
		fdf_isometric_projection(&pixels[pixel], x, y, z);
		pixel ++;
	}
}

void	fdf_apply_projection_formula(t_matrix *matrix)
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
		fdf_apply_isometric(pixels, length);
		row ++;
	}
}
