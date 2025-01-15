/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_count_pixels.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

static	void	fdf_find_color(const char *row, int *i)
{
	int	length_of_hex;
	int	comma_found;

	comma_found = fdf_is_comma_present(row, *i);
	if (comma_found)
	{
		while (ft_isspace(row[*i]))
			(*i)++;
		if (row[*i] == ',')
			(*i)++;
		while (ft_isspace(row[*i]))
			(*i)++;
		length_of_hex = 8;
		(*i) += length_of_hex;
	}
}

static	int	fdf_find_number(const char *row, int *i, int *pixels)
{
	while (ft_isspace(row[*i]))
		(*i)++;
	if (ft_issign(row[*i]))
		(*i)++;
	if (ft_isdigit(row[*i]))
	{
		if (*pixels == INT_MAX)
		{
			ft_putendl_fd(ERROR_ROW_LENGTH, STDERR_FILENO);
			return (0);
		}
		(*pixels)++;
	}
	while (row[*i] != '\0' && ft_isdigit(row[*i]))
		(*i)++;
	return (1);
}

int	fdf_count_pixels(const char *row)
{
	int	pixels;
	int	i;
	int	success;

	pixels = 0;
	i = 0;
	while (row[i] != '\0')
	{
		success = fdf_find_number(row, &i, &pixels);
		if (!success)
			return (-1);
		fdf_find_color(row, &i);
	}
	return (pixels);
}
