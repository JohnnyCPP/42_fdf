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
	ft_printf("DEBUG: key pressed with keysym=%i\n", keysym);
	if (keysym == XK_a)
	{
		ft_printf("DEBUG: rotating counterclockwise...\n");
		//	rotate counterclockwise
		fdf_rotate_z(data, COUNTERCLOCKWISE);
		fdf_apply_isometric_rotation(data->matrix);
		fdf_apply_scaling(data, data->scaling);
	}
	else if (keysym == XK_d)
	{
		ft_printf("DEBUG: rotating clockwise...\n");
		//	rotate clockwise
		fdf_rotate_z(data, CLOCKWISE);
		fdf_apply_isometric_rotation(data->matrix);
		fdf_apply_scaling(data, data->scaling);
	}
	return (0);
}
