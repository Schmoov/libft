#include <strings.h>
#include <string.h>
#include <limits.h>
#include <signal.h>
#include <criterion/criterion.h>
#include "libft.h"

Test(strncmp, basic_strings)
{
	char *s1 = "Wesh whes les amis";
	char *s2 = "Wesh wesh les amis";

	cr_assert_eq(strncmp(s1,s2,0), ft_strncmp(s1,s2,0));
	cr_assert_eq(strncmp(s2,s1,0), ft_strncmp(s2,s1,0));
	cr_assert_eq(strncmp(s1,s2,5), ft_strncmp(s1,s2,5));
	cr_assert_eq(strncmp(s2,s1,5), ft_strncmp(s2,s1,5));
	cr_assert_eq(strncmp(s1,s2,6), ft_strncmp(s1,s2,6));
	cr_assert_eq(strncmp(s2,s1,6), ft_strncmp(s2,s1,6));
	cr_assert_eq(strncmp(s1,s2,7), ft_strncmp(s1,s2,7));
	cr_assert_eq(strncmp(s2,s1,7), ft_strncmp(s2,s1,7));
	cr_assert_eq(strncmp(s1,s2,8), ft_strncmp(s1,s2,8));
	cr_assert_eq(strncmp(s2,s1,8), ft_strncmp(s2,s1,8));
	cr_assert_eq(strncmp(s1,s2,19), ft_strncmp(s1,s2,19));
	cr_assert_eq(strncmp(s2,s1,19), ft_strncmp(s2,s1,19));
	cr_assert_eq(strncmp(s1,s2,50), ft_strncmp(s1,s2,50));
	cr_assert_eq(strncmp(s2,s1,50), ft_strncmp(s2,s1,50));
}


Test(strncmp, thats_not_even_a_char)
{
	char *s1 = strdup("-->1<--");
	char *s2 = strdup("-->X<--");
	s2[3] = -1;
	size_t len = strlen(s1);

	cr_assert_eq(strncmp(s1,s2,4), ft_strncmp(s1,s2,4));
	cr_assert_eq(strncmp(s2,s1,4), ft_strncmp(s2,s1,4));
	cr_assert_eq(strncmp(s1,s2,len), ft_strncmp(s1,s2,len));
	cr_assert_eq(strncmp(s2,s1,len + 1), ft_strncmp(s2,s1,len + 1));
}

Test(strncmp, overlap)
{
	char *s = "hhhhh";
	char *p1 = s;
	char *p2 = (s+2);
	
	cr_assert_eq(strncmp(p1,p2,2), ft_strncmp(p1,p2,2));
	cr_assert_eq(strncmp(p1,p2,3), ft_strncmp(p1,p2,3));
	cr_assert_eq(strncmp(p1,p2,4), ft_strncmp(p1,p2,4));
}


Test(strncmp, bis_ass_string)
{
	char toolong[INT_MAX/1000];
	for (long i = 0; i<INT_MAX/1000; i++)
	{
		toolong[i] = 'X';
	}
	char loong[INT_MAX/1000];
	for (long i = 0; i<INT_MAX/1000; i++)
	{
		loong[i] = 'X';
	}
	toolong[42069] = 'D';
	toolong[INT_MAX/1000 - 1] = 0;
	loong[INT_MAX/1000 - 1] = 0;
	char *p1 = toolong;
	char *p2 = loong;
	cr_assert_eq(strncmp(p1,p2,INT_MAX/1000),ft_strncmp(p1,p2,INT_MAX/1000));
}

Test(strncmp, same_but_shorter)
{
	char *s1 = "abcdef";
	char *s2 = "abc";

	cr_assert_eq(strncmp(s1,s2,3), ft_strncmp(s1,s2,3));
	cr_assert_eq(strncmp(s1,s2,4), ft_strncmp(s1,s2,4));
	cr_assert_eq(strncmp(s1,s2,7), ft_strncmp(s1,s2,7));
}

Test(strncmp, empty_string)
{
	char *e = "";
	char *e2 = "";
	char *s = "non";

	cr_assert_eq(strncmp(e,e2,1), ft_strncmp(e,e2,1));
	cr_assert_eq(strncmp(e,e2,5), ft_strncmp(e,e2,5));
	cr_assert_eq(strncmp(e,s,0), ft_strncmp(e,s,0));
	cr_assert_eq(strncmp(e,s,3), ft_strncmp(e,s,3));
	cr_assert_eq(strncmp(e,s,4), ft_strncmp(e,s,4));
}

Test(strncmp, SEGSUCCESS, .signal = SIGSEGV)
{
	ft_strncmp(NULL, NULL, 1);
}
