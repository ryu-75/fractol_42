PREFIXE					= fractol
EXEC					= $(PREFIXE)

# ------------------- [Library] ---------------------------------------

MLX						= mlx/Makefile
INC						= -I ./include -I ./libft ./mlx_linux # include each folder from root

# ------------------- [Source] ----------------------------------------

DIR_SRC					= src
SRC						= $(DIR_SRC)/main.c		\
							$(DIR_SRC)/fractal.c	\
							$(DIR_SRC)/display.c	\
							$(DIR_SRC)/utils.c		\
							$(DIR_SRC)/color.c		\
							$(DIR_SRC)/event.c		\
							$(DIR_SRC)/render.c		\
							$(DIR_SRC)/action.c
							
OBJ						= $(SRC:.c=.o)
DEP						= $(SRC:.c=.d)
						
%.o						: %.c
						$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@
						$(CC) -c $(CFLAGS) $*.c -o $*.o
						$(CC) -MM $(CFLAGS) $*.c -o $*.d


$(EXEC)					: libft/libft.a $(OBJ)
						$(CC) $(OBJ) -L libft -lft -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(EXEC)

# ------------------- [Compilation] ----------------------------------

CC						= cc

CFLAGS					= -g -Wall -Wextra -Werror 	

all						: $(EXEC)

libft/libft.a			:
						make -C libft

clean					:
						rm -rf $(OBJ) $(DEP)
						make clean -C libft


fclean					: clean
						rm -rf $(EXEC)
						rm -rf object
						make fclean -C libft

re						: fclean
						@make all

.PHONY					= all clean fclean re object