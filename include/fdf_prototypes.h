/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_prototypes.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FDF_PROTOTYPES_H
# define FDF_PROTOTYPES_H

/**
 * @brief Event handler that frees the allocated memory and stops execution.
 *
 * @param data_ptr A pointer to the struct whose members will be freed.
 *
 * @return Always 0.
 *
 * This function attempts to free the memory from the following resources:
 *   1. The image created with "mlx_new_image()"
 *   2. The associated window
 *   3. The minilibx instance
 *   4. The matrix
 *
 * This operation is performed in the specific order in which it's mentioned.
 * Finally, it exits the program with an exit code EXIT_SUCCESS.
 *
 * This function is expected to be bound to minilibx events.
 * It returns "int" to comply with the "mlx_hook()" prototype, but actually,
 * it never reaches the return statement because "exit()" terminates execution.
 */
int			fdf_close(void *data_ptr)	__attribute__((noreturn));

/**
 * @brief Handles the logic called when a key of the keyboard is pressed.
 *
 * @param keysym A symbolic representation of the key, injected 
 *               by minilibx.
 * @param data The struct whose data will be handled depending on 
 *             "keysym".
 * @return Always 0.
 *
 * This function is meant to be hooked into a KeyPress event with 
 * "mlx_hook" function.
 */
int			fdf_key_pressed(int keysym, t_data *data);

/**
 * @brief Initializes minilibx resources.
 *
 * @param data A pointer to the struct whose members will be populated.
 *
 * This function provides the following resources:
 *   1. Initializes the minilibx instance
 *   2. Initializes the new window, setting the window dimensions
 *   3. Initializes the new image, setting the image dimensions
 *   4. Gets the pixel buffer of the new image
 *
 * The initialization and provisioning is performed in that exact order.
 * If any of the initialization tasks runs with errors, this function handles 
 * the exception freeing the allocated memory, printing a descriptive error 
 * message, and exiting with error code EXIT_FAILURE.
 */
void		fdf_init_mlx(t_data *data);

/**
 * @brief Gets the address of a pixel in an image, to assign a color to it.
 *
 * @param x The x-axis of the pixel.
 * @param y The y-axis of the pixel.
 * @param img The image that contains the pixel buffer to get the pixel from.
 *
 * @return The address of the pixel in the given coordinates.
 *
 * This function calculates a row offset and a pixel offset. The row offset 
 * is calculated with the product of "y" times "bpl", which is actually 
 * retrieving the actual row where the pixel is.
 * The pixel offset is calculated with the product of "x" times "bpp/BYTE", 
 * which retrieves the pixel in a row.
 *
 * After the aforementioned calculations, this function applies pointer 
 * arithmetics to the pixel buffer, returning the sum of:
 *
 *     "pixel_buffer + (row_offset + pixel_offset)"
 *
 * Effectively returning the memory of the pixel in the ("x","y") 
 * coordinates from the pixel buffer associated with the "img".
 *
 * This "char *" address can be casted to "unsigned int *" to assign 
 * (32b or 24b) hexadecimal colors.
 */
char		*fdf_get_pixel_address(int x, int y, t_image *img);

/**
 * @brief Draws a pixel on an image.
 *
 * @param data The struct containing the image to print the pixel on.
 * @param pixel The pixel containing its coordinates and the optional color.
 *
 * This function gets the 2D coordinates of a pixel, its color, and the 
 * image associated to the "data" struct.
 * Finally, after getting the pixel address from the pixel buffer with 
 * "fdf_get_pixel_address", assigns a color to the pixel.
 *
 * If the pixel has a color, it will assign that color. If the pixel doesn't 
 * have a color, it will default to COLOR_WHITE.
 */
void		fdf_draw_pixel(t_data *data, t_pixel *pixel);

/**
 * @brief Draws a pixel on an image, with a custom color.
 *
 * @param d The struct containing the image to print the pixel on.
 * @param x The x-coordinate of the pixel.
 * @param y The y-coordinate of the pixel.
 * @param c The color which the pixel will be drawn with.
 *
 * This function is implemented like "fdf_draw_pixel", but allows the 
 * flexibility to impose a color passed through parameter.
 */
void		fdf_draw_pixel_color(t_data *d, int x, int y, unsigned int c);

