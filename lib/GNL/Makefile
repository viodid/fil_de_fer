BINARY=gnl.a
LIB=ar rcs
CODEDIRS=./


CFILES=$(shell find $(CODEDIRS) -name '*.c')
OBJECTS = $(CFILES:.c=.o)

all: $(BINARY)

# https://stackoverflow.com/questions/3220277/what-do-the-makefile-symbols-and-mean
$(BINARY): $(OBJECTS)
	$(LIB) -o $@ $^


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
