PREFIXE    = fractol
EXEC       = $(PREFIXE)

# ------------------- [Library] ---------------------------------------

MLX        = mlx_linux/libmlx.a
LIBFT      = libft/libft.a

# ------------------- [Source] ----------------------------------------

DIR_SRC    = src/
SRC        = main.c        \
             fractal.c     \
             utils.c       \
             color.c       \
             event.c       \
             action.c      \
             generator.c   \
             complex.c     \
             init.c        \
             error.c

SRCS       = $(addprefix $(DIR_SRC), $(SRC))
OBJ_DIR    = obj/
OBJS       = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

# ------------------- [Compilation] ----------------------------------

CC         = cc
CFLAGS     = -g -Wall -Wextra -Werror

all        : $(MLX) $(LIBFT) $(EXEC)

$(MLX)     :
			@echo "Making MiniLibx..."
			@make -sC mlx_linux

$(LIBFT)   :
			@echo "Making Libft..."
			@make -sC libft

$(EXEC)    : $(OBJS)
			@echo "Compiling fractol..."
			@$(CC) $(CFLAGS) -o $(EXEC) $(OBJS) $(MLX) $(LIBFT) -L/usr/lib -lXext -lX11 -lm
			@echo "Fractol ready"

$(OBJ_DIR) :
				@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(DIR_SRC)%.c | $(OBJ_DIR)
				@$(CC) $(CFLAGS) -c $< -o $@ -I./include -I./libft -I./mlx_linux

clean      :
			@echo "Removing .o object files..."
			@rm -rf $(OBJ_DIR)
			@make clean -C libft/
			@make clean -C mlx_linux/

fclean     :	clean
				@echo "Removing fractol..."
				@rm -rf $(EXEC)
				@rm -rf libft/libft.a

re         : fclean all

.PHONY     : all clean fclean re
