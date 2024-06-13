NAME	= fractol
SRCS	= fract_ol_utils.c fract_ol.c ft_mandelbrot.c julia.c mandelbrot_utils.c mlx.c 
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