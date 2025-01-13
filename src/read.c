/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
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

static	void	fdf_handle_mem_failure(char ***matrix_ptr)
{
	fdf_free_str_matrix(matrix_ptr);
	perror(ERROR_MEMORY);
	exit(EXIT_FAILURE);
}

static	void	fdf_add_to_matrix(const char *next_line, char ***matrix_ptr)
{
	char	**old_matrix;
	char	**new_matrix;
	char	*new_string;
	int		matrix_length;
	int		string_length;

	old_matrix = *matrix_ptr;
	matrix_length = fdf_str_matrix_length(old_matrix);
	new_matrix = ft_calloc(matrix_length + 2, sizeof(char *));
	if (!new_matrix)
		fdf_handle_mem_failure(matrix_ptr);
	fdf_str_matrix_shallow_copy(new_matrix, old_matrix, matrix_length);
	string_length = ft_strlen(next_line) + 1;
	new_string = ft_calloc(string_length, sizeof(char));
	if (!new_string)
		fdf_handle_mem_failure(matrix_ptr);
	ft_strlcpy(new_string, next_line, string_length);
	new_matrix[matrix_length] = new_string;
	new_matrix[matrix_length + 1] = NULL;
	free(old_matrix);
	*matrix_ptr = new_matrix;
}

void	fdf_fill_str_matrix(int fd, char ***matrix_ptr, int *is_readable)
{
	char	*next_line;

	next_line = ft_gnl(fd);
	if (next_line)
	{
		fdf_add_to_matrix(next_line, matrix_ptr);
		free(next_line);
	}
	else
		*is_readable = 0;
}
