/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_pixel_color.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

static	int	fdf_out_of_bounds(int x, int y, t_image *img)
{
	if (x < 0 || y < 0 || img->w <= x || img->h <= y)
		return (1);
	return (0);
}

void	fdf_draw_pixel_color(t_data *d, int x, int y, unsigned int c)
{
	t_image			img;
	unsigned int	*pixel_address;

	img = d->img;
	if (fdf_out_of_bounds(x, y, &img))
		return ;
	pixel_address = (unsigned int *) fdf_get_pixel_address(x, y, &img);
	if (!c)
		c = COLOR_WHITE;
	*pixel_address = c;
}
