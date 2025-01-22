/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_background.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	fdf_draw_background(t_data *data)
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
			*(unsigned int *) pixel = COLOR_BLACK;
			x ++;
		}
		y ++;
	}
}
