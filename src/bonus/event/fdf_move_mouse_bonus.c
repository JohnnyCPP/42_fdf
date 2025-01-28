/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_move_mouse_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int	fdf_move_mouse(int mouse_x, int mouse_y, void *d_ptr)
{
	t_data	*data;
	double	delta_x;
	double	delta_y;

	data = (t_data *) d_ptr;
	if (data->mouse.is_dragging)
	{
		delta_x = (double)(mouse_x - data->mouse.last_x);
		delta_y = (double)(mouse_y - data->mouse.last_y);
		fdf_translation(data, delta_x, delta_y);
		data->mouse.last_x = mouse_x;
		data->mouse.last_y = mouse_y;
	}
	return (0);
}
