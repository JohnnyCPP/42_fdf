/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_apply_interpolation.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	fdf_apply_interpolation(t_delta *delta)
{
	double	factor;
	int		start;
	int		end;

	if (delta->steps == 0)
		delta->factor = 0.0;
	else
		delta->factor = (double) delta->current_step / (double) delta->steps;
	factor = delta->factor;
	start = (int) delta->start->decimal_color;
	end = (int) delta->end->decimal_color;
	delta->color = (unsigned int) fdf_interpolate_color(start, end, factor);
	delta->start->decimal_color = delta->color;
}
