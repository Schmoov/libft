#include <criterion/criterion.h>
#include <ctype.h>
#include "libft.h"

char f1(unsigned int i, char c)
{
	(void) i;
	return (toupper(c));
}

char f2(unsigned int i, char c)
{
	if (i%2)
		return(toupper(c));
	else
		return(tolower(c));
}

char f3(unsigned int i, char c)
{
	char *button = NULL;
	return (i + c + button[420]);
}

Test(strmapi, caps_lock)
{
	char *s = "Tu m'enTends la ?";
	char *t = ft_strmapi(s, f1);
	cr_expect_str_eq(t, "TU M'ENTENDS LA ?");
	free(t);
}

Test(strmapi, bOb)
{
	char *s = "Tu m'enTends la ?";

	char *t = ft_strmapi(s, f2);
	cr_expect_str_eq(t, "tU M'EnTeNdS La ?");
	free(t);
}

Test(strmapi, empty)
{
	char *s = "";
	
	char *t = ft_strmapi(s, f2);
	cr_expect_str_eq(t, "");
	free(t);
	t = ft_strmapi(s, f3);
	cr_expect_str_eq(t, "");
	free(t);
}
