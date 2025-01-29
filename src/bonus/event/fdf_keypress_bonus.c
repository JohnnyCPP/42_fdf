/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keypress_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int	fdf_handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_a)
	{
		fdf_rotate_2d(data, COUNTERCLOCKWISE);
		fdf_apply_translation_formula(data);
	}
	else if (keysym == XK_d)
	{
		fdf_rotate_2d(data, CLOCKWISE);
		fdf_apply_translation_formula(data);
	}
	else if (keysym == XK_Escape)
		fdf_close((void *) data);
	return (0);
}
