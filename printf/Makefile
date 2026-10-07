# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hesainte <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/21 17:00:00 by hesainte          #+#    #+#              #
#    Updated: 2026/01/21 17:00:00 by hesainte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = libftprintf.a
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -I$(INC_DIR)

INC_DIR     = include/
SRC_DIR     = src/
OBJ_DIR     = obj/

# Add the prefix to your source files
SRC_FILES   = ft_printf.c ft_iftype.c ft_checkformat.c utils.c utils2.c
SRCS        = $(addprefix $(SRC_DIR), $(SRC_FILES))

# This converts src/file.c to obj/file.o
OBJS        = $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

all: $(NAME)

# Compile the library
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	@echo "Library $(NAME) created."

# Rule for object files in the obj/ directory
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	@echo "Objects removed."

fclean: clean
	rm -f $(NAME)
	@echo "Library removed."

re: fclean all

.PHONY: all clean fclean re