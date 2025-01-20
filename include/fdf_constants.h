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

# define ERROR_ARGC "Usage: ./fdf <filename.fdf>"
# define ERROR_EXTENSION "The map file doesn't contain the " \
						 "expected file extension (.fdf)"
# define ERROR_IO "Error opening file"
# define ERROR_MEMORY "Memory allocation error"
# define ERROR_MAP_FORMAT "The map file contains invalid characters.\n" \
						  "Only spaces, digits, and hex colors are allowed. " \
						  "Colors can be added to each point, with its " \
						  "hexadecimal value just after the point, " \
						  "separated with a comma.\n" \
						  "The hexadecimal format is '0xRRGGBB'"
# define ERROR_ROW_LENGTH "The map file contains a row that exceeds " \
						  "the maximum amount of points.\n" \
						  "Execution halted"
# define ERROR_IOVERFLOW "A number can't be allocated because its size " \
						 "exceeds the maximum value of an integer."
# define ERROR_MINILIB "An error occurred initializing minilibx."
# define ERROR_WINDOW "An error occurred initializing the window."
# define ERROR_IMAGE "An error occurred initializing the image."
# define FDF_EXTENSION ".fdf"
# define WIDTH 1280
# define HEIGHT 720
# define TITLE "FDF"
# define BYTE 8
# define EVENT_CLOSE 17
# define NO_MASK 0
# define LE_BLUE 0xFF000044
# define BE_BLUE 0x440000FF

#endif
