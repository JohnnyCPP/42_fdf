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

static	void	fdf_to_zero(t_data *data)
{
	data->matrix = NULL;
	data->mlx = NULL;
	data->win = NULL;
	data->win_w = 0;
	data->win_h = 0;
	data->img = (t_image){NULL, NULL, 0, 0, 0, 0, 0};
}

int	main(const int argc, const char **argv)
{
	t_data	data;

	//	TODO:
	//	1. the program must accept a path to a map file
	//	2. then, must read the map file and store the data 
	//	   in a suitable structure, such as a 2D array of integers
	fdf_to_zero(&data);
	data.matrix = fdf_read_map(argc, argv);
	fdf_init_mlx(&data);
	ft_printf("DEBUG: bpp=%i\n", data.img.bpp);
	ft_printf("DEBUG: bpl=%i\n", data.img.bpl);
	ft_printf("DEBUG: end=%i\n", data.img.end);
	//	3. develop an implementation of the Projection Formula 
	//	   of Isometric Projection, then modify the "x" and "y" 
	//	   values to get the 2D coordinates of the 3D object
	fdf_apply_projection_formula(data.matrix);
	//	4. add Scaling and Translation. The map may need to be scaled 
	//	   or moved to fit into the window.
	//	   Scaling is to multiply coordinates by a Scaling Factor 
	//	   to adjust the size.
	//	   Translation is to add an offset to center the image 
	//	   in the window
	fdf_compute_initial_scaling(data);
	fdf_apply_translation_formula(data);
	fdf_print_matrix(data.matrix);
	//	5. once the 2D positions of each 3D point are calculated, 
	//	   draw lines between adjacent points to form the object.
	//	   To do so, use Bresenham's line-drawing algorithm
	//	6. finally, use "mlx_put_image_to_window()" to display the 
	//	   drawn image in the window
	mlx_loop_hook(data.mlx, fdf_render_frame, (void *) &data);
	mlx_loop(data.mlx);
	//	extra: to add "zoom", adjust the Scaling Factor dynamically 
	//	       using keyboard events. To add "rotation", modify the 
	//	       Projection Formula to include rotation matrices. To 
	//	       add "movement", adjust the Translation offsets based 
	//	       on user input
	//	       implement a functionality to switch Projection Mode, 
	//	       between Isometric and Parallel
	return (EXIT_SUCCESS);
}
