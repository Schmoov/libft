#include "libft.h"
#include <criterion/criterion.h>
#include <signal.h>
#include <string.h>
#include <stdio.h>

Test(strtrim, basics)
{
	char *s = "   bonjour  bonjour\n";
	char *test = ft_strtrim(s, "\n ");
	cr_expect_str_eq(test, "bonjour  bonjour");
	free(test);

	s = "bonjour  bonjour";
	test = ft_strtrim(s, "\n ");
	cr_expect_str_eq(test, "bonjour  bonjour");
	free(test);

	s = "   bonjour  bonjour\n";
	test = ft_strtrim(s, "");
	cr_expect_str_eq(test, "   bonjour  bonjour\n");
	free(test);

	s = "";
	test = ft_strtrim(s, "\n ");
	cr_expect_str_eq(test, "");
	free(test);

	s = "   bonjour  bonjour\n";
	test = ft_strtrim(s, "                \n");
	cr_expect_str_eq(test, "bonjour  bonjour");
	free(test);
}

Test(strtrim, delete_everything)
{
	char *s = "   xxxx xxx xxx   x";
	char *test = ft_strtrim(s, "x ");
	cr_expect_str_eq(test, "");
	free(test);
}
