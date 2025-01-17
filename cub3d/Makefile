.SILENT:
MAKEFLAGS += --no-print-directory

GREEN   		= \033[0;32m
TEAL    		= \033[1;36m
RESET 			= \033[0m 

NAME			=	cub3D

CC				=	cc

CFLAGS			=	-Wall -Wextra -Werror -gdwarf-4

RM				=	rm -rf

INC_DIR			=	includes/

SRC_DIR			=	sources/

OBJ_DIR			=	objs/

#PROG_DIR		=	program/

PARSER_DIR		=	parser/

#ERROR_DIR		=	errors/

#MATH_DIR		=	math/

#TYPES_DIR		=	t_types/

#RANDOM_MALLOC	=	-Xlinker --wrap=malloc

LIBS_DIR		=	libraries/

LFT_PATH		=	$(addprefix $(LIBS_DIR), libft/)

SRC				=	$(addprefix $(SRC_DIR), cub3D.c) \
					$(addprefix $(SRC_DIR)$(PARSER_DIR), check_map.c) \
#					#$(addprefix $(SRC_DIR), malloc.c)

OBJ_DIRS		=	$(OBJ_DIR) $(addprefix $(OBJ_DIR), $(PARSER_DIR)) \
					$(addprefix $(OBJ_DIR), $(SRC_DIR))

OBJ				=	$(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

$(NAME):			$(OBJ) | $(SRC) 
# Pc da escola					$(CC) $(CFLAGS) -lreadline $^ -o $@ -I $(INC_DIR) -L$(LFT_PATH) -lft
					$(CC) $(CFLAGS) $^ -o $@ -I $(INC_DIR) -L$(LFT_PATH) -lft -lncurses
					printf '$(GREEN)$(NAME) compiled successfully!\n $(RESET)'

$(OBJ_DIR)%.o:		$(SRC_DIR)%.c | $(OBJ_DIRS)
					make dependencies
					printf "$(TEAL)Compiling $(NAME) objects... %-33.33s\n$(RESET)" $(notdir $@) 
					$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR) 

$(OBJ_DIRS):
					mkdir -p $@

all:				$(NAME)

random_malloc:		$(OBJ) | $(SRC)
					$(CC) $(CFLAGS) $(RANDOM_MALLOC) -lreadline $^ -o $(NAME) -I $(INC_DIR) -L$(LFT_PATH) -lft
					printf '$(GREEN)$(NAME) compiled successfully!\n $(RESET)'

dependencies:
					make -C $(LFT_PATH)

clean:
					if [ -d $(OBJ_DIR) ]; then $(RM) $(OBJ_DIR); fi
					make clean -C $(LFT_PATH)

fclean:				clean
					$(RM) $(NAME)
					make fclean -C $(LFT_PATH)

re:					fclean all

val: $(NAME)
	make re 
	clear 
	valgrind --leak-check=full --show-leak-kinds=all --track-fds=all --track-origins=yes ./$(NAME)

.PHONY:				all clean fclean re val

