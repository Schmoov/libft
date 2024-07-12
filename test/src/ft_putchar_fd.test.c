#include <criterion/criterion.h>
#include <unistd.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>
#include <fcntl.h>
#include "libft.h"

Test(putchar_fd, Write_all_chars_in_a_file)
{
	int fd_test = open("test/txt/tested_putchar.txt", O_WRONLY | O_CREAT, 444);
	ft_putchar_fd(EOF, fd_test);
	for(int c = 0; c <= CHAR_MAX; c++)
	{
		ft_putchar_fd((char )c, fd_test);
	}
	close(fd_test);
	fd_test = open("test/txt/tested_putchar.txt", O_RDONLY);

	int fd_expec = open("test/txt/expected_putchar.txt", O_RDONLY);
	
	char s_test[129];
	char s_expec[129];
	cr_expect_eq(129, read(fd_test, s_test, 129));
	read(fd_expec, s_expec, 129);
	cr_expect_arr_eq(s_test, s_expec, 129);
	remove("test/txt/tested_putchar.txt");
}
