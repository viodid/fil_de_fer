NAME=fdf
BINARY=$(NAME)
CODEDIRS=src
INCDIR=./include/
INCLIB=./lib/libft.a ./lib/gnl/gnl.a ./lib/printf/printf.a

CC=gcc
OPT=-Og
# https://stackoverflow.com/questions/8025766/makefile-auto-dependency-generation
#DEPFLAGS=-MP -MD
CFLAGS=-Wall -Wextra -Werror -I$(INCDIR) $(OPT)

CFILES=$(shell find $(CODEDIRS) -name '*client.c')
OBJECTS = $(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(BINARY)

# https://stackoverflow.com/questions/3220277/what-do-the-makefile-symbols-and-mean
$(BINARY): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(INCLIB)

clean:
	rm -f $(OBJECTS) $(BONUS_OBJ)

fclean: clean
	rm -f $(BINARY)

re: fclean all

diff:
	$(info The status of the repository, and the volume of per-file changes:)
	@git status
	@git --no-pager diff --stat

struct:
	$(info Create folder and basic file structure.)
	mkdir -p src include
	git clone https://github.com/viodid/libft.git lib/
	git clone https://github.com/viodid/ft_printf.git lib/printf/
	git clone https://github.com/viodid/GNL.git lib/gnl/
	cd lib; make; make clean; rm -rf .git
	cd lib/ft_pintf; make; make clean; rm -rf .git
	cd lib/gnl; make; make clean; rm -rf .git