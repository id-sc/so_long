# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hesainte <hesainte@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/21 17:00:00 by hesainte          #+#    #+#              #
#    Updated: 2026/10/07 10:20:28 by hesainte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = so_long

# Directories
SRC_DIR     = src/
OBJ_DIR     = obj/
INC_DIR     = include/
MLX_DIR     = mlx/ #linux
#MLX_DIR     = minilibx/ #mac
PRINTF_DIR  = printf/
GNL_DIR     = gnl/

# Files
SRCS_FILES   = 	main.c \
				check_errors.c \
				init_game.c \
				exit_game.c					\
				get_map_elements.c			\
				utils.c						\
				enemies.c					\
				sprite.c					\
				draw_images.c				\
				move_player.c				\
				move_enemy.c				\

GNL_FILES	=	get_next_line.c \
            	get_next_line_utils.c		\

SRCS        =	$(addprefix $(SRC_DIR), $(SRCS_FILES)) \
				$(addprefix $(GNL_DIR), $(GNL_FILES)) \


OBJS        = $(addprefix $(OBJ_DIR), $(notdir $(SRCS:.c=.o))) 
# Compilation
CC          = cc
# Added -I$(GNL_DIR) so the compiler finds get_next_line.h
CFLAGS      = -Wall -Wextra -Werror -Wno-incompatible-pointer-types -I$(INC_DIR) -I$(MLX_DIR) -I$(PRINTF_DIR)include -I$(GNL_DIR)
MLX_FLAGS = -Llib/mlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

#pour mon mac
#MLX_FLAGS	= -Lminilibx -lmlx -framework OpenGL -framework AppKit

PRINTF      = $(PRINTF_DIR)libftprintf.a

all: $(NAME)

$(NAME): $(OBJS) $(PRINTF)
	$(CC) $(OBJS) $(PRINTF) $(MLX_FLAGS) -o $(NAME)

# Rule for SRC_DIR files
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Rule for GNL_DIR files
$(OBJ_DIR)%.o: $(GNL_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(PRINTF):
	@make -C $(PRINTF_DIR)

clean:
	rm -rf $(OBJ_DIR)
	@make -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re