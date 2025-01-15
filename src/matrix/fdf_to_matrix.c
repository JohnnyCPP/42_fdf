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

static	int	fdf_push_to(t_matrix *matrix, char *current_string)
{
	t_row	*old_rows;
	t_row	*new_rows;
	t_row	*row_to_add;

	row_to_add = fdf_to_pixel_row(current_string);
	if (!row_to_add)
		return (0);
	//	create an array of rows of "i+1" rows
	new_rows = fdf_new_row_array(matrix->length + 1);
	if (!new_rows)
	{
		fdf_free_pixel_row(&row_to_add);
		return (0);
	}
	//	copy "matrix->rows" to "new_rows"
	fdf_move_row_array(new_rows, matrix->rows, matrix->length);
	//	add "row_to_add" to "new_rows"
	fdf_push_row(new_rows, row_to_add, matrix->length + 1);
	old_rows = matrix->rows;
	matrix->rows = new_rows;
	matrix->length ++;
	//	free "old_rows"
	free(old_rows);
	return (1);
}

t_matrix	*fdf_to_matrix(char ***matrix_ptr)
{
	t_matrix	*result;
	char		**str_matrix;
	char		*current_string;
	int			i;
	int			success;

	result = (t_matrix *) calloc(1, sizeof(t_matrix));
	if (!result)
		return (NULL);
	result->length = 0;
	result->rows = NULL;
	i = 0;
	str_matrix = *matrix_ptr;
	current_string = str_matrix[i];
	while (current_string != NULL)
	{
		success = fdf_push_to(result, current_string);
		if (!success)
		{
			fdf_free_matrix(&result);
			return (NULL);
		}
		i ++;
		current_string = str_matrix[i];
	}
	return (result);
}
