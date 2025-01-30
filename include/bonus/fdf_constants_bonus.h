/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_constants_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FDF_CONSTANTS_BONUS_H
# define FDF_CONSTANTS_BONUS_H

/**
 * @brief There are no predefined macros for mouse button codes in X11.
 *
 * The following macros are used to handle mouse events.
 */
# define MOUSE_LEFT_BUTTON 1
# define MOUSE_MIDDLE_BUTTON 2
# define MOUSE_RIGHT_BUTTON 3
# define MOUSE_SCROLL_UP 4
# define MOUSE_SCROLL_DOWN 5
/**
 * @brief Determine how much the projection is scaled up and down.
 */
# define SCALE_UP 1.1
# define SCALE_DOWN 0.9
/**
 * @brief Magnitudes of the 3D rotations.
 */
# define COUNTERCLOCKWISE 0.1
# define CLOCKWISE -0.1
/**
 * @brief The default value for focal length when conical projection is active.
 *
 * The focal length represents the distance from the viewpoint to 
 * the projection plane. This is what makes an object appear smaller in 
 * relation to the distance from the viewer to the object.
 *
 * The choice for this value is arbitrary, and depends on the current 
 * scale of the 3D scene and the desired perspective effect.
 *
 * The Focal Length is inversely proportional to the Field of View (FOV).
 * A smaller Focal Length results in a wider FOV, while a larger value 
 * results in a narrower FOV.
 */
# define DEFAULT_FOCAL_LENGTH 200.0
/**
 * @brief The maximum and minimum value for focal length.
 */
# define MAXIMUM_FOCAL_LENGTH 1000.0
# define MINIMUM_FOCAL_LENGTH 10.0
/**
 * @brief The magnitude of focal length modification.
 */
# define INCREMENT_FOCAL_LENGTH 10.0

#endif
