# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/18 19:27:57 by thopgood          #+#    #+#              #
#    Updated: 2025/02/06 17:41:02 by thopgood         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -Iinclude
RM			= rm -rf
LIBC		= ar -rcs

# Directories
SRC_DIR		= src/
OBJ_DIR 	= obj/
HEADER		= include/libft.h

# Sources
SRC			= 	ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_strlen.c \
				ft_memset.c \
				ft_bzero.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_strlcpy.c \
				ft_strlcat.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_strchr.c \
				ft_strchr_no_null.c \
				ft_strrchr.c \
				ft_strncmp.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_strnstr.c \
				ft_atoi.c \
				ft_calloc.c \
				ft_strdup.c \
				ft_substr.c \
				ft_strjoin.c \
				join_var.c \
				ft_strtrim.c \
				ft_split.c \
				ft_itoa.c \
				ft_strmapi.c \
				ft_striteri.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_isspace.c \
				ft_putbase_fd.c \
				ft_abs.c \
				ft_lstnew.c \
				ft_lstadd_front.c \
				ft_lstsize.c \
				ft_lstlast.c \
				ft_lstadd_back.c \
				ft_lstdelone.c \
				ft_lstclear.c \
				ft_lstiter.c \
				ft_lstmap.c \
				ft_printf.c \
				ft_printf_utils.c \
				ft_printf_utils2.c \
				get_next_line.c \
				ft_strpbrk.c \
				count_words.c \
				ft_min_max.c \
				ft_array_size.c \
				ft_dprintf.c \
				ft_dprintf_utils.c \
				ft_dprintf_utils2.c \
				safe_free_array.c \
				free_array.c \
				safe_free.c \
				arr_length.c

OBJ			= $(addprefix $(OBJ_DIR), $(SRC:.c=.o))


$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@


$(NAME): $(OBJ)
	@echo ""${BLUE}$(NAME)""${NC}Archiving... "\c"
	@$(LIBC) $(NAME) $(OBJ)
	@echo ""${GREEN}OK""$(NC)""
	
all: $(NAME)

clean:
	@$(RM) $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus

# Colours
WHITE	=	'\033[0;37m'
YELLOW	=	'\033[0;33m'
BLUE	=	'\033[0;34m'
GREEN	=	'\033[0;32m'
RED		=	'\033[0;31m'
NC		=	'\033[0m' # no colour
#> /dev/null