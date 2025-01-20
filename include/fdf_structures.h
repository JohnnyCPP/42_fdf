/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_structures.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FDF_STRUCTURES_H
# define FDF_STRUCTURES_H

/**
 * @brief Structure representing a pixel on the screen.
 *
 * The pixel contains an optional color, that determines, 
 * with what color the pixel will be rendered on the window.
 *
 * The pixel has been configured to hold three integers, 
 * which represent the (x,y,z) coordinates of a point in space.
 * This point in space will be processed by a projection formula 
 * of isometric projection, with the objective of represent a 
 * 3D object on a 2D surface, the minilibx window.
 */
typedef struct s_pixel
{
	int		x;
	int		y;
	int		z;
	char	*color;
}				t_pixel;

/**
 * @brief Structure representing a row of pixels on the screen.
 *
 * The row contains its length, to manipulate the pixels, which 
 * is a pointer to an array of pixels.
 */
typedef struct s_row
{
	int		length;
	t_pixel	*pixels;
}				t_row;

/**
 * @brief Structure representing a group of rows.
 *
 * Each row represents a given amount of pixels that 
 * will be rendered on the window.
 *
 * The matrix contains its length, to manipulate the rows, which 
 * is a pointer to an array of rows.
 */
typedef struct s_matrix
{
	int		length;
	t_row	*rows;
}				t_matrix;

/**
 * @brief Structure representing an image.
 *
 * Its purpose is to store all the image related data efficiently.
 *
 * ptr Is a pointer to an image object created by "mlx_new_image()".
 *     Serves as a reference to the minilibx image structure.
 *     It's passed to minilibx functions like "mlx_put_image_to_window()" 
 *     to display the image.
 *     It abstracts away the details of how the image is stored 
 *     and managed by the minilibx library.
 *     It's not for direct interaction, it's meant to be managed 
 *     by minilibx.
 *
 * buf Is a memory address pointing to the raw pixel data 
 *     of the image. It's used to directly modify the image's pixel 
 *     values without using "mlx_pixel_put()", which is slow.
 *     It's a block of memory where the actual pixel data for 
 *     an image is stored. Each pixel's color is represented 
 *     by a specific number of bytes (e.g. 4B for "0xRRGGBBAA" 
 *     in a 32-bit image).
 *
 * bpp (bits per pixel) Is the number of bits used to represent each pixel.
 *     32 for a 32-bit color depth (8 bits per RGBA channel).
 *     24 for a 24-bit color depth (8 bits per RGB channel).
 *     Helps determine how many bytes a pixel occupies in memory.
 *
 * bpl (bytes per line, or line length) Is the number of bytes 
 *     used for a single row of pixels (scanline) in the pixel buffer.
 *     Calculated as: bpl=img_width(pixels)*bpp
 *     Is used to calculate pixel positions within the pixel buffer.
 *     It helps calculating the exact memory offset for any pixel 
 *     in the buffer: to find the pixel at (x, y):
 *
 *     pixel_address=image_address+(y*bpl)+(x*bpp/8)
 *
 *     However, due to padding or alignment requirements, it might 
 *     be greater than the theoretical value.
 *     A "single row" refers to all the pixels horizontally aligned on 
 *     the same vertical level of the image, or in terms of memory, a 
 *     contiguous section of the pixel buffer representing the row.
 *     The term "scanline" comes from how traditional displays (like CRTs) 
 *     and image processing systems process an image row by row.
 *     A scanline is essentially a synonym for a single row of pixels.
 *     To move to the next scanline, skip "bpl" bytes in memory.
 *
 *     "padding" refers to the extra unused bytes added to data structures 
 *               or memory allocations to meet alignment requirements.
 *               Its objective is to improve memory access speed by matching 
 *               the CPU or GPU's preferred memory access size.
 *     "alignment" is a constraint on memory addresses that ensures data 
 *                 starts at specific boundaries.
 *                 This is crucial for modern CPUs, as they can access 
 *                 memory more efficiently when data is aligned to their 
 *                 native word size.
 *                 A variable is aligned if its starting memory address 
 *                 is a multiple of the alignment size.
 *
 * end Is the endianess of pixel data, defines how colors are 
 *     stored in memory.
 *     0 -> little-endian: LSB is stored first in memory
 *                      (e.g. "0xRRGGBBAA" stored as "0xAARRGGBB"
 *     1 -> big-endian: MSB is stored first in memory
 *                      (e.g. "0xRRGGBBAA" stored as "0xBBGGRRAA"
 *     When discussing endianess in minilibx, it applies to the ordering 
 *     of the color components (R,G,B,A) in memory for a pixel.
 *     Each color value "RRGGBBAA" is stored as a 32-bit integer (4B).
 *     If the bpl is less than 32 (e.g. 24 for RGB), the alpha byte (AA) 
 *     may not be used, leading to a "0xRRGGBB00" memory layout.
 *
 * w & h Correspond to the image dimensions.
 */
typedef struct s_image
{
	void	*ptr;
	char	*buf;
	int		bpp;
	int		bpl;
	int		end;
	int		w;
	int		h;
}				t_image;

/**
 * @brief Structure representing application resources.
 *
 * It holds references to the minilibx instance, window, images, 
 * and any other resources used in the application.
 * Its purpose is to simplify passing data between functions, and to 
 * centralize all essential pointers and values.
 */
typedef struct s_data
{
	t_matrix	*matrix;
	void		*mlx;
	void		*win;
	int			win_w;
	int			win_h;
	t_image		img;
}				t_data;

#endif
