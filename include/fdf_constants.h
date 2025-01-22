/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_constants.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FDF_CONSTANTS_H
# define FDF_CONSTANTS_H

/**
 * @brief Application errors.
 */
# define ERROR_ARGC "Usage: ./fdf <filename.fdf>"
# define ERROR_EXTENSION "The map doesn't have the expected extension (.fdf)"
# define ERROR_IO "Error opening file"
# define ERROR_MEMORY "Memory allocation error"
# define ERROR_MAP_FORMAT "The map file contains invalid characters"
# define ERROR_ROW_LENGTH "The map has a row that exceeds length limit"
# define ERROR_IOVERFLOW "A number can't be allocated, an int overflows"
# define ERROR_MINILIB "An error occurred initializing minilibx"
# define ERROR_WINDOW "An error occurred initializing the window"
# define ERROR_IMAGE "An error occurred initializing the image"
/**
 * @brief The map file should have the following extension.
 */
# define FDF_EXTENSION ".fdf"
/**
 * @brief Properties of the window.
 */
# define WIDTH 1280
# define HEIGHT 720
# define TITLE "FDF"
/**
 * @brief Amount of bits in a byte.
 */
# define BYTE 8
# define EVENT_CLOSE 17
# define NO_MASK 0
/**
 * @brief Hexadecimal colors.
 */
# define COLOR_BLACK 0xFF000000
# define COLOR_WHITE 0xFFFFFFFF
/**
 * @brief Rounds to the nearest integer.
 */
# define ROUND_NEAREST_INT 0.5
/**
 * @brief Rotation angle applied for the isometric projection convention.
 *
 * The angle "30.0 degrees" is chosen because it's part of the standard 
 * isometric projection convention.
 *
 * The X-axis is rotated 30º, this helps balance the projection visually 
 * and provides a uniform scale on all three axes.
 */
# define ISOMETRIC_CONV_ROT_ANG 30.0
/**
 * @brief Amount of degrees equal to PI radians.
 *
 * Angles in programming often use radians instead of degrees because 
 * many mathematical libraries work in radians.
 *
 * To convert degrees into radians, use a conversion factor:
 * 
 *     radians = degrees*(PI/180)
 *
 * The "180" is used because is the amount of degrees that equals PI radians.
 *
 * If 2*PI radians equals to the full rotation of a circle, PI radians 
 * equals a half rotation of a circle (180º).
 */
# define PI_RADIAN_DEGREES 180.0

#endif
