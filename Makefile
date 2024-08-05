CC      := gcc
OPT     := -O3
DEBUG   := -g0
CFLAGS  := -Wall -Wextra -Werror -Wunreachable-code $(OPT) $(DEBUG)
MLX_DIR  := ./lib/MLX42
MLX      := $(MLX_DIR)/build/libmlx42.a
LIBFT_DIR := ./lib/libft
LIBFT    := $(LIBFT_DIR)/libft.a
GNL_DIR  := ./lib/GNL
GNL      := $(GNL_DIR)/gnl.a
HEADERS  := -I ./inc -I $(MLX_DIR)/include/MLX42 -I $(LIBFT_DIR) -I $(GNL_DIR)
LIBS     := -L$(LIBFT_DIR) -lft -L$(GNL_DIR) $(GNL) -L$(MLX_DIR)/build -lmlx42 -ldl -lglfw -pthread -lm
SRC_DIR  := src
OBJ_DIR  := obj
SRC      := $(shell find $(SRC_DIR) -name '*.c')
OBJECTS  := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
NAME     := fdf

all: $(NAME)

$(MLX): $(MLX_DIR)
	cmake $(MLX_DIR) -B $(MLX_DIR)/build
	make -C $(MLX_DIR)/build -j4

$(MLX_DIR):
	git clone https://github.com/codam-coding-college/MLX42.git $@

$(NAME): $(MLX) $(OBJECTS)
	$(CC) $(OBJECTS) $(LIBS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) $(HEADERS) $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)
	rm -rf $(MLX_DIR)

re: fclean all

diff:
	$(info The status of the repository, and the volume of per-file changes:)
	@git status
	@git --no-pager diff --stat

.PHONY: all clean fclean re diff struct
