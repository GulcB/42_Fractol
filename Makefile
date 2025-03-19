NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I./ft_printf
LIBFT_DIR = ./libft 
LIBFT = $(LIBFT_DIR)/libft.a

SRC = src/burning_ship.c \
		src/init.c \
		src/julia.c \
		src/mandelbrot.c \
		src/render.c \
		src/utils.c \
		ft_printf/ft_printf_funcs.c \
		ft_printf/ft_printf.c \

OBJS = $(SRC:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME) -lm -lX11 -lXext

clean:
	@make -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	@make -C $(LIBFT_DIR) clean
	$(RM) $(NAME) $(OBJ)

re: fclean all

.PHONY: all clean fclean re