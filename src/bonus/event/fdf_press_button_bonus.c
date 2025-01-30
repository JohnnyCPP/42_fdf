/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_press_button_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

static	void	fdf_modify_focal_length(t_data *data, double focal_length)
{
	double	new_value;

	new_value = data->focal_length + focal_length;
	if (new_value < MINIMUM_FOCAL_LENGTH)
		new_value = MINIMUM_FOCAL_LENGTH;
	else if (new_value > MAXIMUM_FOCAL_LENGTH)
		new_value = MAXIMUM_FOCAL_LENGTH;
	data->focal_length = new_value;
	fdf_apply_conical_formula(data->matrix, data->focal_length);
	fdf_compute_initial_scaling(data);
	fdf_apply_translation_formula(data);
}

int	fdf_press_button(int button, int mouse_x, int mouse_y, void *d_ptr)
{
	t_data	*data;

	data = (t_data *) d_ptr;
	if (button == MOUSE_LEFT_BUTTON)
	{
		data->mouse.is_dragging = 1;
		data->mouse.last_x = mouse_x;
		data->mouse.last_y = mouse_y;
	}
	else if (data->projection != CONICAL && button == MOUSE_SCROLL_UP)
		fdf_apply_scaling(data, SCALE_UP);
	else if (data->projection != CONICAL && button == MOUSE_SCROLL_DOWN)
		fdf_apply_scaling(data, SCALE_DOWN);
	else if (data->projection == CONICAL && button == MOUSE_SCROLL_UP)
		fdf_modify_focal_length(data, -INCREMENT_FOCAL_LENGTH);
	else if (data->projection == CONICAL && button == MOUSE_SCROLL_DOWN)
		fdf_modify_focal_length(data, INCREMENT_FOCAL_LENGTH);
	return (0);
}
