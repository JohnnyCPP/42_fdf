/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int	fdf_render_frame(void *parameters)
{
	void	**ptr_to_parameters;
	void	*minilibx;
	void	*window;
	void	*image;

	ptr_to_parameters = (void **) parameters;
	minilibx = ptr_to_parameters[0];
	window = ptr_to_parameters[1];
	image = ptr_to_parameters[2];
	mlx_put_image_to_window(minilibx, window, image, 0, 0);
	return (0);
}
