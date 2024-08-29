CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

SRC = check_map_utils.c \
	check_map.c \
	open_map.c \
	ft_error.c \
	main.c \
	get_next_line.c \
	flood_fill.c \
	window.c \
	keypress.c \
	ft_printf.c 

OBJ = $(SRC:.c=.o)
EXEC = so_long

INCLUDES = -I/usr/include -Imlx

MLX_DIR = ./mlx
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

LIBNAME = ./Libft
LIBDIR = $(LIBNAME)/libft.a

all: $(EXEC)

$(EXEC): $(OBJ) $(LIBDIR)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ) $(LIBDIR) $(MLX_FLAGS)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

$(MLX_LIB):
	@make -C $(MLX_DIR)

$(LIBDIR):
	@make -C $(LIBNAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(EXEC)

re: fclean all

.PHONY: all clean fclean re
