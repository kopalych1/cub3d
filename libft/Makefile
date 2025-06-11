# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akostian <akostian@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/11 10:07:13 by akostian          #+#    #+#              #
#    Updated: 2024/10/30 18:53:59 by akostian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

VPATH		= src:src/is:src/mem:src/str:src/to:src/math:src/fd_put:src/lst:src/ft_printf
SRCS		= ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_isspace.c \
			  ft_bzero.c ft_calloc.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_realloc.c \
			  ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strcmp.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
			  ft_atoi.c ft_itoa.c ft_tolower.c ft_toupper.c \
			  ft_abs.c ft_power.c \
			  ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
			  ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c \
			  ft_split.c ft_striteri.c ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_substr.c \
			  get_next_line.c \
			  ft_printf.c ft_putchar.c ft_puthex.c ft_putll_nbr.c ft_putptr.c ft_putstr.c


BUILD_DIR	= build
OBJS		= $(addprefix $(BUILD_DIR)/, $(SRCS:%.c=%.o))

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -Iinclude
AR			= ar
ARFLAGS		= rcs
RM			= rm -rf



all: $(NAME)
#


$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^
#


$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)
#


$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
#


clean:
	$(RM) $(BUILD_DIR)
#


fclean: clean
	$(RM) $(NAME)
#


re: fclean all
#



.PHONY: all clean fclean re