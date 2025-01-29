/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_initial_scaling.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

static	double	fdf_get_factor(t_data *data, double delta_x, double delta_y)
{
	double	scaling_factor_x;
	double	scaling_factor_y;
	double	factor;

	if (delta_x == 0.0 || delta_y == 0.0)
		return (DEFAULT_FACTOR);
	scaling_factor_x = (double) data->win_w / delta_x;
	scaling_factor_y = (double) data->win_h / delta_y;
	if (scaling_factor_x < scaling_factor_y)
		factor = scaling_factor_x;
	else
		factor = scaling_factor_y;
	return (factor);
}

static	double	fdf_compute_scaling_factor(t_data *data)
{
	double	min_x;
	double	min_y;
	double	max_x;
	double	max_y;
	double	scaling_factor;

	min_x = 0;
	min_y = 0;
	max_x = 0;
	max_y = 0;
	fdf_compute_minimums(data, &min_x, &min_y);
	fdf_compute_maximums(data, &max_x, &max_y);
	scaling_factor = fdf_get_factor(data, max_x - min_x, max_y - min_y);
	scaling_factor *= INITIAL_SCALING_OFFSET;
	return (scaling_factor);
}

void	fdf_compute_initial_scaling(t_data *data)
{
	double	scaling_factor;

	if (!data->matrix || !data->matrix->length)
		return ;
	scaling_factor = fdf_compute_scaling_factor(data);
	fdf_apply_scaling(data, scaling_factor);
}
