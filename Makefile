#SETUP
NAME		=	so_long
CC			=	cc
FLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf

#FILES AND PATH
HEADER_SRCS	=	so_long.h
HEADER_DIR	=	includes/
HEADER		=	$(addprefix $(HEADER_DIR), $(HEADER_SRCS))

MPATH_SRCS	=	main.c window.c
MPATH_DIR	=	mandatory/
MPATH		=	$(addprefix $(MPATH_DIR), $(MPATH_SRCS))
OBJ_M		=	$(MPATH:.c=.o)

FPATH_SRCS	=	ft_calloc.c
FPATH_DIR	=	functions/
FPATH		=	$(addprefix $(FPATH_DIR), $(FPATH_SRCS))
OBJ_F		=	$(FPATH:.c=.o)

PATH_MLX	=	mlx/
LIB_MLX		=	$(PATH_MLX)/libmlx.a

#COMMANDS
%.o: %.c
				@${CC} ${FLAGS} -Imlx -c $< -o $@

$(NAME):		$(OBJ_M) $(OBJ_F) | $(LIB_MLX)
				@$(CC) $(OBJ_M) $(OBJ_F) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
				@echo "$(GREEN)$(NAME) created!$(DEFAULT)"

$(LIB_MLX):
				@make -C $(PATH_MLX)

all:			$(NAME)

clean:
				@$(RM) $(OBJ_M) $(OBJ_B) $(OBJ_F)
				@echo "$(YELLOW)object files deleted!$(DEFAULT)"

fclean:			clean
				@$(RM) $(NAME)
				@make clean -C $(PATH_MLX)
				@echo "$(RED)all deleted!$(DEFAULT)"

re:				fclean all

.PHONY:		all clean fclean re

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m