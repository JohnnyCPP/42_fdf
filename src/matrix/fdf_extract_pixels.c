/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_extract_pixels.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

static	int	fdf_get_length(const char *row, int i)
{
	int	length;

	length = 0;
	if (ft_issign(row[i]))
	{
		length ++;
		i ++;
	}
	while (ft_isdigit(row[i]))
	{
		length ++;
		i ++;
	}
	return (length);
}

static	int	fdf_get_number(const char *row, int i, t_row *result, int pixel)
{
	char	*copy;
	int		length;
	int		overflows;
	int		number;

	length = fdf_get_length(row, i);
	copy = (char *) calloc(length + 1, sizeof(char));
	if (!copy)
	{
		perror(ERROR_MEMORY);
		return (0);
	}
	ft_strlcpy(copy, row + i, length + 1);
	overflows = ft_ioverflow(copy);
	if (overflows)
	{
		free(copy);
		ft_putendl_fd(ERROR_IOVERFLOW, STDERR_FILENO);
		return (0);
	}
	number = ft_atoi(copy);
	result->pixels[pixel].value = number;
	free(copy);
	return (1);
}

static	int	fdf_allocate(const char *row, int *i, int pixel, t_row *result)
{
	char	*color;
	int		color_len;

	color_len = 6;
	color = (char *) calloc(color_len + 1, sizeof(char));
	if (!color)
	{
		perror(ERROR_MEMORY);
		return (0);
	}
	ft_strlcpy(color, row + *i, color_len + 1);
	result->pixels[pixel].color = color;
	(*i) += color_len;
	return (1);
}

static	int	fdf_get_color(const char *row, int *i, int *pixel, t_row *result)
{
	int	comma_found;
	int	prefix_len;
	int	success;

	comma_found = fdf_is_comma_present(row, *i);
	if (comma_found)
	{
		while (ft_isspace(row[*i]))
			(*i)++;
		if (row[*i] == ',')
			(*i)++;
		while (ft_isspace(row[*i]))
			(*i)++;
		prefix_len = 2;
		(*i) += prefix_len;
		if (*pixel >= result->length)
			return (1);
		success = fdf_allocate(row, i, *pixel, result);
		if (!success)
			return (0);
	}
	else if (*pixel >= result->length)
		result->pixels[*pixel].color = NULL;
	(*pixel)++;
	return (1);
}

int	fdf_extract_pixels(const char *row, t_row *result)
{
	int	i;
	int	pixel;
	int	success;

	i = 0;
	pixel = 0;
	while (row[i] != '\0')
	{
		while (ft_isspace(row[i]))
			i ++;
		if (row[i] == '\0')
			break ;
		if (ft_issign(row[i]) || ft_isdigit(row[i]))
		{
			success = fdf_get_number(row, i, result, pixel);
			if (!success)
				return (0);
		}
		while (row[i] != '\0' && ft_isdigit(row[i]))
			i ++;
		success = fdf_get_color(row, &i, &pixel, result);
		if (!success)
			return (0);
	}
	return (1);
}
