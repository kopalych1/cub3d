# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akostian <akostian@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/10 14:47:56 by akostian          #+#    #+#              #
#    Updated: 2025/04/29 22:21:33 by akostian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME					= cub3d

VPATH					= src

SRC_DIR					= src
SRCS					= main.c \
						  init.c \
						  is_control_key.c \
						  utils.c \
						  wall_inter.c wall_direction.c \
						  get_pixel_color.c \
						  load_tex.c \
						  draw.c

INC_DIR					= include
INCLUDES				= -I$(INC_DIR)

BUILD_DIR				= build
LIBFT_DIR				= libft
LIBFT					= $(LIBFT_DIR)/libft.a
LOG_DIR					= logs
OBJS					= $(addprefix $(BUILD_DIR)/, $(SRCS:%.c=%.o))

CC						= cc
CFLAGS					= -Wall -Wextra -Werror -g3

NORMINETTE				= norminette
NORMINETTE_FLAGS		= --use-gitignore

RM						= rm -rf


UNAME		= $(shell uname -s)
# MLX FLAGS FOR LINUX
ifeq ($(UNAME), Linux)
	MLX_DIR				= minilibx-linux
	MLX_FLAGS			= -L$(MLX_DIR) -lmlx -L/usr/lib/X11 -lXext -lX11
	MLX_C_INC			= -I/usr/include -Imlx_linux -O3 
	MLX_LIB				= $(MLX_DIR)/libmlx_Linux.a

# MLX FLAGS FOR MACOS
else
	MLX_DIR				= mlx_macos
	MLX_FLAGS			= -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
	MLX_C_INC			= -I$(MLX_DIR)
	MLX_LIB				= $(MLX_DIR)/libmlx.a

endif


all: $(NAME)
#


$(NAME): $(OBJS) $(LIBFT) $(MLX_LIB)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) $(MLX_FLAGS) $(MLX_LIB) -o $(NAME) -lm
#


$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)
#

$(LIBFT):
	make -C $(LIBFT_DIR)
#

$(MLX_LIB):
	make -C $(MLX_DIR)
#

$(LOG_DIR):
	mkdir -p $(LOG_DIR)
#


$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
#


run: all
	./$(NAME)
#

vrun: all
	valgrind --track-origins=yes --leak-check=full ./$(NAME)
#

norm:
	$(NORMINETTE) $(NORMINETTE_FLAGS) $(SRC_DIR)/ $(INC_DIR)/
#

clean:
	$(RM) $(BUILD_DIR)
#


fclean:
	$(RM) $(BUILD_DIR) $(NAME)
#


re: fclean all
#



.PHONY: all clean fclean re