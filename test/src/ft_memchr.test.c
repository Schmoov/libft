#include <strings.h>
#include <string.h>
#include <limits.h>
#include <signal.h>
#include <criterion/criterion.h>
#include "libft.h"

Test(memchr, find_the_D)
{
	char a1[6] = {0,'1','2','D','4','5'};
	void *p = a1;
	cr_assert_eq(memchr(p,'D',6), ft_memchr(p, 'D', 6));
}

Test(memchr, find_the_first_D)
{
	char a1[6] = {0,'D','2','D','4','D'};
	void *p = a1;
	cr_assert_eq(memchr(p,'D',6), ft_memchr(p, 'D', 6));
}

Test(memchr, looky_looky_no_touchy)
{
	char *s = "Tranquille lDa vie ?";
	void *p = s;
	size_t size = strlen(s)+1;
	cr_assert_eq(memchr(p,'D',size), ft_memchr(p, 'D', size));
	
}

Test(memchr, no_D_in_here)
{
	char *s = "Big rock-climbing event at the mutinerie";
	void *p = s;
	size_t size = strlen(s)+1;
	cr_assert_eq(memchr(p,'D',size), ft_memchr(p, 'D', size));
	
}

Test(memchr, thats_not_even_a_char)
{
	char a1[6] = {0,'1','2',-1,'4','5'};
	void *p = a1;
	cr_assert_eq(memchr(p,-1,6), ft_memchr(p, -1, 6));
	cr_assert_eq(a1 + 3, (char *)ft_memchr(p, -1, 6));

}

Test(memchr, bis_ass_string)
{
	char toolong[INT_MAX/1000];
	for (long i = 0; i<INT_MAX/1000; i++)
	{
		toolong[i] = 'X';
	}
	toolong[42069] = 'D';
	void *p = toolong;
	cr_assert_eq(memchr(p,'D',INT_MAX/1000),ft_memchr(p,'D',INT_MAX/1000));
}

Test(memchr, strlen_with_extra_steps)
{
	char *s = strdup("Tr0nquille lDa vie ?");
	size_t size = strlen(s)+1;
	void *p = s;
	cr_assert_eq(ft_memchr(p, 0,size), s + strlen(s));
	s[8] = 0;
	cr_assert_eq(ft_memchr(p, 0,size), s + strlen(s));
	char *empty = "";
	cr_assert_eq(ft_memchr((void *)empty, 0, 1), (void *)empty);

}

Test(memchr, its_a_trap)
{
	ft_memchr(NULL, 'p', 0);
	cr_assert(1);
}

Test(memchr, SEGSUCCESS, .signal = SIGSEGV)
{
	ft_memchr(NULL, 'k', 1);
}
