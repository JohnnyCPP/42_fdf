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

#endif
