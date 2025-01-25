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
	fdf_draw_background(*data);
	t_pixel start = (t_pixel){60, 10, 10, 50, 0, NULL, 0xFFFF0000};
	t_pixel end = (t_pixel){10, 50, 10, 50, 0, NULL, 0xFFFF0000};
	fdf_draw_pixel(*data, start);
	fdf_draw_pixel(*data, end);
	start.decimal_color = 0xFF444444;
	end.decimal_color = 0xFF444444;
	fdf_apply_bresenham_formula(*data, start, end);
	mlx_put_image_to_window(data->mlx, data->win, data->img.ptr, x, y);
	return (0);
	fdf_draw_matrix(*data);
}
