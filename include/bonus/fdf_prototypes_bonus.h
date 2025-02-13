/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_prototypes_bonus.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FDF_PROTOTYPES_BONUS_H
# define FDF_PROTOTYPES_BONUS_H

/**
 * @brief Iterates through the matrix, applying translation to all pixels.
 *
 * @param data Structure containing the matrix to modify.
 * @param x Horizontal displacement.
 * @param y Vertical displacement.
 *
 * This function sums "x" and "y" to "x_2d" and "y_2d" of all pixels, 
 * respectively, effectively moving the projection on the screen.
 */
void	fdf_translation(t_data *data, double x, double y);

/**
 * @brief Event handler that checks a left mouse button click.
 *
 * @param button The mouse button that triggered the event.
 * @param mouse_x Current x-coordinate of the mouse.
 * @param mouse_y Current y-coordinate of the mouse.
 * @param d_ptr Structure that will keep record of the button clicked.
 *
 * @return Always 0.
 *
 * This function prototype returns int because it conforms with "mlx_hook" 
 * handler function passed as paremeter.
 * It will set "is_dragging" to 1, meaning the mouse left button is clicked.
 * It will get the value of "mouse_x" and "mouse_y" to calculate a delta 
 * when the mouse is moved.
 */
int		fdf_press_button(int button, int mouse_x, int mouse_y, void *d_ptr);

/**
 * @brief Event handler that checks a left mouse button release.
 *
 * @param button The mouse button that triggered the event.
 * @param mouse_x Current x-coordinate of the mouse.
 * @param mouse_y Current y-coordinate of the mouse.
 * @param d_ptr Structure that will keep record of the button released.
 *
 * @return Always 0.
 *
 * This function prototype returns int because it conforms with "mlx_hook" 
 * handler function passed as paremeter.
 * It will set "is_dragging" to 0, meaning the mouse left button is released.
 *
 * This function purpose is to stop the translation functionality when 
 * the mouse button is not pressed anymore. This is achieved through the 
 * "is_dragging" member of the "t_data" struct.
 */
int		fdf_release_button(int button, int mouse_x, int mouse_y, void *d_ptr);

/**
 * @brief Event handler that checks mouse movements.
 *
 * @param mouse_x Current x-coordinate of the mouse.
 * @param mouse_y Current y-coordinate of the mouse.
 * @param d_ptr Structure that will keep record of the mouse movement.
 *
 * @return Always 0.
 *
 * This function prototype returns int because it conforms with "mlx_hook" 
 * handler function passed as paremeter.
 *
 * This function will calculate the "x" and "y" deltas and apply a 
 * translation to the matrix based on the result of these deltas.
 *
 * Then, it will update "last_x" and "last_y" members of the "t_data" 
 * structure, in order to allow future updates.
 */
int		fdf_move_mouse(int mouse_x, int mouse_y, void *d_ptr);

/**
 * @brief Event handler that handles when a key is pressed.
 *
 * @param keysym A symbolic representation of the key, injected
 *               by minilibx.
 * @param data The struct whose data will be handled depending on 
 *             "keysym".
 *
 * @return Always 0.
 *
 * This function prototype returns int because it conforms with "mlx_hook" 
 * handler function passed as paremeter.
 */
int		fdf_handle_keypress(int keysym, t_data *data);

/**
 * @brief Hooks the bonus events to their respective handlers.
 *
 * @param data Structure that will be passed to the params of the handlers.
 *
 * This function hooks the following X Events:
 *
 *   - ButtonPress: mouse left button is clicked.
 *   - ButtonReleased: mouse left button is released.
 *   - MotionNotify: the mouse is moved.
 */
void	fdf_declare_bonus_events(t_data *data);

/**
 * @brief Rotates the matrix in the 2d plane.
 *
 * @param data Structure containing the matrix to rotate.
 * @param angle Magnitude of the rotation.
 */
void	fdf_rotate_2d(t_data *data, const double angle);

/**
 * @brief Toggles between the different projection types.
 *
 * @param data Structure containing the current projection type.
 */
void	fdf_switch_projection(t_data *data);

/**
 * @brief Applies parallel projection to the matrix.
 *
 * @param matrix The matrix to modify.
 *
 * This function just ignores the "z" axis and sets the values of 
 * "x" and "y" directly to the "x_2d" and "y_2d" before rendering.
 */
void	fdf_apply_parallel_formula(t_matrix *matrix);

/**
 * @brief Applies conical projection to the matrix.
 *
 * @param matrix The matrix to modify.
 * @param focal_length The distance of the viewpoint to the projection plane.
 *
 * Conical projection, or perspective projection, simulates how the 
 * human eye would perceive an object in real life at a given distance.
 *
 * The focal length would represent the distance of the viewer to the object.
 */
void	fdf_apply_conical_formula(t_matrix *matrix, double focal_length);

#endif
