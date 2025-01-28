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
		delta->start_x += delta->x_step;
	}
	if (delta->decision < delta->x_delta)
	{
		delta->error += delta->x_delta;
		delta->start_y += delta->y_step;
	}
}

static	int	fdf_is_end_of_line(t_delta *delta)
{
	int	x_start;
	int	x_end;
	int	y_start;
	int	y_end;

	x_start = (int) delta->start_x;
	x_end = (int) delta->end_x;
	y_start = (int) delta->start_y;
	y_end = (int) delta->end_y;
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

	x_start = (int) delta->start_x;
	x_end = (int) delta->end_x;
	y_start = (int) delta->start_y;
	y_end = (int) delta->end_y;
	if (x_start < x_end)
		delta->x_step = INCREASE;
	else
		delta->x_step = DECREASE;
	if (y_start < y_end)
		delta->y_step = INCREASE;
	else
		delta->y_step = DECREASE;
	if (ft_abs(delta->x_delta) > ft_abs(delta->y_delta))
		delta->steps = ft_abs(delta->x_delta);
	else
		delta->steps = ft_abs(delta->y_delta);
}

static	void	fdf_compute_deltas(t_delta *delta)
{
	int	x_start;
	int	x_end;
	int	y_start;
	int	y_end;

	x_start = (int) delta->start_x;
	x_end = (int) delta->end_x;
	y_start = (int) delta->start_y;
	y_end = (int) delta->end_y;
	delta->x_delta = ft_abs(x_end - x_start);
	delta->y_delta = ft_abs(y_end - y_start);
}

void	fdf_apply_bresenham_formula(t_data *d, t_pixel *s, t_pixel *e)
{
	t_delta	delta;
	int		current_x;
	int		current_y;

	fdf_get_pixel_data(&delta, s, e);
	fdf_compute_deltas(&delta);
	fdf_compute_steps(&delta);
	delta.error = delta.x_delta - delta.y_delta;
	delta.current_step = 0;
	while (!fdf_is_end_of_line(&delta))
	{
		fdf_apply_interpolation(&delta);
		fdf_decide_position(&delta);
		if (fdf_is_end_of_line(&delta))
			break ;
		current_x = fdf_round(delta.start_x);
		current_y = fdf_round(delta.start_y);
		fdf_draw_pixel_color(d, current_x, current_y, delta.color);
		delta.current_step ++;
	}
}
