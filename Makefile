NAME=fdf
CODEDIRS=src
INCDIR=./include/
INCLIB=./lib/libft/libft.a ./lib/GNL/gnl.a ./lib/MLX42/build/libmlx42.a

CC=gcc
# https://www.rapidtables.com/code/linux/gcc/gcc-o.html#optimization
OPT=-O3
# https://www.rapidtables.com/code/linux/gcc/gcc-g.html
DEBUG=-g0
WARNINGS=-Wextra -Wall -Werror -Wunreachable-code
MLX_FLAGS=-ldl -lglfw -pthread -lm
CFLAGS=$(OPT) $(DEBUG) $(WARNINGS) -I$(INCDIR)
LFLAGS=$(INCLIB) $(MLX_FLAGS)

CFILES=$(shell find $(CODEDIRS) -name '*.c')
OBJECTS=$(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) $(LFLAGS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

diff:
	$(info The status of the repository, and the volume of per-file changes:)
	@git status
	@git --no-pager diff --stat

struct:
	info Create folder and basic file structure.
	mkdir -p src include
	git clone https://github.com/viodid/libft.git lib/libft
	git clone https://github.com/viodid/GNL.git lib/gnl
	cd lib/libft && make && make clean && rm -rf .git
	cd lib/printf && make && make clean && rm -rf .git
	cd lib/gnl && make && make clean && rm -rf .git

.PHONY: fdf all clean fclean re diff struc