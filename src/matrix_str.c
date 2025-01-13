/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	fdf_str_matrix_print(char **matrix)
{
	char	*current_string;
	int		i;

	ft_printf("Printing the matrix...\n\n");
	i = 0;
	current_string = matrix[0];
	while (current_string)
	{
		ft_printf("%s\n", current_string);
		i ++;
		current_string = matrix[i];
	}
}

int	fdf_str_matrix_length(char **matrix)
{
	int		matrix_length;

	if (!matrix)
		return (0);
	matrix_length = 0;
	while (matrix[matrix_length])
		matrix_length ++;
	return (matrix_length);
}

void	fdf_str_matrix_shallow_copy(char **dest, char **source, int length)
{
	int	matrix_length;
	int	i;
	
	if (!dest || !source)
		return ;
	matrix_length = fdf_str_matrix_length(source);
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
