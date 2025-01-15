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

void	fdf_free_row_array(t_matrix *matrix)
{
	int	i;

	if (!matrix)
		return ;
	i = 0;
	while (i < matrix->length)
	{
		free(matrix->rows[i].pixels);
		matrix->rows[i].pixels = NULL;
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

void	fdf_move_row_array(t_row *destination, const t_row *source, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		destination[i].length = source[i].length;
		destination[i].pixels = source[i].pixels;
		i ++;
	}
}

void	fdf_push_row(t_row *row_array, t_row *row, int length)
{
	row_array[length - 1].length = row->length;
	row_array[length - 1].pixels = row->pixels;
}
