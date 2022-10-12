#------------------------------------#
#             COMPILATION            #
#------------------------------------#

NAME		= cub3D_bonus

FLAGS		= -Wall -Wextra -Werror -g3
INCLUDE		= -I $(HEAD_DIR) -lXext -lX11 -lm
CC			= gcc

#------------------------------------#
#               SOURCES              #
#------------------------------------#

SRCS		=	$(addprefix $(SRC_DIR), $(SRC_FILE))
SRC_DIR		=	srcs/
SRC_FILE	=	cub3d_bonus.c						\
				parsing/struct_init_bonus.c			\
				parsing/struct_init2_bonus.c		\
				parsing/struct_free_bonus.c			\
				parsing/parsing_utils_bonus.c		\
				parsing/checker_info_bonus.c		\
				parsing/checker_map_bonus.c			\
				parsing/errors_bonus.c				\
				parsing/fill_info_bonus.c			\
				parsing/fill_map_bonus.c			\
				raycasting/init_ray_bonus.c			\
				raycasting/raycasting_bonus.c		\
				raycasting/drawing_bonus.c			\
				raycasting/color_and_image_bonus.c	\
				game/init_game_bonus.c				\
				game/intro_image_bonus.c			\
				game/key_press_adsw_bonus.c			\
				game/key_press_rotate_bonus.c		\
				game/minimap_bonus.c

#------------------------------------#
#               OBJECTS              #
#------------------------------------#

OBJS		=	$(addprefix $(OBJ_DIR), $(OBJ))
OBJ			=	$(SRC_FILE:.c=.o)
OBJ_DIR		=	obj/


#------------------------------------#
#              INCLUDES              #
#------------------------------------#

HEADER		= $(addprefix $(HEAD_DIR), $(HEAD_FILE))
HEAD_DIR	= includes/
HEAD_FILE	= cub3d_bonus.h

LIBFT		= $(addprefix $(LIB_DIR), $(LIBFT_A))
LIB_DIR		= libft/
LIBFT_A		= libft.a

LIBMLX		=	$(addprefix $(MLX_DIR), $(LIBMLX_A))
MLX_DIR		=	mlx/
LIBMLX_A	=	libmlx.a

#------------------------------------#
#               COLORS               #
#------------------------------------#

END			= "\033[0m"
GREEN		= "\033[32m"
YELLOW		= "\033[33m"
GRAY		= "\033[2;37m"
CURSIVE		= "\033[3m"

#------------------------------------#
#                RULES               #
#------------------------------------#

all: $(NAME)

bonus: $(NAME)

$(NAME): $(OBJS)
	@echo $(CURSIVE)$(GREEN) "     ~ Making $(LIB_DIR)..." $(END)
	make -C $(LIB_DIR)
	@echo $(CURSIVE)$(GREEN) "     ~ Making $(MLX_DIR)..." $(END)
	make -C $(MLX_DIR)
	@echo $(CURSIVE)$(GRAY) "     - Making object files..." $(END)
	@echo $(CURSIVE)$(GRAY) "     - Compiling $(NAME)..." $(END)
	$(CC) $(FLAGS) $(OBJS) $(LIBFT) $(LIBMLX) $(INCLUDE)  -o $(NAME)
	@echo $(GREEN)"- Project compiled -"$(END)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER)
	@mkdir -p $(OBJ_DIR) $(OBJ_DIR)raycasting $(OBJ_DIR)game $(OBJ_DIR)parsing
	$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

clean:
	@echo $(CURSIVE)$(GRAY) "     - Removing object files..." $(END)
	make -C $(LIB_DIR) clean
	make -C $(MLX_DIR) clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo $(CURSIVE)$(GRAY) "     - Removing $(NAME)..." $(END)
	@rm -f $(NAME) $(NAME_BONUS)
	make fclean -C $(LIB_DIR)
	@echo $(YELLOW)"- Project removed -"$(END)

re: fclean all

.PHONY : clean fclean re
