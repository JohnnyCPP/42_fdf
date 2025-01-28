# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/26 20:27:13 by jonnavar          #+#    #+#              #
#    Updated: 2024/09/26 20:37:23 by jonnavar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


## VARIABLE DECLARATIONS ##
###########################


INCLUDES_PATH	= ./include/
B_INCLUDES_PATH	= ${INCLUDES_PATH}bonus/
LIB_PATH		= ./src/lib/
LIBFT_PATH		= ${LIB_PATH}libft/
LIBFT_INC_PATH	= ${LIBFT_PATH}include/
OBJECTS_PATH	= ./object/
MATRIX_OBJ_PATH	= ${OBJECTS_PATH}matrix/
READ_OBJ_PATH	= ${OBJECTS_PATH}read_map/
CALC_OBJ_PATH	= ${OBJECTS_PATH}calculation/
EVENT_OBJ_PATH	= ${OBJECTS_PATH}event/
RENDER_OBJ_PATH	= ${OBJECTS_PATH}rendering/
ERROR_OBJ_PATH	= ${OBJECTS_PATH}error_handling/
COLOR_OBJ_PATH	= ${OBJECTS_PATH}color/
BONUS_OBJ_PATH	= ${OBJECTS_PATH}bonus/
B_EV_OBJ_PATH	= ${BONUS_OBJ_PATH}event/
B_CALC_OBJ_PATH	= ${BONUS_OBJ_PATH}calculation/
SOURCES_PATH    = ./src/
MINILIBX_PATH	= ${LIB_PATH}minilibx-linux/
MAPS_PATH		= ./maps/


MINILIBX_FILE	= libmlx.a
MINILIBX_NAME	= ${MINILIBX_PATH}${MINILIBX_FILE}
LIBFT_FILE		= libft.a
LIBFT_NAME		= ${LIBFT_PATH}${LIBFT_FILE}
NAME			= fdf
DEBUG			= debug


CC				= cc
DEBUG_SYMBOLS	= -g3
CFLAGS			= -Wall -Wextra -Werror ${DEBUG_SYMBOLS}
GDB				= gdb
# both "-g" or "-g3" flags can be used.
# "-g3" includes everything included with "-g", but with 
# additional information to debug preprocessor directives
SANITIZE_FLAGS	= -fsanitize=address ${DEBUG_SYMBOLS}
# "--track-origin=yes" tracks the origin of uninitialized values
# "-s" display a summary of the results directly in the terminal
# "--leak-check=full" enable detailed memory leak detection, and 
#                     report every possible memory leak
VALGRIND_FLAGS	= --track-origins=yes -s --leak-check=full --show-leak-kinds=all
# "-I <path>" instructs the compiler where to look for header files
# "-L <path>" instructs the linker where to look for static (.a) or 
#             shared (.so) libraries
# "-l<file>" instructs the linker to add a specific library by its name.
#            the linker will consider the "lib" prefix and ".a"/".so" sufix.
#            e.g. "-lft" links against "libft.a" or "libft.so".
#            note: this flag can't have a space in between, it's 
#                  processed as a single token
#
# "-lmlx" links against "libmlx.a"
# "-lmlx_Linux" links against "libmlx_Linux.a"
# "-lXext" links against the "libXext" library, an extension for 
#          the X11 windowing system. It's a dependency of minilibx
# "-lX11" links against the "libX11" library. Provides the core functions 
#         of the X11 windowing system
#
# additional notes: minilibx is a lightweight library that relies on X11 
#                   for graphical rendering. "-lXext -lX11" are dependencies 
#                   of minilibx that provide the underlying graphical 
#                   functionality. "-lmlx -lmlx_Linux" are specific to 
#                   minilibx itself
X11_FILES		= -lXext -lX11 -lm
MLX_SPECIFICS	= -lmlx -lmlx_Linux
INCLUDE_MLX		= -I ${MINILIBX_PATH} -L ${MINILIBX_PATH} ${X11_FILES} ${MLX_SPECIFICS}
INCLUDE_LIBFT	= -I ${LIBFT_INC_PATH}
INCLUDE_BONUS	= -I ${B_INCLUDES_PATH}
INCLUDE			= -I ${INCLUDES_PATH} ${INCLUDE_BONUS} ${INCLUDE_LIBFT} ${INCLUDE_MLX}
MAKE_LIB		= make -sC


