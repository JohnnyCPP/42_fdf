/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_row_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

static	void	fdf_free_pixel_colors(t_pixel **pixels, int length)
{
	char	*color;
	int		pixel;

	if (!pixels || !*pixels)
		return ;
	pixel = 0;
	while (pixel < length)
	{
		color = (*pixels)[pixel].color;
		if (color != NULL)
			free(color);
		pixel ++;
	}
	free(*pixels);
	*pixels = NULL;
}

void	fdf_free_row_array(t_matrix *matrix)
{
	t_pixel	**pixels;
	int		length;
	int		i;

	if (!matrix)
		return ;
	i = 0;
	while (i < matrix->length)
	{
		pixels = &matrix->rows[i].pixels;
		length = matrix->rows[i].length;
		fdf_free_pixel_colors(pixels, length);
		i ++;
	}
	free(matrix->rows);
	matrix->rows = NULL;
}

t_row	*fdf_new_row_array(int length)
{
	t_row	*rows;

	rows = (t_row *) calloc(length, sizeof(t_row));
	if (!rows)
		return (NULL);
	return (rows);
}

void	fdf_move_row_array(t_row *dest, const t_row *source, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		dest[i].length = source[i].length;
		dest[i].pixels = source[i].pixels;
		i ++;
	}
}

void	fdf_push_row(t_row *row_array, t_row *row, int length)
{
	int	last_row;

	last_row = length - 1;
	row_array[last_row].length = row->length;
	row_array[last_row].pixels = row->pixels;
}
