BINARY=gnl.a
LIB=ar rcs
CODEDIRS=./

CC=gcc
CFLAGS=-Wall -Wextra -Werror -fPIE

CFILES=$(shell find $(CODEDIRS) -name '*.c')
OBJECTS=$(CFILES:.c=.o)

all: $(BINARY)

$(BINARY): $(OBJECTS)
	$(LIB) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(BINARY)

re: fclean all

diff:
	$(info The status of the repository, and the volume of per-file changes:)
	@git status
	@git --no-pager diff --stat

.PHONY: all clean fclean re diff
