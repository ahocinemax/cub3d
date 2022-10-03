#------------------------------------#
#             COMPILATION            #
#------------------------------------#

NAME		= cub3d

FLAGS		= -Wall -Wextra -Werror -g3
INCLUDE		= -I $(HEAD_DIR) -lXext -lX11 -lm
CC			= gcc

#------------------------------------#
#               SOURCES              #
#------------------------------------#

SRCS		=	$(addprefix $(SRC_DIR), $(SRC_FILE))
SRC_DIR		=	srcs/
SRC_FILE	=	cub3d.c							\
				struct_handler.c				\
				parsing_utils.c					\
				checker_info.c					\
				checker_map.c					\
				errors.c						\
				fill_info.c						\
				fill_map.c						\
				raycasting/init_ray.c			\
				raycasting/init_struct_game.c	\
				raycasting/raycasting.c			\
				raycasting/setting_player.c		\
				game/free_all.c					\
				game/init_struct.c				\
				game/init_game.c				\
				game/intro_image.c				\
				image/image.c					\

#------------------------------------#
#               OBJECTS              #
#------------------------------------#

OBJS	=	$(addprefix $(OBJ_DIR), $(OBJ))
OBJ		=	$(SRC_FILE:.c=.o)
OBJ_DIR	=	obj/

#------------------------------------#
#              INCLUDES              #
#------------------------------------#

HEADER		= $(addprefix $(HEAD_DIR), $(HEAD_FILE))
HEAD_DIR	= includes/
HEAD_FILE	= cub3d.h

LIBFT		= $(addprefix $(LIB_DIR), $(LIBFT_A))
LIB_DIR		= libft/
LIBFT_A		= libft.a

LIBMLX		=	$(addprefix $(MLX_DIR), $(LIBMLX_A))
MLX_DIR		=	mlx/
LIBMLX_A	=	libmlx.a

#------------------------------------#
#               COLORS               #
#------------------------------------#

END		= "\033[0m"
GREEN		= "\033[32m"
YELLOW		= "\033[33m"
GRAY		= "\033[2;37m"
CURSIVE		= "\033[3m"

#------------------------------------#
#                RULES               #
#------------------------------------#

all: $(NAME)

$(NAME): $(OBJS)
	@echo $(CURSIVE)$(GREEN) "     ~ Making $(LIB_DIR)..." $(END)
	make -C $(LIB_DIR)
	@echo $(CURSIVE)$(GREEN) "     ~ Making $(MLX_DIR)..." $(END)
	make -C $(MLX_DIR)
	@echo $(CURSIVE)$(GRAY) "     - Making object files..." $(END)
	@echo $(CURSIVE)$(GRAY) "     - Compiling $(NAME)..." $(END)
	@$(CC) $(FLAGS) $(OBJS) $(LIBFT) $(LIBMLX) $(INCLUDE)  -o $(NAME)
	@echo $(GREEN)"- Project compiled -"$(END)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER)
	@mkdir -p $(OBJ_DIR) $(OBJ_DIR)/raycasting/ $(OBJ_DIR)/game/ $(OBJ_DIR)/image/
	@$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

clean:
	@echo $(CURSIVE)$(GRAY) "     - Removing object files..." $(END)
	make -C $(LIB_DIR) clean
	# make -C $(MLX_DIR) clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo $(CURSIVE)$(GRAY) "     - Removing $(NAME)..." $(END)
	@rm -f $(NAME)
	make fclean -C $(LIB_DIR)
	@echo $(YELLOW)"- Project removed -"$(END)

re: fclean all

.PHONY : clean fclean re
