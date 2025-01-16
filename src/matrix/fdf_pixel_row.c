/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_matrix_row.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	fdf_free_pixel_row(t_row **row_ptr)
{
	t_pixel	*pixels;
	char	*color;
	int		length;
	int		i;

	if (!row_ptr || !*row_ptr)
		return ;
	i = 0;
	length = (*row_ptr)->length;
	pixels = (*row_ptr)->pixels;
	while (i < length)
	{
		color = pixels[i].color;
		if (color != NULL)
			free(color);
		i ++;
	}
	free(pixels);
	free(*row_ptr);
	*row_ptr = NULL;
}

void	fdf_print_pixel_row(t_row *row)
{
	t_pixel	*pixels;
	char	*color;
	int		length;
	int		i;

	pixels = row->pixels;
	length = row->length;
	i = 0;
	while (i < length)
	{
		color = pixels[i].color;
		ft_printf("(%i,%i,%i)", pixels[i].x, pixels[i].y, pixels[i].z);
		if (color)
			ft_printf(",0x%s", color);
		i ++;
		if (i < length)
			ft_printf(" ");
	}
	ft_printf("\n");
}


void	fdf_assign_y_axis(t_row *row, const int y_axis)
{
	t_pixel	*pixels;
	int		length;
	int		i;

	pixels = row->pixels;
	length = row->length;
	i = 0;
	while (i < length)
	{
		pixels[i].y = y_axis;
		i ++;
	}
}
