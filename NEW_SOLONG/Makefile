CC := cc
CFLAGS := -Wall -Wextra -Werror -g
NAME := so_long
MLX_PATH := ./minilibx/
MLX_LIB := $(MLX_PATH)/libmlx.a

PRINTF_DIR := ./my_printf/
PRINTF_SRCS := $(wildcard $(PRINTF_DIR)*.c)
PRINTF_OBJS := $(patsubst $(PRINTF_DIR)%.c, $(PRINTF_DIR)%.o, $(PRINTF_SRCS))

SRCS := main.c \
		$(PRINTF_OBJS) \
		logic/checkmap.c \
		logic/checkmap2.c \
		logic/checkmap3.c \
		logic/controls.c \
		logic/controls2.c \
		logic/floodfill.c \
		logic/free.c \
		logic/gnl_utils.c \
		logic/gnl_function.c \
		logic/gnl.c \
		logic/init_window.c \
		logic/init.c \
		logic/map.c \

		
LIBRARY := -Lminilibx -lmlx -L/usr/lib -lXext -lX11 -lm -lz 
OBJS := $(SRCS:.c=.o)
INC := -I./my_printf/

# Default target
all: $(NAME)

# Rule to compile .c files to .o files
%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

# Rule to build the custom printf library
$(PRINTF_OBJS): $(PRINTF_SRCS)
	@make -C $(PRINTF_DIR)

$(MLX_LIB):
	@make -C $(MLX_PATH)

# Rule to create the executable by linking the objects and the custom printf library
$(NAME): $(OBJS) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIBRARY) -o $(NAME)

# Rule to clean object files
clean:
	$(RM) $(OBJS)
	@make clean -C $(PRINTF_DIR)
	@make clean -C $(MLX_PATH)

# Rule to clean object files and the executable
fclean: clean
	$(RM) $(NAME)
	@make fclean -C $(PRINTF_DIR)
	@make clean -C $(MLX_PATH)

# Rule to force a rebuild
re: fclean all

# Declaring targets as .PHONY to avoid conflicts with files of the same name
.PHONY: all clean fclean re