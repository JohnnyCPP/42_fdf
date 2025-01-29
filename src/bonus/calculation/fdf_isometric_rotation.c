/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_isometric_rotation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

static	void	fdf_apply_isometric(t_pixel *pixels, const int length)
{
	double	x;
	double	y;
	double	z;
	int		pixel;

	if (!pixels || !length)
		return ;
	pixel = 0;
	while (pixel < length)
	{
		x = pixels[pixel].rot_x;
		y = pixels[pixel].rot_y;
		z = pixels[pixel].rot_z;
		fdf_isometric_projection(&pixels[pixel], x, y, z);
		pixel ++;
	}
}

void	fdf_apply_isometric_rotation(t_matrix *matrix)
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
