/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	fdf_draw_matrix(t_data *data)
{
	t_matrix	*matrix;
	t_row		*rows;
	t_pixel		*pixels;
	int			y;
	int			x;

	matrix = data->matrix;
	rows = matrix->rows;
	y = 0;
	while (y < matrix->length)
	{
		pixels = rows[y].pixels;
		x = 0;
		while (x < rows[y].length)
		{
			fdf_draw_pixel(data, pixels[x]);
			x ++;
		}
		y ++;
	}
}
