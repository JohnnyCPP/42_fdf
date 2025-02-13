/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_matrix_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	fdf_free_str_matrix(char ***matrix_ptr)
{
	char	**matrix;
	int		i;

	if (!*matrix_ptr)
		return ;
	i = 0;
	matrix = *matrix_ptr;
	while (matrix[i])
	{
		free(matrix[i]);
		i ++;
	}
	free(matrix);
	*matrix_ptr = NULL;
}

void	fdf_print_str_matrix(char **matrix)
{
	char	*current_string;
	int		i;

	i = 0;
	current_string = matrix[0];
	while (current_string)
	{
		ft_printf("%s\n", current_string);
		i ++;
		current_string = matrix[i];
	}
}

int	fdf_get_strmat_len(char **matrix)
{
	int		matrix_length;

	if (!matrix)
		return (0);
	matrix_length = 0;
	while (matrix[matrix_length])
		matrix_length ++;
	return (matrix_length);
}

void	fdf_copy_strmat(char **dest, char **source, int length)
{
	int	matrix_length;
	int	i;

	if (!dest || !source)
		return ;
	matrix_length = fdf_get_strmat_len(source);
	i = 0;
	if (length > matrix_length)
		length = matrix_length;
	while (i < length)
	{
		dest[i] = source[i];
		i ++;
	}
	dest[i] = NULL;
}
