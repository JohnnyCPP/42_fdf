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

static	void	fdf_draw_pixel(t_data *data, t_pixel pixel)
{
	t_image	*img;
	char	*pixel_address;
	int		x;
	int		y;

	x = pixel.x;
	y = pixel.y;
	img = &data->img;
	if (x < 0 || y < 0 || img->w <= x || img->h <= y)
		return ;
	pixel_address = img->buf + ((y * img->bpl) + (x * (img->bpp / BYTE)));
	*(unsigned int *) pixel_address = COLOR_WHITE;
}

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
