#include <criterion/criterion.h>
#include "libft.h"

Test(strjoin, basics)
{
	char *s1 = "0123456789";
	char *s2 = "abcdef";
	char *test;

	test = ft_strjoin(s1,s2);
	cr_expect_str_eq(test, "0123456789abcdef");
	free(test);

	test = ft_strjoin("",s2);
	cr_expect_str_eq(test, s2);
	free(test);

	test = ft_strjoin(s1,"");
	cr_expect_str_eq(test, s1);
	free(test);

	test = ft_strjoin("","");
	cr_expect_str_eq(test, "");
	free(test);

	test = ft_strjoin(s1,s1+7);
	cr_expect_str_eq(test, "0123456789789");
	free(test);
}