/**
 * @brief Sets all pixels from a image to black.
 *
 * @param data A pointer to the structure whose image will be modified.
 *
 * This function iterates through all the pixels of the image, assigning 
 * COLOR_BLACK to each of them.
 */
void		fdf_draw_background(t_data *data);

/**
 * @brief Sets colored pixels where the matrix coordinates point to.
 *
 * @param data A pointer to the structure whose matrix will be iterated.
 *
 * This function iterates through the matrix, getting "x" and "y" axes.
 * Then, for each 2D coordinate, prints a pixel to that location.
 *
 * The color depends on the color read from the map file, but it defaults 
 * to COLOR_WHITE if the optional color is missing.
 */
void		fdf_draw_matrix(t_data *data);

/**
 * @brief Draws lines through all rows of the matrix on the image.
 *
 * @param data A pointer to the structure containing the image and the matrix.
 *
 * This function iterates through all the rows, printing lines between all 
 * of their pixels with "fdf_apply_bresenham_formula".
 */
void		fdf_draw_rows(t_data *data);

/**
 * @brief Draws lines through all columns of the matrix on the image.
 *
 * @param data A pointer to the structure containing the image and the matrix.
 *
 * This function iterates through all the rows, printing lines 
 * with "fdf_apply_bresenham_formula", between pixels from one row to 
 * the one under it, effectively drawing the columns.
 */
void		fdf_draw_columns(t_data *data);

/**
 * @brief Draws the entire projection on the image.
 *
 * @param data A pointer to the structure containing the image and the matrix.
 *
 * This function draws a background, the matrix points, and lines between 
 * rows and columns.
 */
void		fdf_draw_projection(t_data *data);

/**
 * @brief Updates the image before rendering it to the window.
 *
 * @param data_ptr A pointer to the structure whose image will be rendered.
 *
 * @return 1 if the operation is success, 0 otherwise.
 *
 * This function manipulates the image to draw the background and the matrix, 
 * then puts it to the window with "mlx_put_image_to_window()".
 * It's meant to be hooked into the main event loop, so it complies with the 
 * "mlx_loop_hook()" prototype by returning an integer of value "0" 
 * to signal success, or any non-zero value to signal error.
 */
int			fdf_render_frame(void *data_ptr);

/**
 * @brief Validates the argument, map file, and format, before reading it.
 *
 * @param argc Arguments count, represents the amount of arguments 
 *             passed to the program, including the program name.
 * @param argv Arguments vector, a double pointer to the program arguments.
 *
 * #return A t_matrix struct, representing the numbers and colors 
 *         read from a ".fdf" file.
 *
 * This function leads the input validation:
 *   1. Validates the amount of arguments
 *   2. Validates the file name
 *   3. Validates proper access to the ".fdf" file
 *   4. Validates the ".fdf" file content
 *
 * If all the validations apply, it will read the ".fdf" file and return 
 * a t_matrix with the data read from the file.
 */
t_matrix	*fdf_read_map(const int argc, const char **argv);

/**
 * @brief Reads a ".fdf" file and fills "data_read" with the content.
 *
 * @param fd The file descriptor from the open ".fdf" file.
 * @param data_read A pointer to the matrix of characters.
 * @param is_readable A value used to read through the file until the end.
 *
 * This function reads the ".fdf" file using "ft_gnl()" function until 
 * there are no more lines to read. Then, updates "is_readable" to 0.
 * The "data_read" matrix will be filled with dynamically allocated pointers 
 * and strings that the caller needs to free.
 * The matrix pointers end with a NULL pointer.
 */
void		fdf_fill_str_matrix(int fd, char ***data_read, int *is_readable);

/**
 * @brief Verifies the values from a matrix row.
 *
 * @param row A row from the matrix read from the ".fdf" file.
 *
 * @return 1 if the validation is correct, 0 otherwise.
 *
 * A row is a string that contains digits, and is part of a matrix.
 * The digits are separated by spaces, and contain optional hexadecimal 
 * values of 6 digits just after a comma and a hex prefix. E.g. "12,0xAABBCC".
 */
int			fdf_validate_matrix_row(const char *row);

