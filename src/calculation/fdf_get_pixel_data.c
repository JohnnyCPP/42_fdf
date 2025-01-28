/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_get_pixel_data.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	fdf_get_pixel_data(t_delta *delta, t_pixel *s, t_pixel *e)
{
	delta->start_x = s->x_2d;
	delta->start_y = s->y_2d;
	delta->start_color = s->decimal_color;
	delta->end_x = e->x_2d;
	delta->end_y = e->y_2d;
	delta->end_color = e->decimal_color;
}