ALL				= all
DELETE			= delete_library
CLEAN			= clean
FCLEAN			= fclean
RE				= re
BONUS			= bonus
CC_SANITIZER	= sanitize
VALGRIND		= valgrind
VALGRIND_ARGS	= ${MAPS_PATH}42.fdf
MAP				= map
MAP_ARGS		= ${MAPS_PATH}42.fdf
PREFIX_LIB		= lib_
LIB_DELETE		= ${PREFIX_LIB}${DELETE}
LIB_CLEAN		= ${PREFIX_LIB}${CLEAN}
LIB_FCLEAN		= ${PREFIX_LIB}${FCLEAN}
LIB_RE			= ${PREFIX_LIB}${RE}


PHONY			= .PHONY
STD_PHONY		= ${ALL} ${CLEAN} ${FCLEAN} ${RE} ${BONUS}
DEBUG_PHONY		= ${CC_SANITIZER} ${VALGRIND} ${MAP} ${GDB}
LIB_PHONY		= ${LIB_DELETE} ${LIB_CLEAN} ${LIB_FCLEAN} ${LIB_RE}


MAKE_LIBFT		= ${MAKE_LIB} ${LIBFT_PATH}
DELETE_LIBFT	= ${MAKE_LIBFT} ${DELETE}
CLEAN_LIBFT		= ${MAKE_LIBFT} ${CLEAN}
FCLEAN_LIBFT	= ${MAKE_LIBFT} ${FCLEAN}
RE_LIBFT		= ${MAKE_LIBFT} ${RE}


MAKE_MINILIBX	= ${MAKE_LIB} ${MINILIBX_PATH}
CLEAN_MINILIBX	= ${MAKE_MINILIBX} ${CLEAN}
RE_MINILIBX		= ${MAKE_MINILIBX} ${RE}


