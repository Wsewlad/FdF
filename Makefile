NAME	=	fdf
LIB		=	-I /usr/local/include -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit
MYLIB	=	-L. -lftprintf
SRC		=	main.c draw_map.c parse_map.c

all: $(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC) $(LIB) $(MYLIB)

clean:
	rm -f .*o

fclean: clean
	rm -f $(NAME)

re: fclean all