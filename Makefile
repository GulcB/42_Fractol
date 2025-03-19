NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I./ft_printf
MLX_LIB = ./minilibx-linux/libmlx.a
LIBFT_DIR = ./libft 
LIBFT = $(LIBFT_DIR)/libft.a

SRC = src/burning_ship.c \
		src/color_scheme.c \
		src/color.c \
		src/events.c \
		src/init.c \
		src/julia.c \
		src/mandelbrot.c \
		src/render.c \
		src/utils.c \
		ft_printf/ft_printf_funcs.c \
		ft_printf/ft_printf.c \
		main.c

OBJS = $(SRC:.c=.o)

all: $(NAME) 

$(MLX_LIB):
	@make -C ./minilibx-linux

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(MLX_LIB) $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_LIB) -L$(LIBFT_DIR) -lft -o $(NAME) -lm -lX11 -lXext

clean:
	@make -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	@make -C ./libft fclean
	@make -C ./minilibx-linux clean
	$(RM) $(NAME) $(OBJ)

re: fclean all

.PHONY: all clean fclean re