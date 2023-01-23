#SETUP
OS			=	$(shell uname)
NAME		=	so_long
CC			=	cc
FLAGS		=	-Wall -Wextra -Werror
ifeq ($(OS), Linux)
	MLX_FLAGS	=	-Lmlx_linux -lmlx_Linux -lX11 -lXext -lm -lz -O3
else
	MLX_FLAGS	=	-Lmlx -lmlx -framework OpenGL -framework AppKit
endif
RM			=	rm -rf

#FILES AND PATH
HEADER_SRCS	=	so_long.h
HEADER_DIR	=	includes/
HEADER		=	$(addprefix $(HEADER_DIR), $(HEADER_SRCS))

MPATH_SRCS	=	main.c errors.c map.c map_utils.c
MPATH_DIR	=	mandatory/
MPATH		=	$(addprefix $(MPATH_DIR), $(MPATH_SRCS))
OBJ_M		=	$(MPATH:.c=.o)

FPATH_SRCS	=	ft_calloc.c ft_strchr.c ft_strjoin.c ft_strlen.c \
				ft_split.c ft_strdup.c ft_strlcat.c get_next_line.c \
				ft_strarr_free.c ft_strarr_copy.c
FPATH_DIR	=	functions/
FPATH		=	$(addprefix $(FPATH_DIR), $(FPATH_SRCS))
OBJ_F		=	$(FPATH:.c=.o)

ifeq ($(OS), Linux)
	PATH_MLX	=	mlx_linux/
else
	PATH_MLX	=	mlx/
endif
LIB_MLX		=	$(PATH_MLX)/libmlx.a

#COMMANDS
%.o: %.c
				@${CC} ${FLAGS} -Imlx -c $< -o $@

$(NAME):		$(OBJ_M) $(OBJ_F) | $(LIB_MLX)
				@$(CC) $(OBJ_M) $(OBJ_F) $(MLX_FLAGS) -o $(NAME)
				@echo "$(GREEN)$(NAME) created!$(DEFAULT)"

$(LIB_MLX):
				@make -C $(PATH_MLX)

all:			$(NAME)

clean:
				@$(RM) $(OBJ_M) $(OBJ_B) $(OBJ_F)
				@echo "$(YELLOW)object files deleted!$(DEFAULT)"

fclean:			clean
				@$(RM) $(NAME)
				@echo "$(RED)all deleted!$(DEFAULT)"

re:				fclean all

.PHONY:		all clean fclean re

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m