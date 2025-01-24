/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_get_pixel_address.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

char	*fdf_get_pixel_address(int x, int y, t_image img)
{
	char	*pixel_buffer;
	int		row;
	int		pixel;

	pixel_buffer = img.buf;
	row = y * img.bpl;
	pixel = x * (img.bpp / BYTE);
	return (pixel_buffer + (row + pixel));
}
