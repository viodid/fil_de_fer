NAME = libft.a
LIB = ar rcs

CFILES=$(shell find . -name '*.c')
OBJ = $(CFILES:.c=.o)

$(NAME): $(OBJ)
	$(LIB) $(NAME) $(OBJ)

all: $(NAME)

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
