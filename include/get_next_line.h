#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <fcntl.h>
# include "include/libft.h"

# ifndef FD_MAX
#  define FD_MAX 16
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2048
# endif

char	*get_next_line(int fd);
#endif
