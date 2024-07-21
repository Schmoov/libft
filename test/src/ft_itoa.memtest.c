#include "libft.h"
#include <criterion/criterion.h>
#include <signal.h>

Test(ft_itoa, basics)
{
	char *s = ft_itoa(42);
	cr_assert_str_eq("42",s);
	free(s);

	s = ft_itoa(1);
	cr_assert_str_eq("1",s);
	free(s);

	s = ft_itoa(-1);
	cr_assert_str_eq("-1",s);
	free(s);

	s = ft_itoa(0);
	cr_assert_str_eq("0",s);
	free(s);

	s = ft_itoa(2147483647);
	cr_assert_str_eq("2147483647",s);
	free(s);

	s = ft_itoa(-2147483648);
	cr_assert_str_eq("-2147483648",s);
	free(s);

	s = ft_itoa(-1500008);
	cr_assert_str_eq("-1500008",s);
	free(s);

	s = ft_itoa(90000);
	cr_assert_str_eq("90000",s);
	free(s);
}

Test(itoa, memtest42, .signal = SIGABRT)
{
    char *s = ft_itoa(42);
    char c = s[3];
    (void) c;
    free(s);
}

Test(itoa, memtest_neg, .signal = SIGABRT)
{
    char *s = ft_itoa(-45042);
    char c = s[7];
    (void) c;
    free(s);
}

Test(itoa, memtest0, .signal = SIGABRT)
{
    char *s = ft_itoa(-0);
    char c = s[2];
    (void) c;
    free(s);
}

