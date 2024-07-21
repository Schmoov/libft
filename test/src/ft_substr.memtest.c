#include "libft.h"
#include <criterion/criterion.h>
#include <signal.h>
#include <string.h>
#include <stdio.h>

Test(substr, basics)
{
	char *s = "Y '0 mEme p4S AcCen*ts";

	char *test = ft_substr(s, 0, 3);
	cr_expect_str_eq(test, "Y '");
	free(test);

	test = ft_substr(s, 5, 7);
	cr_expect_str_eq(test, "mEme p4");
	free(test);

	test = ft_substr(s, 12, 23);
	cr_expect_str_eq(test, "S AcCen*ts");
	free(test);

	test = ft_substr(s, strlen(s)-1, 23);
	cr_expect_str_eq(test, "s");
	free(test);

	test = ft_substr(s, strlen(s), 23);
	cr_expect_str_eq(test, "");
	printf("%s\n",test);
	free(test);
}

Test(substr, empty_string)
{
	char *t = ft_substr("", 0, 1);
	cr_expect_str_eq(t, "");
	free(t);

	t = ft_substr("", 0, 100);
	cr_expect_str_eq(t, "");
	free(t);

	t = ft_substr("", 0, 0);
	cr_expect_str_eq(t, "");
	free(t);
}

Test(substr, zero_len)
{
	char *s = "qsgfsdgsdf";

	char *t = ft_substr(s, 0, 0);
	cr_expect_str_eq(t, "");
	free(t);

	t = ft_substr(s, 3, 0);
	cr_expect_str_eq(t, "");
	free(t);

	t = ft_substr(s, strlen(s)-1, 0);
	cr_expect_str_eq(t, "");
	free(t);

	t = ft_substr(s, strlen(s), 0);
	cr_expect_str_eq(t, "");
	free(t);
}

Test(substr, dup_not_cpy)
{
	char *s = strdup("unstable");
	char *t = ft_substr(s, 0, 125);
	s[0]= 0;
	free(s);
	cr_expect_str_eq(t,"unstable");
	free(t);
}
//Not sure why this ASAN doesnt catch the illegal read here
//Ive seen it pass AND display crash on build or teardown (:
/*
Test(substr, leak_on_empty_str)
{
	char *t = ft_substr("a", 3, 3);
	cr_expect_str_eq("", t);
	free(t);
}
*/
