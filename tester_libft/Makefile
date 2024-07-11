CC := cc
CFLAGS := -Wall -Wextra -Werror

SRC_DIR := src/
SRCS := $(wildcard $(SRC_DIR)*.c)

BIN_DIR := .bin/
OBJS := $(patsubst $(SRC_DIR)%.c, $(BIN_DIR)%.o, $(SRCS))

TST_DIR := tests/
TSTS := $(patsubst $(BIN_DIR)%.o, $(TST_DIR)%, $(OBJS))

CRIT := -lcriterion

LIBFT := libft.h libft.a

ASAN := -fsanitize=address
LOG_DIR := .logs/
ASAN_ENV := ASAN_OPTIONS=log_path=$(LOG_DIR):abort_on_error=1:allocator_may_return_null=1

###############################################################################

all: $(LIBFT) test

$(LIBFT):
	make -C ../ all
	make -C ../ bonus
	cp ../libft.a ./
	cp ../libft.h ./

test: $(OBJS) $(TSTS)

$(BIN_DIR)%.test.o: $(SRC_DIR)%.test.c
	@ mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -I ./ -c $< -o $@

$(BIN_DIR)%.memtest.o: $(SRC_DIR)%.memtest.c
	@ mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $(ASAN) -I ./ -c $< -o $@

$(TST_DIR)%.test: $(BIN_DIR)%.test.o
	@ mkdir -p $(TST_DIR)
	@ mkdir -p $(LOG_DIR)
	$(CC) $(CFLAGS) $< libft.a $(CRIT) -lbsd -o $@
	 ./$@

$(TST_DIR)%.memtest: $(BIN_DIR)%.memtest.o
	$(CC) $(CFLAGS) $(ASAN) $< libft.a $(CRIT) -lbsd -o $@
	$(ASAN_ENV)  ./$@

print-%  : ; @echo $* = $($*)

clean:
	rm -rf $(BIN_DIR)
	rm -rf $(LOG_DIR)

fclean: clean
	rm -f $(LIBFT)
	rm -rf $(TST_DIR)

re: fclean all

.PHONY: all test clean fclean re
