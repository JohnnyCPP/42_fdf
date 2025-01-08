/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int	close_window(void *parameter)
{
	(void) parameter;
	exit(0);
}

int	render_frame(void *parameters)
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

int	main(const int argc, const char **argv)
{
	(void) argc;
	(void) argv;
	void	*minilibx;
	void	*window;
	void	*image;
	void	*parameters[3];
	char	*image_address;
	int		bits_in_byte;
	//		bits per pixel
	int		bpp;
	int		line_length;
	int		endianess;
	int		w_width;
	int		w_height;
	int		pixel_index;

	bits_in_byte = 8;
	w_width = 1000;
	w_height = 800;
	minilibx = mlx_init();
	if (!minilibx)
	{
		ft_printf("Error: MLX initialization failed.\n");
		return (1);
	}
	window = mlx_new_window(minilibx, w_width, w_height, "Test window");
	if (!window)
	{
		ft_printf("Error: window initialization failed.\n");
		return (1);
	}
	mlx_hook(window, 17, 0, close_window, NULL);
	image = mlx_new_image(minilibx, w_width, w_height);
	if (!image)
		ft_printf("Error: failed to create image.\n");
	image_address = mlx_get_data_addr(image, &bpp, &line_length, &endianess);
	for (int y = 100; y < (w_height - 100); y ++)
	{
		for (int x = 100; x < (w_width - 100); x ++)
		{
			pixel_index = (y * line_length) + (x * (bpp / bits_in_byte));
			image_address[pixel_index + 0] = 0x44; //	blue ?
			image_address[pixel_index + 1] = 0x00; //	green ?
			image_address[pixel_index + 2] = 0x44; //	red ?
			image_address[pixel_index + 3] = 0xFF; //	alpha ?
		}
	}
	/*
	for (int y = 0; y < w_height; y ++)
		for (int x = 0; x < w_width; x ++)
			*(int *)(image_address + (y * line_length + x * (bpp / bits_in_byte))) = 0x00FF00;
	*/
	mlx_put_image_to_window(minilibx, window, image, 0, 0);
	parameters[0] = minilibx;
	parameters[1] = window;
	parameters[2] = image;
	mlx_loop_hook(minilibx, render_frame, parameters);
	mlx_loop(minilibx);
	return (0);
}
