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

	fdf_to_zero(&data);
	data.matrix = fdf_read_map(argc, argv);
	fdf_init_mlx(&data);
	fdf_apply_projection_formula(data.matrix);
	fdf_compute_initial_scaling(&data);
	fdf_apply_translation_formula(&data);
	fdf_print_matrix(data.matrix);
	fdf_draw_projection(&data);
	mlx_loop_hook(data.mlx, fdf_render_frame, (void *) &data);
	mlx_loop(data.mlx);
	//	bonus:
	//	  - To add "zoom", adjust the Scaling Factor dynamically using events
	//	  - To add "rotation", modify the Projection Formula to include 
	//	    rotation matrices
	//	  - To add "movement", adjust the Translation offsets 
	//	    based on user input
	//	  - Implement a functionality to switch Projection Mode, 
	//	    between Isometric, Conical, or Parallel
	return (EXIT_SUCCESS);
}
