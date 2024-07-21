#include <criterion/criterion.h>
#include <stdio.h>
#include "libft.h"

void	itoa_tester(int n, char *base, bool is_signed, char *expected)
{
	char *str;

	str = itoa_base(n, base, is_signed);
	cr_expect_str_eq(str, expected);
	free(str);
}

void	ptrtoa_tester(void *p, char *base, char *expected)
{
	char *str;

	str = ptrtoa_base(p, base);
	cr_expect_str_eq(str, expected);
	free(str);
}

Test(itoa_base, base10)
{
	itoa_tester(0, BASE10, false, "0");
	itoa_tester(1, BASE10, false, "1");
	itoa_tester(42, BASE10, false, "42");
	itoa_tester(100, BASE10, false, "100");
	itoa_tester(INT_MAX, BASE10, false, "2147483647");
	itoa_tester(UINT_MAX, BASE10, false, "4294967295");

	itoa_tester(0, BASE10, true, "0");
	itoa_tester(1, BASE10, true, "1");
	itoa_tester(-1, BASE10, true, "1");
	itoa_tester(42, BASE10, true, "42");
	itoa_tester(-42, BASE10, true, "42");
	itoa_tester(100, BASE10, true, "100");
	itoa_tester(-100, BASE10, true, "100");
	itoa_tester(INT_MAX, BASE10, true, "2147483647");
	itoa_tester(INT_MIN, BASE10, true, "2147483648");
}

Test(itoa_base, base16)
{
	itoa_tester(0, UPBASE16, false, "0");
	itoa_tester(1, UPBASE16, false, "1");
	itoa_tester(42, UPBASE16, false, "2A");
	itoa_tester(256, UPBASE16, false, "100");
	itoa_tester(INT_MAX, UPBASE16, false, "7FFFFFFF");
	itoa_tester(UINT_MAX, UPBASE16, false, "FFFFFFFF");

	itoa_tester(0, LOBASE16, false, "0");
	itoa_tester(1, LOBASE16, false, "1");
	itoa_tester(42, LOBASE16, false, "2a");
	itoa_tester(256, LOBASE16, false, "100");
	itoa_tester(INT_MAX, LOBASE16, false, "7fffffff");
	itoa_tester(UINT_MAX, LOBASE16, false, "ffffffff");
}

Test(itoa_base, ptrtoa)
{
	ptrtoa_tester((void *)1, LOBASE16, "1");
	ptrtoa_tester((void *)42, LOBASE16, "2a");
	ptrtoa_tester((void *)256, LOBASE16, "100");
	ptrtoa_tester((void *)INT_MAX, LOBASE16, "7fffffff");
	ptrtoa_tester((void *)UINT_MAX, LOBASE16, "ffffffff");
	ptrtoa_tester((void *)UINTPTR_MAX, LOBASE16, "ffffffffffffffff");
}
