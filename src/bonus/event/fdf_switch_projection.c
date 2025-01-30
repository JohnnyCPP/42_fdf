/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_switch_projection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

static	void	fdf_switch_to_isometric(t_data *data)
{
	fdf_apply_projection_formula(data->matrix);
	fdf_compute_initial_scaling(data);
	fdf_apply_translation_formula(data);
}

static	void	fdf_switch_to_conical(t_data *data)
{
	data->focal_length = DEFAULT_FOCAL_LENGTH;
	fdf_apply_conical_formula(data->matrix, data->focal_length);
	fdf_compute_initial_scaling(data);
	fdf_apply_translation_formula(data);
}

static	void	fdf_switch_to_parallel(t_data *data)
{
	fdf_apply_parallel_formula(data->matrix);
	fdf_compute_initial_scaling(data);
	fdf_apply_translation_formula(data);
}

void	fdf_switch_projection(t_data *data)
{
	if (data->projection == ISOMETRIC)
	{
		fdf_switch_to_parallel(data);
		data->projection = PARALLEL;
	}
	else if (data->projection == PARALLEL)
	{
		fdf_switch_to_conical(data);
		data->projection = CONICAL;
	}
	else if (data->projection == CONICAL)
	{
		fdf_switch_to_isometric(data);
		data->projection = ISOMETRIC;
	}
}
