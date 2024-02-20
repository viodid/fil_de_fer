NAME=fdf
CODEDIRS=src
INCDIR=./include/
INCLIB=./lib/libft/libft.a ./lib/gnl/gnl.a ./lib/printf/printf.a

CC=gcc
OPT=-Og
# https://stackoverflow.com/questions/8025766/makefile-auto-dependency-generation
#DEPFLAGS=-MP -MD
CFLAGS=-Wall -Wextra -Werror -I$(INCDIR) $(OPT)

CFILES=$(shell find $(CODEDIRS) -name '*.c')
OBJECTS=$(CFILES:.c=.o)

all: $(NAME)

# https://stackoverflow.com/questions/3220277/what-do-the-makefile-symbols-and-mean
$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(INCLIB)

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
	$(info Create folder and basic file structure.)
	mkdir -p src include
	git clone https://github.com/viodid/libft.git lib/libft
	git clone https://github.com/viodid/ft_printf.git lib/printf
	git clone https://github.com/viodid/GNL.git lib/gnl
	cd lib/libft && make && make clean && rm -rf .git
	cd lib/printf && make && make clean && rm -rf .git
	cd lib/gnl && make && make clean && rm -rf .git

.PHONY: fdf all clean fclean re diff struc