/**
 * @brief Prints an error and terminates execution.
 *
 * @param matrix_ptr A pointer to the matrix, to free its memory.
 *
 * This function handles the case when an error occurs reading the map.
 */
void		fdf_handle_map_failure(char ***matrix_ptr);

/**
 * @brief Prints an error and terminates execution.
 *
 * @param matrix_ptr A pointer to the matrix, to free its memory.
 *
 * This function handles the case when an error occurs allocating memory.
 */
void		fdf_handle_mem_failure(char ***matrix_ptr);

/**
 * @brief Prints an error and terminates execution.
 *
 * @param data A pointer to the data struct, to free memory from its members.
 *
 * This function handles the case when an error occurs 
 * creating the minilibx instance.
 */
void		fdf_handle_mlx_failure(t_data *data);

/**
 * @brief Prints an error and terminates execution.
 *
 * @param data A pointer to the data struct, to free memory from its members.
 *
 * This function handles the case when an error occurs 
 * creating the window instance.
 */
void		fdf_handle_win_failure(t_data *data);

/**
 * @brief Prints an error and terminates execution.
 *
 * @param data A pointer to the data struct, to free memory from its members.
 *
 * This function handles the case when an error occurs 
 * creating the image instance.
 */
void		fdf_handle_img_failure(t_data *data);

/**
 * @brief Prints an error and terminates execution.
 *
 * @param data A pointer to the data struct, to free memory from its members.
 *
 * This function handles the case when an error occurs 
 * creating the pixel buffer.
 */
void		fdf_handle_buffer_failure(t_data *data);

/**
 * @brief Counts the pixels in a row.
 *
 * @param row A string that represents a row in a matrix.
 *
 * @return The amount of pixels. If an error occurs, returns -1.
 *
 * This function counts the amount of numbers in a string, separated 
 * by spaces, and with optional hexadecimal numbers separated by commas.
 */
int			fdf_count_pixels(const char *row);

/**
 * @brief Extracts the pixels from a string.
 *
 * @param row The string of pixels to extract from.
 * @param result The destination row to store the pixels to.
 *
 * @return 1 if the extraction was successful. 0 otherwise.
 *
 * This function expects a dynamically allocated "t_row" 
 * that will have its "pixels" member filled with the data from "row".
 */
int			fdf_extract_pixels(const char *row, t_row *result);

/**
 * @brief Looks for a comma in a string, until the next digit or terminator.
 *
 * @param row The string where the comma will be looked upon.
 * @param i The position in the string to start looking for.
 *
 * @return 1 if there's a comma, or 0 otherwise.
 *
 * This helper function looks for a comma just after a number 
 * is found in a row. If it finds digit or a terminator character, 
 * returns 0.
 */
int			fdf_is_comma_present(const char *row, int i);

/**
 * @brief Frees a dynamically allocated row of pixels.
 *
 * @param row A double pointer to the row to free.
 *
 * This function frees a "t_row" and its "pixels" member.
 */
void		fdf_free_pixel_row(t_row **row_ptr);

/**
 * @brief Displays the contents of a row on the terminal.
 *
 * @param row A pointer to the row to display.
 *
 * This function prints the numbers, followed by (if present) 
 * their hexadecimal colors, from a row of pixels.
 */
void		fdf_print_pixel_row(t_row *row);

/**
 * @brief Assigns the value of 'y' to pixels in a row.
 *
 * @param row The row whose pixels will be modified.
 * @param y_axis The value to set.
 *
 * This function iterates through all the pixels in a t_row struct,
 * assigning the value of "y_axis" to the "y" member of each of them.
 */
void		fdf_assign_y_axis(t_row *row, const int y_axis);

/**
 * @brief Assigns the values of 2d axes to pixels in a row.
 *
 * @param row The row whose pixels will be modified.
 *
 * This function iterates through all the pixels in a t_row struct,
 * assigning the values of "x" and "y" to the "x_2d" and "y_2d" members.
 * While "x" and "y" will hold the original values of the map, 
 * the 2d counterparts will store the result of rendering computations.
 */
void		fdf_assign_2d_axes(t_row *row);

/**
 * @brief Assigns the values of decimal colors to pixels in a row.
 *
 * @param row The row whose pixels will be modified.
 *
 * This function iterates through all the pixels in a t_row struct,
 * assigning the values of "decimal_color" with the value stored 
 * in the hexadecimal string "color".
 */
