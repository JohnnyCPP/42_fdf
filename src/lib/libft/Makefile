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
OBJECTS_PATH	= ./object/
BIT_OBJ_PATH	= ${OBJECTS_PATH}ft_bit/
CHAR_OBJ_PATH	= ${OBJECTS_PATH}ft_char/
STRING_OBJ_PATH	= ${OBJECTS_PATH}ft_string/
MEMORY_OBJ_PATH = ${OBJECTS_PATH}ft_memory/
FD_OBJ_PATH		= ${OBJECTS_PATH}ft_fd/
FUNC_OBJ_PATH	= ${OBJECTS_PATH}ft_function/
LIST_OBJ_PATH	= ${OBJECTS_PATH}ft_list/
PRINTF_OBJ_PATH	= ${OBJECTS_PATH}ft_printf/
GNL_OBJ_PATH	= ${OBJECTS_PATH}ft_gnl/
MATH_OBJ_PATH	= ${OBJECTS_PATH}ft_math/
SOURCES_PATH	= ./src/


LIBRARY_NAME	= libft.a


CC				= cc
CFLAGS			= -Wall -Wextra -Werror
INCLUDE			= -I ${INCLUDES_PATH}
MAKE_LIB		= make -sC


BIT_SOURCES		= $(wildcard ${SOURCES_PATH}ft_bit/*.c)
CHAR_SOURCES	= $(wildcard ${SOURCES_PATH}ft_char/*.c)
STRING_SOURCES	= $(wildcard ${SOURCES_PATH}ft_string/*.c)
MEMORY_SOURCES	= $(wildcard ${SOURCES_PATH}ft_memory/*.c)
FD_SOURCES		= $(wildcard ${SOURCES_PATH}ft_fd/*.c)
FUNC_SOURCES	= $(wildcard ${SOURCES_PATH}ft_function/*.c)
LIST_SOURCES	= $(wildcard ${SOURCES_PATH}ft_list/*.c)
PRINTF_SOURCES	= $(wildcard ${SOURCES_PATH}ft_printf/*.c)
GNL_SOURCES		= $(wildcard ${SOURCES_PATH}ft_gnl/*.c)
MATH_SOURCES	= $(wildcard ${SOURCES_PATH}ft_math/*.c)
SOURCE_FILES	= $(wildcard ${SOURCES_PATH}*.c) ${BIT_SOURCES} ${CHAR_SOURCES} ${STRING_SOURCES} ${MEMORY_SOURCES} ${FD_SOURCES} ${FUNC_SOURCES} ${LIST_SOURCES} ${PRINTF_SOURCES} ${GNL_SOURCES} ${MATH_SOURCES}
OBJECT_FILES	= $(patsubst ${SOURCES_PATH}%.c, ${OBJECTS_PATH}%.o, ${SOURCE_FILES})


CREATE_INDEX	= ranlib
CREATE_LIB		= ar rc
CREATE_PATH		= mkdir -p
DELETE_FILE		= rm -f
DELETE_PATH		= rm -fr


ALL				= all
DELETE			= delete_library
CLEAN			= clean
FCLEAN			= fclean
RE				= re


## RULES ##
###########


${ALL}: ${LIBRARY_NAME}


${OBJECTS_PATH}:
	@${CREATE_PATH} ${OBJECTS_PATH}
	@${CREATE_PATH} ${BIT_OBJ_PATH}
	@${CREATE_PATH} ${CHAR_OBJ_PATH}
	@${CREATE_PATH} ${STRING_OBJ_PATH}
	@${CREATE_PATH} ${MEMORY_OBJ_PATH}
	@${CREATE_PATH} ${FD_OBJ_PATH}
	@${CREATE_PATH} ${FUNC_OBJ_PATH}
	@${CREATE_PATH} ${LIST_OBJ_PATH}
	@${CREATE_PATH} ${PRINTF_OBJ_PATH}
	@${CREATE_PATH} ${GNL_OBJ_PATH}
	@${CREATE_PATH} ${MATH_OBJ_PATH}


${OBJECTS_PATH}%.o: ${SOURCES_PATH}%.c | ${OBJECTS_PATH}
	@${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@


${LIBRARY_NAME}: ${OBJECT_FILES}
	@${CREATE_LIB} ${LIBRARY_NAME} ${OBJECT_FILES}
	@${CREATE_INDEX} ${LIBRARY_NAME}
	@echo "The library \"${LIBRARY_NAME}\" has been compiled."


${DELETE}:
	@${DELETE_FILE} ${LIBRARY_NAME}
	@echo "The library \"${LIBRARY_NAME}\" has been deleted."


${CLEAN}:
	@${DELETE_FILE} ${OBJECT_FILES}
	@${DELETE_PATH} ${OBJECTS_PATH}
	@echo "The objects of library \"${LIBRARY_NAME}\" have been deleted."


${FCLEAN}: ${CLEAN} ${DELETE}


${RE}: ${FCLEAN} ${ALL}


.PHONY: ${ALL} ${DELETE} ${CLEAN} ${FCLEAN} ${RE}
