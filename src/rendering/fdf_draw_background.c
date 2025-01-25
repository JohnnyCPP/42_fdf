/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_background.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	fdf_draw_background(t_data data)
{
	unsigned int	*pixel;
	int				y;
	int				x;

	y = 0;
	while (y < data.win_h)
	{
		x = 0;
		while (x < data.win_w)
		{
			pixel = (unsigned int *) fdf_get_pixel_address(x, y, data.img);
			*pixel = COLOR_BLACK;
			x ++;
		}
		y ++;
	}
}
