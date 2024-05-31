#include <strings.h>
#include <string.h>
#include <limits.h>
#include <signal.h>
#include <criterion/criterion.h>
#include "libft.h"

Test(strlen, string_as_arr)
{
	char a[6] = {'0','1','2','D','4',0};
	
	cr_assert_eq(strlen(a), ft_strlen(a));
}

Test(strlen, looky_looky_no_touchy)
{
	char *s = "Tranquille lDa vie ?";
	cr_assert_eq(strlen(s), ft_strlen(s));
	
}

Test(strlen, empty_string)
{
	char *s = "";
	
	cr_assert_eq(0,ft_strlen(s));
	
}


Test(strlen, bis_ass_string)
{
	char toolong[INT_MAX/500];
	for (long i = 0; i<INT_MAX/500; i++)
	{
		toolong[i] = 'X';
	}
	toolong[INT_MAX/500 - 1] = 0;
	toolong[42069] = 'D';
	cr_assert_eq(strlen(toolong),ft_strlen(toolong));
}

Test(strlen, SEGSUCCESS, .signal = SIGSEGV)
{
	ft_strlen(NULL);
}
