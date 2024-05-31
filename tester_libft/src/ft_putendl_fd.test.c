#include <criterion/criterion.h>
#include <unistd.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>
#include <fcntl.h>
#include "libft.h"

Test(putendl_fd, putendl_in_file)
{
	int fd_test = open("txt/tested_putendl.txt", O_WRONLY | O_CREAT, 444);
	ft_putendl_fd("JPP de faire de fr des tests wllh\n", fd_test);
	close(fd_test);
	fd_test = open("txt/tested_putendl.txt", O_RDONLY);

	int fd_expec = open("txt/expected_putstr.txt", O_RDONLY);
	
	char s_test[1000];
	char s_expec[1000];
	cr_expect_eq(read(fd_expec, s_expec, 1000), read(fd_test, s_test, 1000));
	cr_expect_arr_eq(s_test, s_expec, 35);
	remove("txt/tested_putendl.txt");
}
