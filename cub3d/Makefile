LIBFT_PATH		=	libraries/libft
LIBFT			=	$(LIBFT_PATH)/libft.a

MINILIBX_PATH	=	libraries/minilibx
MINILIBX		=	$(MINILIBX_PATH)/libmlx.a

SOURCES_FILES	=	cub3D.c \
					draw/draw_textures.c \
					errors/close_game.c \
					initialize/init.c \
					gameplay/gameplay.c gameplay/move_player.c \
					render/render.c render/raycasting.c\
					debug_function/debug.c \
					parser/check_map.c parser/check_texture.c parser/verify_matrix_utils.c\

SOURCES_DIR		=	sources

HEADER			=	includes/cub.h

SOURCES			=	$(addprefix $(SOURCES_DIR)/, $(SOURCES_FILES))

OBJECTS			=	$(SOURCES:.c=.o)

NAME			=	cub3D

CC				=	cc
RM				=	rm -rf

CFLAGS			=	-Wall -Wextra -Werror
MLXFLAGS		=	-L. -lXext -L. -lX11

.c.o:
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:			$(NAME)

$(NAME):		$(LIBFT) $(MINILIBX) $(OBJECTS) $(HEADER)
				$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) $(MINILIBX) $(MLXFLAGS) -o $(NAME) -lm 
				#-lm.   Para compilar com a biblioteca math.h

$(LIBFT):
				$(MAKE) -C $(LIBFT_PATH)

$(MINILIBX):
				$(MAKE) -C $(MINILIBX_PATH)

clean:
				$(MAKE) -C $(LIBFT_PATH) clean
				$(MAKE) -C $(MINILIBX_PATH) clean
				$(RM) $(OBJECTS) $(OBJECTS_BONUS)

fclean:			clean
				$(MAKE) -C $(LIBFT_PATH) fclean
				$(RM) $(NAME) $(NAME_BONUS)

re:				fclean all

.PHONY:			all clean fclean re libft minilibx bonus
