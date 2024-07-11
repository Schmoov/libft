NAME := libft.a

CC := cc
CFLAGS := -Wall -Wextra -Werror 

SRC := $(wildcard src/**/*.c)
INCS := libft.h

OBJ_DIR := .bin/
OBJ := $(patsubst src/%.c, $(OBJ_DIR)%.o, $(SRC))

###############################################################################

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $?

$(OBJ_DIR)%.o: src/%.c
	@ mkdir -p $(OBJ_DIR)
	@ mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

print-%  : ; @echo $* = $($*)

.PHONY: all clean fclean re
