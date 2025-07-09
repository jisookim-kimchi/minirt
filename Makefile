NAME = miniRT

#lib directory includes the libft files. The obj folder will consists the .o files
LIBFT_DIR = libft
OBJ_DIR = obj

#Download and build MLX42
MLX_DIR = MLX42
MLX_LIB = $(MLX_DIR)/build/libmlx42.a
LIBMLX = ./MLX42
LIBSM :=$(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

CC = cc
CFLAGS = -Wall -Werror -Wextra -Wunreachable-code
HEADER = -I $(LIBMLX)/include

LIBFT = $(LIBFT_DIR)/libft.a

SRCS :=	render/window.c

OBJS := $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))


all: libmlx $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(LIBSM) -o $(NAME) $(OBJS) $(LIBFT)
	@echo "$(NAME) built succesfully.\n"

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) --silent

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@


#Build the MLX42
libmlx:
	@if [ ! -d "$(MLX_DIR)" ]; then \
		git submodule add --force https://github.com/codam-coding-college/MLX42.git $(MLX_DIR); \
	fi
	git submodule update --init --recursive > /dev/null 2>&1
	cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4 > /dev/null 2>&1
	@echo "$(MLX_DIR) downloaded succesfully.\n"

#Delete MLX42
cleanmlx:
	@if [ -d "$(MLX_DIR)" ]; then \
		git submodule deinit -f -q $(MLX_DIR); \
		git	rm -f -q $(MLX_DIR); \
		rm -rf .git/modules/$(MLX_DIR) > /dev/null 2>&1; \
		rm -rf $(MLX_DIR) > /dev/null 2>&1; \
		echo "$(MLX_DIR) deleted."; \
	else \
		echo "MLX42 is already deleted."; \
	fi

clean:
	@rm -rf $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean cleanmlx
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re