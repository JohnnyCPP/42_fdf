/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:34:07 by jonnavar          #+#    #+#             */
/*   Updated: 2024/09/29 08:46:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FDF_H
# define FDF_H

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
# define FDF_EXTENSION ".fdf"

# include "libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>

/**
 * @brief Structure representing a pixel on the screen.
 *
 * The pixel contains an integer representing the height 
 * of the isometric projection of a matrix.
 * It contains an optional color which determines 
 * how the pixel will be rendered on the window.
 */
typedef struct s_pixel
{
	int		value;
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

//	rendering & events, will be documented later
int		fdf_close_window(void *parameter);
int		fdf_render_frame(void *parameters);

/**
 * @brief Validates the argument, map file, and format, before reading it.
 *
 * @param argc Arguments count, represents the amount of arguments 
 *             passed to the program, including the program name.
 * @param argv Arguments vector, a double pointer to the program arguments.
 *
 * #return An array of strings, representing a matrix 
 *         of characters read from a ".fdf" file.
 *
 * This function leads the input validation:
 *   1. Validates the amount of arguments
 *   2. Validates the file name
 *   3. Validates proper access to the ".fdf" file
 *   4. Validates the ".fdf" file content
 * If all the validations apply, it will read the ".fdf" file and return 
 * an array of strings with the data read from the file.
 */
char	**fdf_read_map(const int argc, const char **argv);

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
void	fdf_fill_str_matrix(int fd, char ***data_read, int *is_readable);

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
int		fdf_validate_matrix_row(const char *row);

/**
 * @brief Prints an error and terminates execution.
 *
 * @param matrix_ptr A pointer to the matrix, to free it's memory.
 *
 * This function handles the case when an error occurs reading the map.
 */
void	fdf_handle_map_failure(char ***matrix_ptr);

/**
 * @brief Prints an error and terminates execution.
 *
 * @param matrix_ptr A pointer to the matrix, to free it's memory.
 *
 * This function handles the case when an error occurs allocating memory.
 */
void	fdf_handle_mem_failure(char ***matrix_ptr);

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
int		fdf_count_pixels(const char *row);

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
int		fdf_extract_pixels(const char *row, t_row *result);

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
int		fdf_is_comma_present(const char *row, int i);

/**
 * @brief Frees a dynamically allocated row of pixels.
 *
 * @param row A double pointer to the row to free.
 *
 * This function frees a "t_row" and its "pixels" member.
 */
void	fdf_free_pixel_row(t_row **row_ptr);

/**
 * @brief Displays the contents of a row on the terminal.
 *
 * @param row A pointer to the row to display.
 *
 * This function prints the numbers, followed by (if present) 
 * their hexadecimal colors, from a row of pixels.
 */
void	fdf_print_pixel_row(t_row *row);

/**
 * @brief Frees a dynamically allocated matrix of characters.
 *
 * @param matrix_ptr A pointer to the matrix to free.
 *
 * This function frees the memory of all the strings in a matrix, 
 * the string of pointers, and assigns the pointer array to NULL.
 */
void	fdf_free_str_matrix(char ***matrix_ptr);

/**
 * @brief Displays a matrix of characters on the terminal.
 *
 * @param matrix The matrix of characters to display.
 *
 * This function displays the contents of a ".fdf" file stored 
 * in a matrix of characters.
 */
void	fdf_print_str_matrix(char **matrix);

/**
 * @brief Gets the length of a matrix of characters.
 *
 * @param matrix The matrix of characters to get the length from.
 *
 * @return The amount of strings in the matrix. 0 if the pointer is NULL.
 */
int		fdf_get_strmat_len(char **matrix);

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
void	fdf_copy_strmat(char **dest, char **source, int length);

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
t_row	*fdf_to_pixel_row(const char *row);

/**
 * @brief Frees a matrix.
 *
 * @param matrix_ptr The matrix to free.
 *
 * This function frees the dynamic memory of a matrix, 
 * all its rows, and sets all the pointers to NULL.
 */
void	fdf_free_matrix(t_matrix **matrix_ptr);

/**
 * @brief Frees the row array of a matrix.
 *
 * @param matrix_ptr The matrix whose rows will be freed.
 *
 * This function frees the dynamic memory of all the rows of a matrix.
 * Sets the pointers of all the pixels and the row array to NULL.
 */
void	fdf_free_row_array(t_matrix *matrix_ptr);

/**
 * @brief Creates a dynamically allocated array of rows.
 *
 * @param length The amount of rows that the array will have.
 *
 * @return The allocated array, or NULL if memory allocation failed.
 */
t_row	*fdf_new_row_array(int length);

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
void	fdf_move_row_array(t_row *destination, const t_row *source, int rows);

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
void	fdf_push_row(t_row *row_array, t_row *row, int length);

/**
 * @brief Displays the values of a matrix.
 *
 * @param matrix The matrix whose values will be displayed.
 *
 * This function iterates for each row of the "rows" member of "matrix", 
 * to print the numbers and hexadecimal color codes on the terminal.
 */
void	fdf_print_matrix(t_matrix *matrix);

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
t_matrix	*fdf_to_matrix(char ***matrix_ptr);

#endif
