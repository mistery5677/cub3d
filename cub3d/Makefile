.SILENT:
MAKEFLAGS += --no-print-directory

GREEN   		= \033[0;32m
TEAL    		= \033[1;36m
RESET 			= \033[0m 

NAME			= cub3D

CC				= cc

CFLAGS			= -Wall -Wextra -Werror -gdwarf-4

RM				= rm -rf

INC_DIR			= includes/

SRC_DIR			= sources/

OBJ_DIR			= objs/

LIBS_DIR		= libraries/

LFT_PATH		= $(addprefix $(LIBS_DIR), libft/)

MINILIBX_DIR	= $(addprefix $(LIBS_DIR), minilibx/)

SRC				= $(addprefix $(SRC_DIR), cub3D.c) \
				  $(addprefix $(SRC_DIR)parser/, check_map.c check_texture.c)

OBJ				= $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ -I $(INC_DIR) -L$(LFT_PATH) -lft -L$(MINILIBX_DIR) -lX11 -lXext -lm
	printf '$(GREEN)$(NAME) compiled successfully!\n $(RESET)'

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	printf "$(TEAL)Compiling $(NAME) objects... %-33.33s\n$(RESET)" $(notdir $@)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR) 

$(OBJ_DIR):
	mkdir -p $@

all: $(NAME)

dependencies:
	make -C $(LFT_PATH)

clean:
	$(RM) $(OBJ_DIR)
	make clean -C $(LFT_PATH)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LFT_PATH)

re: fclean all

.PHONY: all clean fclean re
