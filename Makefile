# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/01 10:04:16 by ftothmur          #+#    #+#              #
#    Updated: 2019/07/19 10:12:51 by ftothmur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-------------------------------------MISC-------------------------------------#
.PHONY:				all lib clean cleanm clean_lib fclean re re_lib re_all
NAME =				fillit
LIB =				libft.a
#---------------------------------DIRECTIRIES----------------------------------#
LIB_DIR =			./libft/
HDR_LIB_DIR =		./libft/
SRC_DIR =			./
#---------------------------------SOURCE_FILES---------------------------------#
OBJ = 				$(SRC:.c=.o)
SRC =       		fillit.c \
					validation.c \
					validation_matching.c \
					validation_recognition.c \
					solution.c \
					solution_placing_and_limiting.c \
					printing_of_the_result.c

#-------------------------------COMPILER_OPTIONS-------------------------------#
LIB_FLAGS =			-L$(LIB_DIR) -lft
I_FLAGS =			-I $(HDR_LIB_DIR)
DEBUG ?=			0
ifeq ($(DEBUG), 0)
	CC_FLAGS =		-Wall -Wextra -Werror
else
	CC_FLAGS =		-Wall -Wextra -Werror -g
endif
#-------------------------------------RULES------------------------------------#
all:				$(NAME)

$(NAME):			$(LIB_DIR)$(LIB) $(OBJ) 
					gcc -o $(NAME) $(OBJ) $(I_FLAGS) $(LIB_FLAGS)

$(LIB_DIR)$(LIB):	lib

lib:
					make -C $(LIB_DIR)

%.o : 				$(SRC_DIR)%.c
					gcc -c $(CC_FLAGS) $^ $(I_FLAGS)

clean:				clean_lib
					/bin/rm -f *.o

clean_lib:
					make clean -C $(LIB_DIR)

cleanm:	
					/usr/bin/find . \
						\( \
							-name "*~" -o \
							-name "#*#" -o \
							-name "a.out" -o \
							-name "*.swp" -o \
							-name "*.swo" \
						\) \
						-print -delete
fclean_lib:
					make fclean -C $(LIB_DIR)


fclean: 			clean cleanm fclean_lib 
					/bin/rm -f $(NAME)

re:					fclean all

re_lib:
					make re -C $(LIB_DIR)

re_all:				re_lib re
