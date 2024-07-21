#include <strings.h>
#include <string.h>
#include <limits.h>
#include <signal.h>
#include <criterion/criterion.h>
#include "libft.h"

bool strict_sign(int a, int b)
{
	return ((a>0 && b>0) || (a<0 && b<0) || (!a && !b));
}

Test(memcmp, basic_strings)
{
	char *s1 = "Wesh whes les amis";
	char *s2 = "Wesh wesh les amis";
	void *p1 = s1;
	void *p2 = s2;

	cr_expect(strict_sign(memcmp(p1,p2,0), ft_memcmp(p1,p2,0)));
	cr_expect(strict_sign(memcmp(p1,p2,5), ft_memcmp(p1,p2,5)));
	cr_expect(strict_sign(memcmp(p1,p2,6), ft_memcmp(p1,p2,6)));
	cr_expect(strict_sign(memcmp(p1,p2,7), ft_memcmp(p1,p2,7)));
	cr_expect(strict_sign(memcmp(p1,p2,8), ft_memcmp(p1,p2,8)));
	cr_expect(strict_sign(memcmp(p1,p2,12), ft_memcmp(p1,p2,12)));
	cr_expect(strict_sign(memcmp(p2,p1,12), ft_memcmp(p2,p1,12)));
}

Test(memcmp, int_array)
{
	int a1[] = {-1,42,1,-16615};
	int a2[] = {-1,42,0,-16615};
	void *p1 = a1;
	void *p2 = a2;

	cr_expect(strict_sign(memcmp(p1,p2,0), ft_memcmp(p1,p2,0)));
	cr_expect(strict_sign(memcmp(p1,p2,2*sizeof(int)+1), ft_memcmp(p1,p2,2*sizeof(int)+1)));
	cr_expect(strict_sign(memcmp(p1,p2,3*sizeof(int)), ft_memcmp(p1,p2,3*sizeof(int))));
	cr_expect(strict_sign(memcmp(p2,p1,3*sizeof(int)), ft_memcmp(p2,p1,3*sizeof(int))));
}

Test(memcmp, thats_not_even_a_char)
{
	char *s1 = strdup("Wesh whes les amis");
	char *s2 = strdup("Wesh wesh les amis");
	s2[3] = -1;
	void *p1 = s1;
	void *p2 = s2;

	cr_expect(strict_sign(memcmp(p1,p2,3), ft_memcmp(p1,p2,3)));
	cr_expect(strict_sign(memcmp(p1,p2,4), ft_memcmp(p1,p2,4)));
	cr_expect(strict_sign(memcmp(p2,p1,4), ft_memcmp(p2,p1,4)));
	cr_expect(strict_sign(memcmp(p1,p2,4), ft_memcmp(p1,p2,5)));
	cr_expect(strict_sign(memcmp(p2,p1,5), ft_memcmp(p2,p1,5)));
}

Test(memcmp, overlap)
{
	char *s = "hhhhhhh";
	void *p1 = s;
	void *p2 = (s+3);
	
	cr_expect(strict_sign(memcmp(p1,p2,3), ft_memcmp(p1,p2,3)));
	cr_expect(strict_sign(memcmp(p1,p2,4), ft_memcmp(p1,p2,4)));
}


Test(memcmp, bis_ass_string)
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
	void *p1 = toolong;
	void *p2 = loong;
	cr_expect(strict_sign(memcmp(p1,p2,INT_MAX/1000),ft_memcmp(p1,p2,INT_MAX/1000)));
}

Test(memcmp, its_a_trap)
{
	ft_memcmp(NULL, NULL, 0);
	cr_expect(1);
}

Test(memcmp, SEGSUCCESS, .signal = SIGSEGV)
{
	ft_memcmp(NULL, NULL, 1);
}
