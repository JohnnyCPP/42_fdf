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

static	char	*fdf_get_address(int x, int y, t_image img)
{
	char	*buffer;
	int		row;
	int		pixel;

	buffer = img.buf;
	row = y * img.bpl;
	pixel = x * (img.bpp / BYTE);
	return (buffer + (row + pixel));
}

static	int	fdf_out_of_bounds(int x, int y, t_image img)
{
	if (x < 0 || y < 0 || img.w <= x || img.h <= y)
		return (1);
	return (0);
}

static	void	fdf_draw_pixel(t_data *data, t_pixel pixel)
{
	t_image			*img;
	unsigned int	*pixel_address;
	unsigned int	color;
	int				x;
	int				y;

	color = pixel.decimal_color;
	x = pixel.x_2d;
	y = pixel.y_2d;
	img = &data->img;
	if (fdf_out_of_bounds(x, y, *img))
		return ;
	pixel_address = (unsigned int *) fdf_get_address(x, y, *img);
	if (!color)
		color = COLOR_WHITE;
	*pixel_address = color;
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
