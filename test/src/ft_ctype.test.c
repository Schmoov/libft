#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <criterion/criterion.h>
#include "libft.h"

Test(ctype, isalnum)
{
	for (int i = 0; i <= UCHAR_MAX; i++)
		cr_assert(!!ft_isalnum(i) == !!isalnum(i));
	cr_assert(ft_isalnum(EOF) == 0);
}

Test(ctype, isalpha)
{
	for (int i = 0; i <= UCHAR_MAX; i++)
		cr_assert(!!ft_isalpha(i) == !!isalpha(i));
	cr_assert(ft_isalpha(EOF) == 0);
}

Test(ctype, isascii)
{
	for (int i = 0; i <= UCHAR_MAX; i++)
		cr_assert(!!ft_isascii(i) == !!isascii(i));
	cr_assert(ft_isascii(EOF) == 0);
}

Test(ctype, isdigit)
{
	for (int i = 0; i <= UCHAR_MAX; i++)
		cr_assert(!!ft_isdigit(i) == !!isdigit(i));
	cr_assert(ft_isdigit(EOF) == 0);
}

Test(ctype, isprint)
{
	for (int i = 0; i <= UCHAR_MAX; i++)
		cr_assert(!!ft_isprint(i) == !!isprint(i));
	cr_assert(ft_isprint(EOF) == 0);
}

Test(ctype, tolower)
{
	for (int i = 0; i <= UCHAR_MAX; i++)
		cr_assert(ft_tolower(i) == tolower(i));
	cr_assert(ft_tolower(EOF) == EOF);
}

Test(ctype, toupper)
{
	for (int i = 0; i <= UCHAR_MAX; i++)
		cr_assert(ft_toupper(i) == toupper(i));
	cr_assert(ft_toupper(EOF) == EOF);
}
