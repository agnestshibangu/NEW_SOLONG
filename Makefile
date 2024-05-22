# Nom de l'executable
NAME := so_long

CC := cc
# CC := gcc

# Options de compilation
CFLAGS := -Wall -Wextra -Werror -g
# CFLAGS := -Wall -Wextra -Werror -Iheaders/

# printf
PRINTF_NAME = my_printf 
PRINTF_PATH = ./my_printf/
PRINTF = $(PRINTF_PATH)$(PRINTF_NAME)

# Liste des fichiers source.
SRCS := main.c	

# Options de la bibliotheque MiniLibX et des bibliotheques systeme
LIBRARY := -Lminilibx -lmlx -L/usr/lib -lXext -lX11 -lm -lz 
# LIBRARY := -L./minilibx -lmlx -lXext -lX11 -lm
OBJS := $(SRCS:.c=.o)

INC := -I./my_printf/

# Default target
all: $(NAME)

# Rule to compile .c files to .o files
%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

# Rule to build the custom printf library
$(PRINTF):
	@make -C $(PRINTF_PATH)

# Rule to create the executable by linking the objects and the custom printf library
$(NAME): $(OBJS) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(LIBRARY) -o $(NAME) $(PRINTF)

# Rule to clean object files
clean:
	$(RM) $(OBJS)
	@make clean -C $(PRINTF_PATH)

# Rule to clean object files and the executable
fclean: clean
	$(RM) $(NAME)
	@make fclean -C $(PRINTF_PATH)

# Rule to force a rebuild
re: fclean all

# Declaring targets as .PHONY to avoid conflicts with files of the same name
.PHONY: all clean fclean re
