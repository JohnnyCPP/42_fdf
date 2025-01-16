/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_to_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

static	int	fdf_push_to(t_matrix *matrix, const char *str_row)
{
	t_row	*auxiliar;
	t_row	*new_rows;
	t_row	*old_rows;

	//	how do I get "x" coordinate?
	//		each pixel in the row has it, from 0 to 'n'
	//		"fdf_extract_pixels()" can take care of that
	//	how do I get "y" coordinate?
	//		the current "matrix->length" is the "y" coordinate
	//		create a new function to assign this value
	//		"fdf_assign_y_axis"
	//	the "z" coordinate is just the "value"
	//		"value" can be renamed to "z"
	auxiliar = fdf_to_pixel_row(str_row);
	if (!auxiliar)
		return (0);
	fdf_assign_y_axis(auxiliar, matrix->length);
	new_rows = fdf_new_row_array(matrix->length + 1);
	if (!new_rows)
	{
		fdf_free_pixel_row(&auxiliar);
		return (0);
	}
	old_rows = matrix->rows;
	fdf_move_row_array(new_rows, old_rows, matrix->length);
	fdf_push_row(new_rows, auxiliar, matrix->length + 1);
	matrix->rows = new_rows;
	matrix->length ++;
	free(old_rows);
	free(auxiliar);
	return (1);
}

static	int	fdf_push_all(t_matrix *matrix, const char **str_matrix)
{
	const char	*str_row;
	int			success;
	int			i;

	i = 0;
	str_row = str_matrix[i];
	while (str_row != NULL)
	{
		success = fdf_push_to(matrix, str_row);
		if (!success)
		{
			fdf_free_matrix(&matrix);
			return (0);
		}
		i ++;
		str_row = str_matrix[i];
	}
	return (1);
}

t_matrix	*fdf_to_matrix(const char **str_matrix)
{
	t_matrix	*matrix;
	int			success;

	matrix = (t_matrix *) calloc(1, sizeof(t_matrix));
	if (!matrix)
		return (NULL);
	matrix->length = 0;
	matrix->rows = NULL;
	success = fdf_push_all(matrix, str_matrix);
	if (!success)
		return (NULL);
	return (matrix);
}
