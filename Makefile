NAME := libft.a

CC := gcc
CFLAGS := -Wall -Wextra -Werror 

SRCS = ft_atoi.c ft_isdigit.c ft_memmove.c ft_split.c ft_strlcpy.c ft_strtrim.c ft_bzero.c ft_isprint.c ft_memset.c ft_strchr.c ft_strlen.c ft_substr.c ft_calloc.c ft_itoa.c ft_putchar_fd.c ft_strdup.c ft_strmapi.c ft_tolower.c ft_isalnum.c ft_memchr.c ft_putendl_fd.c ft_striteri.c ft_strncmp.c ft_toupper.c ft_isalpha.c ft_memcmp.c ft_putnbr_fd.c ft_strjoin.c ft_strnstr.c ft_isascii.c ft_memcpy.c ft_putstr_fd.c ft_strlcat.c ft_strrchr.c is_in.c
SRCS_BONUS := ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c

INCS := libft.h

OBJ_DIR := .bin/
OBJS := $(patsubst %.c, $(OBJ_DIR)%.o, $(SRCS))
OBJS_BONUS := $(patsubst %.c, $(OBJ_DIR)%.o, $(SRCS_BONUS))
BONUS_FLAG := .has_bonus

###############################################################################

all: $(NAME)

$(NAME): $(OBJS) $(INCS)
	ar rcs $@ $?

bonus: $(BONUS_FLAG)

$(BONUS_FLAG) : $(OBJS) $(OBJS_BONUS) $(INCS)
	ar rcs $(NAME) $?
	touch $(BONUS_FLAG)

$(OBJ_DIR)%.o: %.c
	@ mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

print-%  : ; @echo $* = $($*)

clean:
	rm -rf $(OBJ_DIR)
	rm -f $(BONUS_FLAG)

fclean: clean
	rm -f $(NAME)

re: fclean all

rebonus : fclean bonus

rfclean : fclean
	make -C tester_libft fclean

.PHONY: all clean fclean re bonus rebonus rfclean
