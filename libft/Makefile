NAME = libft.a

SRC = $(addsuffix .c, ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint \
ft_strlen ft_memset ft_bzero ft_memcpy ft_memmove ft_toupper ft_tolower \
ft_memchr ft_memcmp ft_strlcpy ft_strlcat ft_strchr ft_strrchr ft_strncmp \
ft_strnstr ft_atoi ft_calloc ft_strdup ft_substr ft_putchar_fd ft_putstr_fd \
ft_putendl_fd ft_putnbr_fd ft_striteri ft_strmapi ft_strjoin ft_itoa \
ft_strtrim ft_split)

OBJ_DIR = obj

OBJ := $(SRC:%.c=$(OBJ_DIR)/%.o)
HEADER = libft.h

CC = cc
CCFLAGS = -Wall -Werror -Wextra
CPPFLAGS = -I.
ARFILE = ar rcs $(NAME)

all: $(NAME) $(OBJ)

$(NAME): $(OBJ)
	$(ARFILE) $(OBJ)

$(OBJ_DIR)/%.o: %.c $(HEADER) | $(OBJ_DIR)
	$(CC) $(CPPFLAGS) $(CCFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re