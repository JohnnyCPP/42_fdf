/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_declare_events_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	fdf_declare_bonus_events(t_data *data)
{
	long	x_event;
	long	x_mask;

	x_event = ButtonPress;
	x_mask = ButtonPressMask;
	mlx_hook(data->win, x_event, x_mask, fdf_press_button, data);
	x_event = ButtonRelease;
	x_mask = ButtonReleaseMask;
	mlx_hook(data->win, x_event, x_mask, fdf_release_button, data);
	x_event = MotionNotify;
	x_mask = PointerMotionMask;
	mlx_hook(data->win, x_event, x_mask, fdf_move_mouse, data);
}
