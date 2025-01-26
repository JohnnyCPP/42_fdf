/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_rows.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

static	void	fdf_join_pixels(t_data *data, t_pixel *pixels, int length)
{
	t_pixel	*start;
	t_pixel	*end;
	int		pixel;

	if (!pixels || !length)
		return ;
	pixel = 0;
	while (pixel < (length - 1))
	{
		start = pixels + pixel;
		end = pixels + pixel + 1;
		fdf_apply_bresenham_formula(data, start, end);
		pixel ++;
	}
}

void	fdf_draw_rows(t_data *data)
{
	t_row	*rows;
	t_pixel	*pixels;
	int		row;

	if (!data || !data->matrix || !data->matrix->length)
		return ;
	rows = data->matrix->rows;
	row = 0;
	while (row < data->matrix->length)
	{
		pixels = rows[row].pixels;
		fdf_join_pixels(data, pixels, rows[row].length);
		row ++;
	}
}
