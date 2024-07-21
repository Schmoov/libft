#include <criterion/criterion.h>
#include <ctype.h>
#include "libft.h"

void f1(unsigned int i, char *s)
{
	*s = toupper(*s);
	(void) i;
}

void f2(unsigned int i, char *s)
{
	if (i%2)
		*s = toupper(*s);
	else
		*s = tolower(*s);
}

void f3(unsigned int i, char *s)
{
	s[-i-42]=0;
}

Test(striteri, caps_lock)
{
	char *s = strdup("Tu m'enTends la ?");

	ft_striteri(s, f1);
	cr_expect_str_eq(s, "TU M'ENTENDS LA ?");
	free(s);
}

Test(striteri, bOb)
{
	char *s = strdup("Tu m'enTends la ?");

	ft_striteri(s, f2);
	cr_expect_str_eq(s, "tU M'EnTeNdS La ?");
	free(s);
}

Test(striteri, empty)
{
	char *s = "";

	ft_striteri(s, f2);
	cr_expect_str_eq(s, "");
	ft_striteri(s, f3);
	cr_expect_str_eq(s, "");
}
