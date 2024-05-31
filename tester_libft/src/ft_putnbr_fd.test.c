#include <criterion/criterion.h>
#include <unistd.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>
#include <fcntl.h>
#include "libft.h"

Test(putnbr_fd, putnbr_in_a_file)
{
	int fd_test = open("txt/tested_putnbr.txt", O_WRONLY | O_CREAT, 444);
	
	ft_putnbr_fd(42,fd_test);
	ft_putnbr_fd(INT_MAX,fd_test);
	ft_putnbr_fd(0,fd_test);
	ft_putnbr_fd(INT_MIN,fd_test);
	close(fd_test);
	fd_test = open("txt/tested_putnbr.txt", O_RDONLY);

	int fd_expec = open("txt/expected_putnbr.txt", O_RDONLY);
	
	char s_test[129];
	char s_expec[129];
	cr_expect_eq(24, read(fd_test, s_test, 129));
	read(fd_expec, s_expec, 129);
	cr_expect_arr_eq(s_test, s_expec, 24);
	remove("txt/tested_putnbr.txt");
}
