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
	else if (button == MOUSE_SCROLL_UP)
	{
		data->scaling += 0.1;
		fdf_apply_scaling(data, SCALE_UP);
	}
	else if (button == MOUSE_SCROLL_DOWN)
	{
		data->scaling -= 0.1;
		fdf_apply_scaling(data, SCALE_DOWN);
	}
	return (0);
}
