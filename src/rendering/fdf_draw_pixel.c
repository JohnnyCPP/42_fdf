/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_pixel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

static	int	fdf_out_of_bounds(int x, int y, t_image *img)
{
	if (x < 0 || y < 0 || img->w <= x || img->h <= y)
		return (1);
	return (0);
}

void	fdf_draw_pixel(t_data *data, t_pixel *pixel)
{
	t_image			img;
	unsigned int	*pixel_address;
	unsigned int	color;
	int				x;
	int				y;

	color = pixel->decimal_color;
	x = fdf_round(pixel->x_2d);
	y = fdf_round(pixel->y_2d);
	img = data->img;
	if (fdf_out_of_bounds(x, y, &img))
		return ;
	pixel_address = (unsigned int *) fdf_get_pixel_address(x, y, &img);
	if (!color)
		color = COLOR_WHITE;
	*pixel_address = color;
}