void		fdf_assign_decimal_colors(t_row *row);

/**
 * @brief Frees a dynamically allocated matrix of characters.
 *
 * @param matrix_ptr A pointer to the matrix to free.
 *
 * This function frees the memory of all the strings in a matrix, 
 * the string of pointers, and assigns the pointer array to NULL.
 */
void		fdf_free_str_matrix(char ***matrix_ptr);

/**
 * @brief Displays a matrix of characters on the terminal.
 *
 * @param matrix The matrix of characters to display.
 *
 * This function displays the contents of a ".fdf" file stored 
 * in a matrix of characters.
 */
void		fdf_print_str_matrix(char **matrix);

/**
 * @brief Gets the length of a matrix of characters.
 *
 * @param matrix The matrix of characters to get the length from.
 *
 * @return The amount of strings in the matrix. 0 if the pointer is NULL.
 */
int			fdf_get_strmat_len(char **matrix);

/**
 * @brief Shallow copy of a matrix of characters.
 *
 * @param dest The matrix where the copy will be.
 * @param source The original matrix to copy from.
 * @param length The amount of addresses to copy.
 *
 * This function copies from 0 to "length" addresses from "source" 
 * to "dest". It just assigns pointers, the strings are left untouched.
 */
void		fdf_copy_strmat(char **dest, char **source, int length);

/**
 * @brief From a string of pixels, gets a "t_row" struct.
 *
 * @param row The string of characters to get the data from.
 *
 * @return A struct with the contents of a string of pixels.
 *         If an error occurs, returns NULL.
 *
 * This function computes the numbers and colors obtained from a 
 * ".fdf" file that have been stored in a string.
 * It allocates dynamic memory for a "t_row" pointer, and its "pixels" 
 * member which is an array of pixels.
 */
t_row		*fdf_to_pixel_row(const char *row);

/**
 * @brief Frees a matrix.
 *
 * @param matrix_ptr The matrix to free.
 *
 * This function frees the dynamic memory of a matrix, 
 * all its rows, and sets all the pointers to NULL.
 */
void		fdf_free_matrix(t_matrix **matrix_ptr);

/**
 * @brief Frees the row array of a matrix.
 *
 * @param matrix_ptr The matrix whose rows will be freed.
 *
 * This function frees the dynamic memory of all the rows of a matrix.
 * Sets the pointers of all the pixels and the row array to NULL.
 */
void		fdf_free_row_array(t_matrix *matrix_ptr);

/**
 * @brief Creates a dynamically allocated array of rows.
 *
 * @param length The amount of rows that the array will have.
 *
 * @return The allocated array, or NULL if memory allocation failed.
 */
t_row		*fdf_new_row_array(int length);

/**
 * @brief Moves the rows of "source" to "destination" until "rows".
 *
 * @param destination The row array where the values will be moved to.
 * @param source The row array where the values are obtained from.
 * @param rows The length of "source".
 *
 * This function assigns the "length" and "pixels" members of 
 * rows from 0 to "rows", of "destination" array 
 * with the values of "source" array.
 * The "source" array is not modified.
 */
void		fdf_move_row_array(t_row *dest, const t_row *source, int rows);

/**
 * @brief Adds a new row to a row array.
 *
 * @param row_array The array of rows to add a new row to.
 * @param row The new row to add to the array.
 * @param length The amount of rows of "row_array".
 *
 * This function expects that "row_array" has memory allocated for 
 * a new row, and will store the values of "row" in the last row (length - 1).
 */
void		fdf_push_row(t_row *row_array, t_row *row, int length);

/**
 * @brief Displays the values of a matrix.
 *
 * @param matrix The matrix whose values will be displayed.
 *
 * This function iterates for each row of the "rows" member of "matrix", 
 * to print the numbers and hexadecimal color codes on the terminal.
 */
void		fdf_print_matrix(t_matrix *matrix);

/**
 * @brief Converts a matrix of characters into a t_matrix.
 *
 * @param matrix_ptr The matrix of characters to convert to.
 *
 * @return A dynamically allocated t_matrix, or NULL if an error occurred.
 *
 * This function doesn't free the memory of "matrix_ptr", 
 * the caller needs to do it.
 */