MATRIX_SOURCES	= $(wildcard ${SOURCES_PATH}matrix/*.c)
READ_SOURCES	= $(wildcard ${SOURCES_PATH}read_map/*.c)
CALC_SOURCES	= $(wildcard ${SOURCES_PATH}calculation/*.c)
EVENT_SOURCES	= $(wildcard ${SOURCES_PATH}event/*.c)
RENDER_SOURCES	= $(wildcard ${SOURCES_PATH}rendering/*.c)
ERROR_SOURCES	= $(wildcard ${SOURCES_PATH}error_handling/*.c)
COLOR_SOURCES	= $(wildcard ${SOURCES_PATH}color/*.c)
SOURCE_FILES	= ${SOURCES_PATH}main.c ${MATRIX_SOURCES} ${READ_SOURCES} ${CALC_SOURCES} ${EVENT_SOURCES} ${RENDER_SOURCES} ${ERROR_SOURCES} ${COLOR_SOURCES}
B_EVENT_SOURCES	= $(wildcard ${SOURCES_PATH}bonus/event/*.c)
B_CALC_SOURCES	= $(wildcard ${SOURCES_PATH}bonus/calculation/*.c)
BONUS_SOURCES	= $(wildcard ${SOURCES_PATH}bonus/*.c) ${B_EVENT_SOURCES} ${B_CALC_SOURCES} ${MATRIX_SOURCES} ${READ_SOURCES} ${CALC_SOURCES} ${EVENT_SOURCES} ${RENDER_SOURCES} ${ERROR_SOURCES} ${COLOR_SOURCES}
# "patsubst": pattern substitution
# parameters: pattern, replacement, text
#
# pattern: the pattern to match. Supports wildcards
# replacement: the string to replace the pattern with. By using wildcards, 
#              Make keeps the original text matched by the same 
#              wildcard in the pattern
# text: the list of strings on which the substitution will be performed
OBJECT_FILES	= ${patsubst ${SOURCES_PATH}%.c, ${OBJECTS_PATH}%.o, ${SOURCE_FILES}}
BONUS_OBJECTS	= ${patsubst ${SOURCES_PATH}%.c, ${OBJECTS_PATH}%.o, ${BONUS_SOURCES}}


CREATE_PATH		= mkdir -p
DELETE_FILE		= rm -f
DELETE_PATH		= rm -fr


## RULES ##
###########


${ALL}: ${NAME}


${OBJECTS_PATH}:
	@${CREATE_PATH} ${OBJECTS_PATH}
	@${CREATE_PATH} ${MATRIX_OBJ_PATH}
	@${CREATE_PATH} ${READ_OBJ_PATH}
	@${CREATE_PATH} ${CALC_OBJ_PATH}
	@${CREATE_PATH} ${EVENT_OBJ_PATH}
	@${CREATE_PATH} ${RENDER_OBJ_PATH}
	@${CREATE_PATH} ${ERROR_OBJ_PATH}
	@${CREATE_PATH} ${COLOR_OBJ_PATH}


${BONUS_OBJ_PATH}: ${OBJECTS_PATH}
	@${CREATE_PATH} ${BONUS_OBJ_PATH}
	@${CREATE_PATH} ${B_EV_OBJ_PATH}
	@${CREATE_PATH} ${B_CALC_OBJ_PATH}


# "$@" refers to the target (%.o)
# "$<" refers to the dependency (%.c)
#
# "|" the pipe syntax indicates that the ${OBJECTS_PATH} is 
#     an Order-Only Prerequisite of the "${OBJECTS_PATH}%.o" target.
#     Order-Only Prerequisites are required, but don't trigger a rebuild.
#     This means that if an Order-Only Prerequisite changes, its target 
#     is not built again
${OBJECTS_PATH}%.o: ${SOURCES_PATH}%.c | ${OBJECTS_PATH}
	@${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@


${NAME}: ${MINILIBX_NAME} ${LIBFT_NAME} ${OBJECT_FILES}
	@${CC} ${CFLAGS} ${OBJECT_FILES} ${LIBFT_NAME} -o ${NAME} ${INCLUDE_MLX}
	@echo "The program \"${NAME}\" has been compiled."


${CLEAN}: ${LIB_CLEAN}
	@${DELETE_FILE} ${OBJECT_FILES}
	@${DELETE_PATH} ${OBJECTS_PATH}
	@echo "The objects of program \"${NAME}\" have been deleted."


${FCLEAN}: ${LIB_CLEAN} ${LIB_DELETE} ${CLEAN} ${DEL_BONUS_FILE}
	@${DELETE_FILE} ${LIBFT_NAME}
	@${DELETE_FILE} ${NAME}
	@echo "The program \"${NAME}\" has been deleted."


${RE}: ${FCLEAN} ${ALL}


${BONUS}: ${MINILIBX_NAME} ${LIBFT_NAME} ${BONUS_OBJ_PATH} ${BONUS_OBJECTS}
	@if [ ! -e ${NAME} ]; then \
		${CC} ${CFLAGS} ${BONUS_OBJECTS} ${LIBFT_NAME} -o ${NAME} ${INCLUDE_MLX}; \
		echo "The program \"${NAME}\" has been compiled including bonus."; \
	else \
		echo "The program \"${NAME}\" already exists. Skipping compilation."; \
	fi


${CC_SANITIZER}: ${MINILIBX_NAME} ${LIBFT_NAME} ${OBJECT_FILES}
	@${CC} ${CFLAGS} ${SANITIZE_FLAGS} ${OBJECT_FILES} ${LIBFT_NAME} -o ${NAME} ${INCLUDE_MLX}
	@echo "C compiler's sanitizer has been added to debug memory issues."


${VALGRIND}: ${NAME}
	@${VALGRIND} ${VALGRIND_FLAGS} ./${NAME} ${VALGRIND_ARGS}


${MAP}: ${NAME}
	@./${NAME} ${MAP_ARGS}


${GDB}: ${NAME}
	@${GDB} ./${NAME}


# library rules
# #############


${MINILIBX_NAME}:
	@${MAKE_MINILIBX}


${LIBFT_NAME}:
	@${MAKE_LIBFT}


${LIB_DELETE}:
	@${DELETE_LIBFT}


${LIB_CLEAN}:
	@${CLEAN_LIBFT}
	@${CLEAN_MINILIBX}


${LIB_FCLEAN}:
	@${FCLEAN_LIBFT}
	@${CLEAN_MINILIBX}


${LIB_RE}:
	@${RE_LIBFT}
	@${RE_MINILIBX}


${PHONY}: ${STD_PHONY} ${DEBUG_PHONY} ${LIB_PHONY}
