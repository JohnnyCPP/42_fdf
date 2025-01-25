/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bresenham.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

static	void	fdf_decide_position(t_delta *delta)
{
	delta->decision = delta->error * TIMES_TWO;
	if (delta->decision > -delta->y_delta)
	{
		delta->error -= delta->y_delta;
		delta->start->x_2d += delta->x_step;
	}
	if (delta->decision < delta->x_delta)
	{
		delta->error += delta->x_delta;
		delta->start->y_2d += delta->y_step;
	}
}

static	int	fdf_is_end_of_line(t_delta *delta)
{
	int	x_start;
	int	x_end;
	int	y_start;
	int	y_end;

	x_start = delta->start->x_2d;
	x_end = delta->end->x_2d;
	y_start = delta->start->y_2d;
	y_end = delta->end->y_2d;
	if (x_start == x_end && y_start == y_end)
		return (1);
	return (0);
}

static	void	fdf_compute_steps(t_delta *delta)
{
	int	x_start;
	int	x_end;
	int	y_start;
	int	y_end;

	x_start = delta->start->x_2d;
	x_end = delta->end->x_2d;
	y_start = delta->start->y_2d;
	y_end = delta->end->y_2d;
	if (x_start < x_end)
		delta->x_step = INCREASE;
	else
		delta->x_step = DECREASE;
	if (y_start < y_end)
		delta->y_step = INCREASE;
	else
		delta->y_step = DECREASE;
}

static	void	fdf_compute_deltas(t_delta *delta)
{
	int	x_start;
	int	x_end;
	int	y_start;
	int	y_end;

	x_start = delta->start->x_2d;
	x_end = delta->end->x_2d;
	y_start = delta->start->y_2d;
	y_end = delta->end->y_2d;
	delta->x_delta = ft_abs(x_end - x_start);
	delta->y_delta = ft_abs(y_end - y_start);
}

void	fdf_apply_bresenham_formula(t_data d, t_pixel start, t_pixel end)
{
	t_delta	delta;

	delta.start = &start;
	delta.end = &end;
	fdf_compute_deltas(&delta);
	fdf_compute_steps(&delta);
	delta.error = delta.x_delta - delta.y_delta;
	while (!fdf_is_end_of_line(&delta))
	{
		fdf_decide_position(&delta);
		if (fdf_is_end_of_line(&delta))
			break ;
		fdf_draw_pixel(d, *delta.start);
	}
}
