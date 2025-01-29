/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rotate_z.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

static	void	fdf_rotate_coordinates(t_pixel *pixel, const double angle)
{
	double	cosine;
	double	sine;

	cosine = cos(angle);
	sine = sin(angle);
	pixel->rot_x = pixel->x * cosine - pixel->y * sine;
	pixel->rot_y = pixel->x * sine + pixel->y * cosine;
}

static	int	fdf_struct_is_null(t_data *data)
{
	if (!data || !data->matrix || !data->matrix->length)
		return (1);
	if (!data->matrix->rows[0].length)
		return (1);
	return (0);
}

void	fdf_rotate_z(t_data *data, const double angle)
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
			{
				fdf_rotate_coordinates(&pixels[pixel], angle);
				pixel ++;
			}
		}
		row ++;
	}
}
