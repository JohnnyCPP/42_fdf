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

static	void	fdf_scale_matrix_down(t_data *data, double max_x, double max_y)
{
	double	width_ratio;
	double	height_ratio;
	double	scaling_factor;

	if (!data || !data->matrix || !data->matrix->length)
		return ;
	width_ratio = (double) data->img.w / max_x;
	height_ratio = (double) data->img.h / max_y;
	scaling_factor = ft_dmin(width_ratio, height_ratio);
	if (scaling_factor < DEFAULT_FACTOR)
		fdf_apply_scaling(data, scaling_factor);
}

static	int	fdf_struct_is_null(t_data *data)
{
	if (!data || !data->matrix || !data->matrix->length)
		return (1);
	if (!data->matrix->rows[0].length)
		return (1);
	return (0);
}

static	void	fdf_apply_translation(t_data *data, double min_x, double min_y)
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
				pixels[pixel].x_2d -= min_x;
				pixels[pixel].y_2d -= min_y;
				pixel ++;
			}
		}
		row ++;
	}
}

void	fdf_apply_translation_formula(t_data *data)
{
	double	min_x;
	double	min_y;
	double	max_x;
	double	max_y;

	if (!data || !data->matrix || !data->matrix->length)
		return ;
	min_x = 0;
	min_y = 0;
	fdf_compute_minimums(data, &min_x, &min_y);
	fdf_apply_translation(data, min_x, min_y);
	max_x = 0;
	max_y = 0;
	fdf_compute_maximums(data, &max_x, &max_y);
	fdf_scale_matrix_down(data, max_x, max_y);
}
