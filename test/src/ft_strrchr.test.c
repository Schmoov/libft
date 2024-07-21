#include <strings.h>
#include <string.h>
#include <limits.h>
#include <signal.h>
#include <criterion/criterion.h>
#include "libft.h"

Test(strrchr, find_the_D)
{
	char a[6] = {'0','1','2','D','4',0};
	
	cr_assert_eq(strrchr(a,'D'), ft_strrchr(a,'D'));
}

Test(strrchr, find_the_last_D)
{
	char a[6] = {'0','D','2','D','D',0};

	cr_assert_eq(strrchr(a,'D'), ft_strrchr(a, 'D'));
}

Test(strrchr, looky_looky_no_touchy)
{
	char *s = "Tranquille lDa vie ?";
	cr_assert_eq(strrchr(s,'D'), ft_strrchr(s, 'D'));
	
}

Test(strrchr, no_D_in_here)
{
	char *s = "Big rock-climbing event at the mutinerie";
	
	cr_assert_null(ft_strrchr(s, 'D'));
	
}

Test(strrchr, standard_says_char_not_unsigned)
{
	char a[6] = {'0','1','2',-1,'4',0};
	cr_assert_eq(strrchr(a,255), ft_strrchr(a,255));
	cr_assert_eq(a + 3, ft_strrchr(a, 255));

	char b[6] = {'0','1','2',(char)255,'4',0};
	cr_assert_eq(strrchr(b,-1), ft_strrchr(b,-1));
	cr_assert_eq(b + 3, ft_strrchr(b, -1));

	char c[6] = {'0','1','2','x','4',0};
	cr_assert_eq(strrchr(c, 1024+'x'), ft_strrchr(c, 1024 +'x'));
	cr_assert_eq(c + 3, ft_strrchr(c, 1024+'x'));
}

Test(strrchr, bis_ass_string)
{
	char toolong[INT_MAX/1000];
	for (long i = 0; i<INT_MAX/1000; i++)
	{
		toolong[i] = 'X';
	}
	toolong[INT_MAX/1000 - 1] = 0;
	toolong[42069] = 'D';
	cr_assert_eq(toolong + 42069,ft_strrchr(toolong,'D'));
}

Test(strrchr, strlen_with_extra_steps)
{
	char *s = strdup("Tr0nquille lDa vie ?");

	cr_assert_eq(ft_strrchr(s, 0), s + strlen(s));
	s[8] = 0;
	cr_assert_eq(ft_strrchr(s, 0), s + 8);
	cr_assert_null(ft_strrchr(s, '?'));
	char *empty = "";
	cr_assert_eq(ft_strrchr(empty, 0), empty);
	cr_assert_null(ft_strrchr(empty, '0'));

}

Test(strrchr, INT_minmax)
{
	char a[100000];
	char c = 0;
	for (int i = 0; i < 100000; i++)
	{
		if (!c)
			c++;
		a[i] = c;
		c++;
	}
	a[99999]=0;
	cr_assert_eq(strrchr(a,INT_MAX), ft_strrchr(a,INT_MAX));
	cr_assert_eq(strrchr(a,INT_MIN), ft_strrchr(a,INT_MIN));
	cr_assert_eq(strrchr(a,0), ft_strrchr(a,0));
}

Test(strrchr, SEGSUCCESS, .signal = SIGSEGV)
{
	ft_strrchr(NULL, 0);
}
