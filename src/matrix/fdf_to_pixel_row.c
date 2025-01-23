/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_to_pixel_row.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

static	int	fdf_assign_pixels(const char *row, t_row *result)
{
	int	success;

	success = fdf_extract_pixels(row, result);
	if (!success)
	{
		fdf_free_pixel_row(&result);
		ft_putendl_fd(ERROR_MEMORY, STDERR_FILENO);
		return (0);
	}
	return (1);
}

static	t_row	*fdf_allocate_memory(const char *row)
{
	t_row	*result;
	int		length;

	length = fdf_count_pixels(row);
	if (length == -1)
		return (NULL);
	result = (t_row *) calloc(NEW_ITEM, sizeof(t_row));
	if (!result)
	{
		perror(ERROR_MEMORY);
		return (NULL);
	}
	result->length = length;
	result->pixels = (t_pixel *) calloc(length, sizeof(t_pixel));
	if (!result->pixels)
	{
		free(result);
		perror(ERROR_MEMORY);
		return (NULL);
	}
	return (result);
}

t_row	*fdf_to_pixel_row(const char *row)
{
	t_row	*result;
	int		success;

	result = fdf_allocate_memory(row);
	if (!result)
		return (NULL);
	success = fdf_assign_pixels(row, result);
	if (!success)
		return (NULL);
	return (result);
}
