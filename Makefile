NAME = fractol
NAME_BONUS = fractol_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror -O2 -I./includes
MLX_DIR = ./minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF_DIR = ./ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

SRCS = src/fractol.c \
       src/init.c \
       src/render.c \
       src/mandelbrot.c \
       src/julia.c \
       src/color.c \
       src/events.c \
       src/utils.c \
       src/funcs.c \
       src/view.c

BONUS_SRCS = bonus/fractol_bonus.c \
             bonus/init_bonus.c \
             bonus/render_bonus.c \
             bonus/mandelbrot_bonus.c \
             bonus/julia_bonus.c \
             bonus/burning_ship_bonus.c \
             bonus/color_bonus.c \
             bonus/color_scheme_0_bonus.c \
             bonus/color_scheme_1_bonus.c \
             bonus/color_scheme_2_bonus.c \
             bonus/color_scheme_3_bonus.c \
             bonus/color_scheme_4_bonus.c \
             bonus/color_schemes_bonus.c \
             bonus/events_bonus.c \
             bonus/utils_bonus.c \
             bonus/funcs_bonus.c \
             bonus/view_bonus.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

HEADERS = includes/fractol.h
BONUS_HEADERS = includes/fractol_bonus.h

all: $(LIBFT) $(PRINTF) $(MLX_LIB) $(NAME)

$(MLX_LIB):
	@make -C $(MLX_DIR)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(PRINTF):
	@make -C $(PRINTF_DIR)

$(NAME): $(MLX_LIB) $(LIBFT) $(PRINTF) $(OBJS)
	$(CC) $(CFLAGS) $^ -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf $(MLX_FLAGS) -o $@

bonus: $(LIBFT) $(PRINTF) $(MLX_LIB) $(NAME_BONUS)

$(NAME_BONUS): $(MLX_LIB) $(LIBFT) $(PRINTF) $(BONUS_OBJS)
	$(CC) $(CFLAGS) $^ -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf $(MLX_FLAGS) -o $@

$(OBJS): %.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_OBJS): %.o: %.c $(BONUS_HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR) clean
	@make -C $(PRINTF_DIR) clean
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@make -C $(PRINTF_DIR) fclean
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all bonus

.PHONY: all clean fclean re bonus