t_matrix	*fdf_to_matrix(const char **str_matrix);

/**
 * @brief Applies isometric projection to the coordinates of a matrix.
 *
 * @param matrix The matrix whose points will be modified.
 *
 * Modifies the x and y axes to represent a 3D object on a 2D surface.
 * The "x_2d" and "y_2d" members of each pixel will be modified to
 * represent their coordinates on a 2D surface.
 */
void		fdf_apply_projection_formula(t_matrix *matrix);

/**
 * @brief Calculates the minimum values of "x" and "y" coordinates.
 *
 * @param data The struct whose matrix will be iterated through.
 * @param min_x Pointer to the minimum value of "x".
 * @param min_y Pointer to the minimum value of "y".
 *
 * This function will iterate through the matrix, comparing all the 
 * "x" and "y" coordinates, starting from the first pixel from the first row.
 *
 * It takes pointers to store the minimum values of each axis, so 
 * the result will be stored in "min_x" and "min_y".
 */
void		fdf_compute_minimums(t_data *data, double *min_x, double *min_y);

/**
 * @brief Calculates the maximum values of "x" and "y" coordinates.
 *
 * @param data The struct whose matrix will be iterated through.
 * @param max_x Pointer to the maximum value of "x".
 * @param max_y Pointer to the maximum value of "y".
 *
 * This function will iterate through the matrix, comparing all the 
 * "x" and "y" coordinates, starting from the first pixel from the first row.
 *
 * It takes pointers to store the maximum values of each axis, so 
 * the result will be stored in "max_x" and "max_y".
 */
void		fdf_compute_maximums(t_data *data, double *max_x, double *max_y);

/**
 * @brief Computes how much scaling is applied before the first renderization.
 *
 * @param data The struct whose matrix will be modified.
 *
 * This function calculates a scaling factor from the values of the matrix 
 * in "data", and applies a scaling with that value.
 *
 * It's intended to be called once when the application starts.
 */
void		fdf_compute_initial_scaling(t_data *data);

/**
 * @brief Clamps a double to integer limits.
 *
 * @param value The value to convert to int.
 *
 * @return If it's safe to be casted, the rounded "value" casted to int.
 *         If the value would exceed integer limits, returns INT_MAX or 
 *         INT_MIN when appropiate.
 */
int			fdf_round(const double value);

/**
 * @brief Checks if a multiplication would exceed integer limits.
 *
 * @param a One factor of a multiplication.
 * @param b Another factor of a multiplication.
 *
 * @return 1 if the multiplication is safe, 0 otherwise.
 *
 * This function checks if the product of multiplying "a" and "b" 
 * would exceed INT_MAX or INT_MIN.
 *
 * Without performing the actual multiplication, by dividing both sides 
 * of the "a*b>INT_MAX" inequality per |b|, and treating both values 
 * with their absolute representations, this function performs the 
 * "|a|>INT_MAX/|b|" expression.
 *
 * This expression results from the simplification of:
 *
 *     "|a| * |b| / |b| > INT_MAX / |b|"
 */
int			fdf_is_product_safe(const double a, const double b);

/**
 * @brief Converts an hexadecimal representation to decimal.
 *
 * @param hex A pointer to a null-terminated string.
 *
 * @return The decimal representation of "hex".
 *
 * This function expects a string whose value is a hex number of eight digits.
 */
int			fdf_to_int(const char *hex);

/**
 *	@brief Applies translation to the coordinates of a matrix.
 *
 *	@param data The structure whose matrix will be modified.
 *
 *	Since isometric projection often involves negative coordinates 
 *	due to the rotation and scaling, the translation needs to be applied 
 *	to shift the entire drawing into the visible area of the image.
 *
 *	This process involves adding an offset to all "x" and "y" coordinates.
 *
 *	This offset is calculated with the minimum value of each one.
 */
void		fdf_apply_translation_formula(t_data *data);

/**
 * @brief Applies scaling to the coordinates of a matrix.
 *
 * @param data The structure whose matrix will be modified.
 *
 * Scaling adjusts the size of the rendered 3D object by multiplying 
 * its coordinates by a scaling factor.
 *
 * This can help to fit the object proportionally within 
 * the window dimensions, no matter the size of the original map 
 * or the resolution of the window.
 */
