/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_read_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

static	void	fdf_validate_str_matrix(char **matrix)
{
	const char	*row;
	int			is_valid;
	int			i;

	i = 0;
	row = matrix[i];
	while (row != NULL)
	{
		is_valid = fdf_validate_matrix_row(row);
		if (!is_valid)
			fdf_handle_map_failure(&matrix);
		i ++;
		row = matrix[i];
	}
}

static	int	fdf_validate_file_access(const char *path_to_file)
{
	int	fd;

	fd = open(path_to_file, O_RDONLY);
	if (fd == -1)
	{
		perror(ERROR_IO);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

static	void	fdf_validate_argument_name(const char *path_to_file)
{
	char	*extension;
	int		is_different;

	extension = ft_strrchr(path_to_file, '.');
	if (extension)
		is_different = ft_strcmp(extension, FDF_EXTENSION);
	else
		is_different = 1;
	if (is_different)
	{
		ft_putendl_fd(ERROR_EXTENSION, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}

static	void	fdf_validate_argument_count(const int argc)
{
	if (argc != 2)
	{
		ft_putendl_fd(ERROR_ARGC, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}

t_matrix	*fdf_read_map(const int argc, const char **argv)
{
	t_matrix	*matrix;
	const char	*path_to_file;
	char		**str_matrix;
	int			is_readable;
	int			fd;

	fdf_validate_argument_count(argc);
	path_to_file = argv[1];
	fdf_validate_argument_name(path_to_file);
	is_readable = 1;
	fd = fdf_validate_file_access(path_to_file);
	str_matrix = NULL;
	while (is_readable)
		fdf_fill_str_matrix(fd, &str_matrix, &is_readable);
	fdf_validate_str_matrix(str_matrix);
	matrix = fdf_to_matrix((const char **) str_matrix);
	fdf_free_str_matrix(&str_matrix);
	return (matrix);
}
