NAME = miniRT

#lib directory includes the libft files. The obj folder will consists the .o files
LIB_DIR = lib
SRC_DIR = src
OBJ_DIR = obj

CC = cc
CFLAGS = -Wall -Werror -Wextra

LIB = $(LIB_DIR)/lib.a


SRCS :=	main.c

SRCS := $(addprefix $(SRC_DIR)/, $(SRCS))
OBJS :=$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

all: $(NAME)
	@echo "$(NAME) built succesfully.\n"

$(NAME): $(LIB) $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB)

$(LIB):
	@$(MAKE) -C $(LIB_DIR) --silent

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJS)
	@$(MAKE) -C $(LIB_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIB_DIR) fclean

re: fclean all

.PHONY: all clean fclean re