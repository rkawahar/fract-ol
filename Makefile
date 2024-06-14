NAME	= fractol
SRCS	= main.c utils.c mandelbrot.c julia.c mlx.c ft_atoi.c ft_atod.c
CC 		= cc
CFLAGS 	= -Wall -Wextra -Werror

MLX_LNK	= -L $(MLX) -l mlx -framework OpenGL -framework AppKit

OBJ = $(SRCS:.c=.o)
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.cclear

	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re