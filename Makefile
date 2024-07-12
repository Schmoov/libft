NAME := libft.a

CC := cc
CFLAGS := -Wall -Wextra -Werror 

SRC_DIR := src/
SRC := $(wildcard $(SRC_DIR)**/*.c)

TEST_SRC_DIR := test/src/
TEST_SRC := $(wildcard $(TEST_SRC_DIR)*.c)

OBJ_DIR := .obj/
OBJ := $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))
TEST_OBJ := $(patsubst $(TEST_SRC_DIR)%.c, $(OBJ_DIR)%.o, $(TEST_SRC))

TEST_BIN_DIR := test/bin/
TEST_BIN := $(patsubst $(OBJ_DIR)%.o, $(TEST_BIN_DIR)%, $(TEST_OBJ))

CRIT := -lcriterion
ASAN := -fsanitize=address
LOG_DIR := .logs/
ASAN_ENV := ASAN_OPTIONS=log_path=$(LOG_DIR):abort_on_error=1:allocator_may_return_null=1
###############################################################################

all: $(NAME)

test: $(NAME) $(TEST_OBJ) $(TEST_BIN)

$(NAME): $(OBJ)
	ar rcs $@ $?

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@ mkdir -p $(OBJ_DIR)
	@ mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)%.test.o: $(TEST_SRC_DIR)%.test.c
	@ mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)%.memtest.o: $(TEST_SRC_DIR)%.memtest.c
	@ mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(ASAN) -c $< -o $@

$(TEST_BIN_DIR)%.test: $(OBJ_DIR)%.test.o
	@ mkdir -p $(TEST_BIN_DIR)
	@ mkdir -p $(LOG_DIR)
	$(CC) $(CFLAGS) $< libft.a $(CRIT) -lbsd -o $@
	 ./$@

$(TEST_BIN_DIR)%.memtest: $(OBJ_DIR)%.memtest.o
	@ mkdir -p $(TEST_BIN_DIR)
	@ mkdir -p $(LOG_DIR)
	$(CC) $(CFLAGS) $(ASAN) $< libft.a $(CRIT) -lbsd -o $@
	$(ASAN_ENV) ./$@

clean:
	rm -rf $(OBJ_DIR)

tclean:
	rm -f $(TEST_OBJ)
	rm -rf $(LOG_DIR)
	rm -rf $(TEST_BIN_DIR)

fclean: clean tclean
	rm -f $(NAME)

re: fclean tclean all

tre: tclean test

print-%  : ; @echo $* = $($*)

.PHONY: all test clean tclean fclean re tre
