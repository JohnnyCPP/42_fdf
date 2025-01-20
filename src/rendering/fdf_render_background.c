/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_render_background.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

static	void	fdf_render_little_endian(t_data *data)
{
	char	*pixel;
	int		line_offset;
	int		pixel_offset;
	int		y;
	int		x;

	y = 0;
	while (y < data->win_h)
	{
		x = 0;
		while (x < data->win_w)
		{
			line_offset = y * data->img.bpl;
			pixel_offset = x * (data->img.bpp / BYTE);
			pixel = data->img.buf + (line_offset + pixel_offset);
			*(unsigned int *) pixel = LE_BLUE;
			x ++;
		}
		y ++;
	}
}

static	void	fdf_render_big_endian(t_data *data)
{
	char	*pixel;
	int		line_offset;
	int		pixel_offset;
	int		y;
	int		x;

	y = 0;
	while (y < data->win_h)
	{
		x = 0;
		while (x < data->win_w)
		{
			line_offset = y * data->img.bpl;
			pixel_offset = x * (data->img.bpp / BYTE);
			pixel = data->img.buf + (line_offset + pixel_offset);
			*(unsigned int *) pixel = BE_BLUE;
			x ++;
		}
		y ++;
	}
}

void	fdf_render_background(t_data *data)
{
	if (data->img.end == 0)
		fdf_render_little_endian(data);
	else if (data->img.end == 1)
		fdf_render_big_endian(data);
}
