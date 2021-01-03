NAME = miniRT

SRCS = ${wildcard src/*.c}

INCLUDES = includes

OBJS		= ${SRCS:.c=.o}

LIBFT_DIR = libft

SRCS_LIBFT = ${wildcard libft/*.c}

OBJS_LIBFT		= ${SRCS_LIBFT:.c=.o}

MLX_DIR = mlx_linux

CC			= gcc

MLX_FLAGS = -lm -lbsd -lXext -lX11 -pthread

LFLAGS =  -D BUFFER_SIZE=100

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror -Ofast -flto -march=native -g3 -O3

all: 			$(NAME)

$(NAME):		$(OBJS) $(OBJS_LIBFT)
				@make -C $(MLX_DIR)
				@make -C $(LIBFT_DIR)
				@$(CC) $(CFLAGS) $(LFLAGS) -I $(INCLUDES) $(OBJS)  $(OBJS_LIBFT) -o $(NAME) -L./mlx_linux -lmlx_Linux -lm -lbsd -lXext -lX11 -lpthread

%.o: %.c
				@$(CC) $(CFLAGS) $(LFLAGS)  -I $(INCLUDES) -o $@ -c $<

clean:
				${RM} ${OBJS}
				@make clean -C $(MLX_DIR)
				@make clean -C $(LIBFT_DIR)

fclean:			clean
				${RM} ${NAME}
				@$(RM) miniRT.bmp
				@make fclean -C $(LIBFT_DIR)

re:				fclean all

.PHONY:			all clean fclean re