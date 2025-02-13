/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

static	void	fdf_show_controls(void)
{
	ft_printf("Controls:\n\n");
	ft_printf("Move the projection holding the left mouse button.\n");
	ft_printf("Zoom in and out scrolling the mouse wheel.\n");
	ft_printf("Press \"a\" or \"d\" to rotate the projection.\n");
	ft_printf("Press \"p\" to switch the projection type.\n");
	ft_printf("Press \"Esc\" to close.\n");
}

static	void	fdf_to_zero(t_data *data)
{
	data->matrix = NULL;
	data->mlx = NULL;
	data->win = NULL;
	data->win_w = 0;
	data->win_h = 0;
	data->img = (t_image){NULL, NULL, 0, 0, 0, 0, 0};
	data->mouse = (t_mouse){0, 0, 0};
	data->projection = ISOMETRIC;
	data->focal_length = 0.0;
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
	mlx_loop_hook(data.mlx, fdf_render_frame, (void *) &data);
	fdf_declare_bonus_events(&data);
	fdf_show_controls();
	mlx_loop(data.mlx);
	return (EXIT_SUCCESS);
}
