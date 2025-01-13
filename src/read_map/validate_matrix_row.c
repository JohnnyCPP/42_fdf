/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_matrix_row.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

static	int	fdf_parse_matrix_color(const char *row, int *i)
{
	char	*hex_prefix;
	int		hex_prefix_len;
	int		j;

	if (row[*i] == ',')
		(*i)++;
	while (ft_isspace(row[*i]))
		(*i)++;
	hex_prefix = "0x";
	hex_prefix_len = ft_strlen(hex_prefix);
	if (ft_strncmp(hex_prefix, row + (*i), hex_prefix_len) == 0)
	{
		(*i) += hex_prefix_len;
		j = 0;
		while (row[*i] != '\0' && ft_ishex(row[*i]))
		{
			j ++;
			(*i)++;
		}
		if (j != 6)
			return (0);
	}
	return (1);
}

static	int	fdf_parse_matrix_digit(const char *row, int *i)
{
	while (ft_isspace(row[*i]))
		(*i)++;
	if (row[*i] == '+' || row[*i] == '-')
		(*i)++;
	if (!ft_isdigit(row[*i]))
		return (0);
	while (ft_isdigit(row[*i]))
		(*i)++;
	while (ft_isspace(row[*i]))
		(*i)++;
	return (1);
}

int	fdf_validate_matrix_row(const char *row)
{
	int	i;

	i = 0;
	while (row[i] != '\0')
	{
		if (!fdf_parse_matrix_digit(row, &i))
			return (0);
		if (ft_isdigit(row[i]))
			continue ;
		if (!fdf_parse_matrix_color(row, &i))
			return (0);
		if (row[i] != '\0' && !ft_isspace(row[i]))
			return (0);
		while (ft_isspace(row[i]))
			i ++;
	}
	return (1);
}
