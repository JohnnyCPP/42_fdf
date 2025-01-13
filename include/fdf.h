/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FDF_H
# define FDF_H

# define ERROR_ARGC "Usage: ./fdf <filename.fdf>"
# define ERROR_EXTENSION "The map file doesn't contain the " \
						 "expected file extension (.fdf)"
# define ERROR_IO "Error opening file"
# define ERROR_MEMORY "Memory allocation error"
# define FDF_EXTENSION ".fdf"

# include "libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>

int		fdf_close_window(void *parameter);
int		fdf_render_frame(void *parameters);
char	**fdf_read_map(const int argc, const char **argv);
void	fdf_fill_str_matrix(int fd, char ***data_read, int *is_readable);
int		fdf_str_matrix_length(char **matrix);
void	fdf_str_matrix_shallow_copy(char **dest, char **source, int length);
void	fdf_str_matrix_print(char **matrix);
void	fdf_free_str_matrix(char ***matrix_ptr);

#endif
