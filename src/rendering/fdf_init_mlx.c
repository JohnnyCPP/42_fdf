/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init_mlx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

static	void	fdf_declare_events(t_data *data)
{
	mlx_hook(data->win, KeyPress, KeyPressMask, fdf_key_pressed, data);
	mlx_hook(data->win, DestroyNotify, StructureNotifyMask, fdf_close, data);
}

void	fdf_init_mlx(t_data *data)
{
	t_image	*i;

	data->mlx = mlx_init();
	if (!data->mlx)
		fdf_handle_mlx_failure(data);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, TITLE);
	if (!data->win)
		fdf_handle_win_failure(data);
	data->win_w = WIDTH;
	data->win_h = HEIGHT;
	fdf_declare_events(data);
	data->img.ptr = mlx_new_image(data->mlx, data->win_w, data->win_h);
	if (!data->img.ptr)
		fdf_handle_img_failure(data);
	data->img.w = data->win_w;
	data->img.h = data->win_h;
	i = &data->img;
	data->img.buf = mlx_get_data_addr(i->ptr, &i->bpp, &i->bpl, &i->end);
	if (!data->img.buf)
		fdf_handle_buffer_failure(data);
}
