/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int	main(const int argc, const char **argv)
{
	void	*minilibx;
	void	*window;
	void	*image;
	void	*parameters[3];
	char	*image_address;
	char	**map;
	int		bits_in_byte;
	int		bpp;
	int		line_length;
	int		endianess;
	int		w_width;
	int		w_height;
	int		pixel_index;

	//	TODO:
	//	1. the program must accept a path to a map file
	//	2. then, must read the map file and store the data 
	//	   in a suitable structure, such as a 2D array of integers
	//	3. display the 3D object on a 2D surface. To do so, 
	//	   use a Projection Formula, like Isometric Projection
	//	4. once the 2D positions of each 3D point are calculated, 
	//	   draw lines between adjacent points to form the object.
	//	   To do so, use Bresenham's line-drawing algorithm
	//	5. add Scaling and Translation. The map may need to be scaled 
	//	   or moved to fit into the window.
	//	   Scaling is to multiply coordinates by a Scaling Factor 
	//	   to adjust the size.
	//	   Translation is to add an offset to center the image 
	//	   in the window
	//	6. finally, use "mlx_put_image_to_window()" to display the 
	//	   drawn image in the window
	//	
	//	extra: to add "zoom", adjust the Scaling Factor dynamically 
	//	       using keyboard events. To add "rotation", modify the 
	//	       Projection Formula to include rotation matrices. To 
	//	       add "movement", adjust the Translation offsets based 
	//	       on user input
	//	       implement a functionality to switch Projection Mode, 
	//	       between Isometric and Parallel
	map = fdf_read_map(argc, argv);
	fdf_print_str_matrix(map);
	t_matrix *matrix = fdf_to_matrix(&map);
	fdf_print_matrix(matrix);
	fdf_free_str_matrix(&map);
	//char *row = " 1,0xbAaFfF 2 ,0xbAaFfF 3, 0xbAaFfF 4 , 0xbAaFfF  5,0xaabbcc 6,0xbAaFfF\n";
	//char *row = " 1,0xaabbcc 2 3 4 ";
	//t_row	*result = fdf_to_pixel_row(row);
	//fdf_print_pixel_row(result);
	//fdf_free_pixel_row(&result);
	if (1)
		return (EXIT_SUCCESS);
	(void) argc; (void) argv;
	(void) map;
	bits_in_byte = 8;
	w_width = 1000;
	w_height = 800;
	minilibx = mlx_init();
	if (!minilibx)
	{
		ft_printf("Error: MLX initialization failed.\n");
		return (1);
	}
	window = mlx_new_window(minilibx, w_width, w_height, "FDF");
	if (!window)
	{
		ft_printf("Error: window initialization failed.\n");
		return (1);
	}
	mlx_hook(window, 17, 0, fdf_close_window, NULL);
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
	mlx_put_image_to_window(minilibx, window, image, 0, 0);
	parameters[0] = minilibx;
	parameters[1] = window;
	parameters[2] = image;
	mlx_loop_hook(minilibx, fdf_render_frame, parameters);
	mlx_loop(minilibx);
	return (EXIT_SUCCESS);
}
