/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

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

char	**fdf_read_map(const int argc, const char **argv)
{
	const	char	*path_to_file;
	char			**matrix;
	int				is_readable;
	int				fd;

	fdf_validate_argument_count(argc);
	path_to_file = argv[1];
	fdf_validate_argument_name(path_to_file);
	is_readable = 1;
	fd = fdf_validate_file_access(path_to_file);
	matrix = NULL;
	while (is_readable)
		fdf_fill_str_matrix(fd, &matrix, &is_readable);
	return (matrix);
}
