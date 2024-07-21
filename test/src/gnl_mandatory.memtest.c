#include <criterion/criterion.h>
#include <stdio.h>
#include <fcntl.h>
#include "libft.h"

Test(gnl_mandatory, single_line_text)
{
	int fd = open("test/txt/bonjour.txt", O_RDONLY);
	char *line;

	line = get_next_line(fd);
	cr_expect_str_eq(line, "bonjour\n");
	free(line);

	line = get_next_line(fd);
	cr_expect_null(line);

	line = get_next_line(fd);
	cr_expect_null(line);

	close(fd);
}

Test(gnl_mandatory, normal_text)
{
	int fd = open("test/txt/manifesto.txt", O_RDONLY);
	char *line;

	line = get_next_line(fd);
	cr_expect_str_eq(line, "MANIFESTO OF THE COMMUNIST PARTY\n");
	free(line);

	line = get_next_line(fd);
	cr_expect_str_eq(line, "\n");
	free(line);

	line = get_next_line(fd);
	cr_expect_str_eq(line, "[From the English edition of 1888, edited by Friedrich Engels]\n");
	free(line);

	line = get_next_line(fd);
	cr_expect_str_eq(line, "\n");
	free(line);

	line = get_next_line(fd);
	cr_expect_str_eq(line, "\n");
	free(line);

	line = get_next_line(fd);
	cr_expect_str_eq(line, "A spectre is haunting Europe--the spectre of Communism.\n");
	free(line);

	for (int i = 6; i < 1485; i++)
		free(get_next_line(fd));

	line = get_next_line(fd);
	cr_expect_str_eq(line, "\n");
	free(line);

	line = get_next_line(fd);
	cr_expect_str_eq(line, "           WORKING MEN OF ALL COUNTRIES, UNITE!\n");
	free(line);

	line = get_next_line(fd);
	cr_expect_null(line);
	line = get_next_line(fd);
	cr_expect_null(line);
	line = get_next_line(fd);
	cr_expect_null(line);
	line = get_next_line(fd);
	cr_expect_null(line);

	line = get_next_line(fd);
	cr_expect_null(line);
	line = get_next_line(fd);
	cr_expect_null(line);
	line = get_next_line(fd);
	cr_expect_null(line);
	line = get_next_line(fd);
	cr_expect_null(line);

	line = get_next_line(fd);
	cr_expect_null(line);
	line = get_next_line(fd);
	cr_expect_null(line);
	line = get_next_line(fd);
	cr_expect_null(line);
	line = get_next_line(fd);
	cr_expect_null(line);

	line = get_next_line(fd);
	cr_expect_null(line);
	line = get_next_line(fd);
	cr_expect_null(line);
	line = get_next_line(fd);
	cr_expect_null(line);
	line = get_next_line(fd);
	cr_expect_null(line);

	close(fd);
}
