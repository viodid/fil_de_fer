NAME=fdf
CODEDIRS=src
INCDIR=./include/ mlx_linux
INCLIB=./lib/libft/libft.a ./lib/gnl/gnl.a ./lib/printf/printf.a
INCPATH=/usr/lib
LINKLIB=mlx_Linux Xext X11 m z

CC=gcc
OPT=-g3
# https://stackoverflow.com/questions/8025766/makefile-auto-dependency-generation
#DEPFLAGS=-MP -MD
# https://www.rapidtables.com/code/linux/gcc/gcc-l.html
CFLAGS= -I$(INCDIR) -L$(INCPATH) -l$(LINKLIB) $(OPT)

CFILES=$(shell find $(CODEDIRS) -name '*.c')
OBJECTS=$(CFILES:.c=.o)

all: $(NAME)

$(NAME):
	gcc src/main.c -g3 MLX42/build/libmlx42.a -Iinclude -ldl -lglfw -pthread -lm -o fdf

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
	info Create folder and basic file structure.)
	mkdir -p src include
	git clone https://github.com/viodid/libft.git lib/libft
	git clone https://github.com/viodid/ft_printf.git lib/printf
	git clone https://github.com/viodid/GNL.git lib/gnl
	cd lib/libft && make && make clean && rm -rf .git
	cd lib/printf && make && make clean && rm -rf .git
	cd lib/gnl && make && make clean && rm -rf .git

.PHONY: fdf all clean fclean re diff struc