/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parallel_projection.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

static	void	fdf_parallel_projection(t_pixel *pixel, int x, int y)
{
	pixel->x_2d = x;
	pixel->y_2d = y;
}

static	void	fdf_apply_parallel(t_pixel *pixels, const int length)
{
	int	x;
	int	y;
	int	pixel;

	if (!pixels || !length)
		return ;
	pixel = 0;
	while (pixel < length)
	{
		x = pixels[pixel].x;
		y = pixels[pixel].y;
		fdf_parallel_projection(&pixels[pixel], x, y);
		pixel ++;
	}
}

void	fdf_apply_parallel_formula(t_matrix *matrix)
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
		fdf_apply_parallel(pixels, length);
		row ++;
	}
}
