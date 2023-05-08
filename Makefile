NAME	=	so_long
SRCS	=	get_next_line.c get_next_line_utils.c main.c map_dup.c map_parsing.c \
			map_parsing_2.c so_long_utils.c so_long_utils_2.c

FLAGS	=	-Wall -Wextra -Werror -fsanitize=address
OBJS	=	$(SRCS:.c=.o)
GCCO	=	gcc $(FLAGS) -c $(SRCS) -I libft -I mlx/mlx.h -I mlx/mlx_int.h
GCC		=	gcc $(FLAGS) -o $(NAME) $(OBJS) libft/libft.a mlx/libmlx.a -framework OpenGL -framework AppKit

all	:	
		@make -C mlx
		@make -C libft
		$(GCCO)
		$(GCC)

mcheck : 
		@make -C libft
		$(GCCO)
		$(GCC)

clean : 
		@make -C mlx clean
		@make -C libft clean
		@rm -f $(OBJS)
fclean : 
		@make -C . clean
		@make -C libft fclean
		@rm so_long
re : 
		@make -C . fclean 
		@make -C . all