/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_columns.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

static	void	fdf_join_pixels(t_data *data, t_row *top, t_row *bottom)
{
	t_pixel	*top_pixels;
	t_pixel	*bottom_pixels;
	t_pixel	*start;
	t_pixel	*end;
	int		pixel;

	if (!top || !bottom || !top->length || !bottom->length)
		return ;
	top_pixels = top->pixels;
	bottom_pixels = bottom->pixels;
	pixel = 0;
	while (pixel < top->length && pixel < bottom->length)
	{
		start = &top_pixels[pixel];
		end = &bottom_pixels[pixel];
		fdf_apply_bresenham_formula(data, start, end);
		pixel ++;
	}
}

void	fdf_draw_columns(t_data *data)
{
	t_row	*rows;
	t_row	*top_row;
	t_row	*bottom_row;
	int		row;

	if (!data || !data->matrix || !data->matrix->length)
		return ;
	rows = data->matrix->rows;
	row = 0;
	while (row < data->matrix->length - 1)
	{
		top_row = &rows[row];
		bottom_row = &rows[row + 1];
		fdf_join_pixels(data, top_row, bottom_row);
		row ++;
	}
}
