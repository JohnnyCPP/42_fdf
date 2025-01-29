/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_translation_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

static	int	fdf_struct_is_null(t_data *data)
{
	if (!data || !data->matrix || !data->matrix->length)
		return (1);
	if (!data->matrix->rows[0].length)
		return (1);
	return (0);
}

static	int	fdf_modify_coords(t_pixel *pixel, double x, double y)
{
	pixel->x_2d += x;
	pixel->y_2d += y;
	return (1);
}

void	fdf_translation(t_data *data, double x, double y)
{
	t_row	*rows;
	t_pixel	*pixels;
	int		row;
	int		pixel;

	if (fdf_struct_is_null(data))
		return ;
	rows = data->matrix->rows;
	row = 0;
	while (row < data->matrix->length)
	{
		pixels = rows[row].pixels;
		if (pixels)
		{
			pixel = 0;
			while (pixel < rows[row].length)
				pixel += fdf_modify_coords(&pixels[pixel], x, y);
		}
		row ++;
	}
}
