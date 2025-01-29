/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_set_rotation_cord.c                            :+:      :+:    :+:   */
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

void	fdf_set_rotation_cord(t_data *data)
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
				pixels[pixel].rot_x = (double) pixels[pixel].x;
				pixels[pixel].rot_y = (double) pixels[pixel].y;
				pixels[pixel].rot_z = (double) pixels[pixel].z;
				pixel ++;
			}
		}
		row ++;
	}
}
