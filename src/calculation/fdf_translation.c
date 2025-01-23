/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_translation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

static	void	fdf_apply_translation(t_data data, int min_x, int min_y)
{
	t_row	*rows;
	t_pixel	*pixels;
	int		row;
	int		pixel;

	if (!data.matrix || !data.matrix->length || !data.matrix->rows[0].length)
		return ;
	rows = data.matrix->rows;
	row = 0;
	while (row < data.matrix->length)
	{
		pixels = rows[row].pixels;
		if (pixels)
		{
			pixel = 0;
			while (pixel < rows[row].length)
			{
				pixels[pixel].x_2d -= min_x;
				pixels[pixel].y_2d -= min_y;
				pixel ++;
			}
		}
		row ++;
	}
}

void	fdf_apply_translation_formula(t_data data)
{
	int	min_x;
	int	min_y;

	if (!data.matrix || !data.matrix->length)
		return ;
	//	1. determine minimum coordinates
	min_x = 0;
	min_y = 0;
	fdf_compute_minimums(data, &min_x, &min_y);
	//	2. apply the translation
	fdf_apply_translation(data, min_x, min_y);
	//	3. ensure it fits within image dimensions
	//	    - after translating, the "x" and "y" values should fit within 
	//	      the image's width and height
	//	    - if the image is too small to accommodate the entire projection, 
	//        either:
	//          - scale the matrix down
	//          - increase the image size
}
