/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_render_frame.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int	fdf_render_frame(void *data_ptr)
{
	t_data	*data;
	int		x;
	int		y;

	data = (t_data *) data_ptr;
	x = 0;
	y = 0;
	fdf_draw_projection(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.ptr, x, y);
	return (0);
}
