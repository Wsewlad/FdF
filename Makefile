NAME	=	fdf
LIB		=	-I /usr/local/include -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit
MYLIB	=	-L libft -lftprintf -I libft
SRC		=	main.c draw_map.c parse_map.c rotate.c shift.c del_copy_scale_center.c bunus.c \
			bonus2.c
OSRC	=	$(SRC:.c=.o)
FLAGS	=	-Wall -Werror -Wextra

.PHONY: all clean fclean re
all: $(NAME)

$(NAME): $(SRC)
	make -C libft/
	gcc $(FLAGS) -o $(NAME) $(SRC) $(LIB) $(MYLIB)
	@say fdf is compiled baby

clean:
	rm -f .*o
	make clean -C libft/

fclean: clean
	rm -f $(NAME)
	make fclean -C libft/

re: fclean all make re -C libft/