void		fdf_apply_scaling(t_data *data, const double scaling_factor);

/**
 * @brief Populates the delta structure from two positions in space.
 *
 * @param delta The delta structure that will be populated.
 * @param s The initial position in space.
 * @param e The final position in space.
 *
 * This function copies the data from two pixels to the t_delta structure.
 * This data will be used to draw the corresponding pixels between the 
 * starting and ending points.
 */
void		fdf_get_pixel_data(t_delta *delta, t_pixel *s, t_pixel *e);

/**
 * @brief Draws a line, between two points, in an image.
 *
 * @param d A pointer to the structure containing the image to draw into.
 * @param start The starting point.
 * @param end The ending point.
 *
 * To draw a line between two points, where the points are excluded, this 
 * function performs specific calculations in a given order.
 * That the points are excluded means that this function doesn't draw 
 * "start" or "end", this function expects the caller to draw them. This is 
 * explicitly done to not instruct drawing a given pixel twice.
 *
 * The order of calculations is as follows:
 *
 *   1. Calculates deltas. Deltas are the differences between "start" and 
 *      "end" in "x" and "y" axes. "x_delta" is horizontal length.
 *      "y_delta" is vertical length.
 *   2. Calculates steps. Steps are the direction of displacement from 
 *      "start" to "end", in "x" and "y" axes.
 *      For example, if "start" has a lower "x" value than "end", the "x_step" 
 *      will be positive in order to move to the right in the horizontal axis.
 *      Otherwise, it will be negative to move to the left.
 *      This applies aswell to the y-axis, moving up or down.
 *   3. Calculates the error term. The error term represents how far is the 
 *      current position ("start") from the ideal straight-line path.
 *   4. Loops until "start" is exactly at "end" in both axes. In the loop, 
 *      calculates the "decision" variable whose purpose is to decide where 
 *      will be the next position to draw in the line.
 **/
void		fdf_apply_bresenham_formula(t_data *d, t_pixel *s, t_pixel *e);

/**
 * @brief Gets the alpha component of a hex color.
 *
 * @param color The hexadecimal color to get the component from.
 *
 * @return The integer value of the alpha component.
 */
int			fdf_get_alpha(int color);

/**
 * @brief Gets the red component of a hex color.
 *
 * @param color The hexadecimal color to get the component from.
 *
 * @return The integer value of the red component.
 */
int			fdf_get_red(int color);

/**
 * @brief Gets the green component of a hex color.
 *
 * @param color The hexadecimal color to get the component from.
 *
 * @return The integer value of the green component.
 */
int			fdf_get_green(int color);

/**
 * @brief Gets the blue component of a hex color.
 *
 * @param color The hexadecimal color to get the component from.
 *
 * @return The integer value of the blue component.
 */
int			fdf_get_blue(int color);

/**
 * @brief Creates a new color from its individual components.
 *
 * @param alpha The alpha component of the new color.
 * @param red The red component of the new color.
 * @param green The green component of the new color.
 * @param blue The blue component of the new color.
 *
 * @return A new hexadecimal color built from the given components.
 */
int			fdf_new_color(int alpha, int red, int green, int blue);

/**
 * @brief Gets the color of a pixel between two colors with a given factor.
 *
 * @param start The color of the start pixel.
 * @param end The color of the end pixel.
 * @param factor A number between 0.0 and 1.0.
 *
 * @return The color that the pixel would have with a given factor.
 *
 * The different components, alpha, red, green, and blue, are obtained 
 * from both the start and end colors.
 *
 * Then, an interpolation is applied individually to each component. This 
 * interpolation gets the value that the component of the color would have 
 * in a given point of the line.
 *
 * Finally, the three interpolated components are mixed, creating the 
 * new color.
 */
int			fdf_interpolate_color(int start, int end, double factor);

/**
 * @brief Calculates the interpolated color for a given step in a delta.
 *
 * @param delta The current delta during line drawing.
 *
 * This function calculates the factor with the current position in the 
 * line being drawn. Then, gets the current color through interpolation.
 * Finally, assigns the current color to the next pixel that will be drawn.
 */
void		fdf_apply_interpolation(t_delta *delta);

#endif
