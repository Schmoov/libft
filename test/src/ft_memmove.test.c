#include <strings.h>
#include <string.h>
#include <limits.h>
#include <signal.h>
#include <criterion/criterion.h>
#include "libft.h"

Test(memmove, basic_strings)
{
	char *src = "Wesh whes les amis";
	char d1[100];
	char d2[100];
	void *psrc = src;
	void *pd1 = d1;
	void *pd2 = d2;
	void *ret;

	memmove(pd1,psrc,0);
	ret = ft_memmove(pd2,psrc,0);
	cr_assert_arr_eq(d1, d2, 0);
	cr_assert_eq(pd2, ret);

	memmove(pd1,psrc,1);
	ret = ft_memmove(pd2,psrc,1);
	cr_assert_arr_eq(d1, d2, 1);
	cr_assert_eq(pd2, ret);

	memmove(pd1,psrc,10);
	ret = ft_memmove(pd2,psrc,10);
	cr_assert_arr_eq(d1, d2, 10);
	cr_assert_eq(pd2, ret);

	memmove(pd1,psrc,strlen(src + 1));
	ret = ft_memmove(pd2,psrc,strlen(src + 1));
	cr_assert_arr_eq(d1, d2, strlen(src + 1));
	cr_assert_eq(pd2, ret);
}

Test(memmove, int_array)
{
	int src[] = {-1,42,1,-16615};
	int d1[4];
	int d2[4];
	void *psrc = src;
	void *pd1 = d1;
	void *pd2 = d2;
	void *ret;

	memmove(pd1,psrc,1);
	ret = ft_memmove(pd2,psrc,1);
	cr_assert_arr_eq(d1, d2, 1);
	cr_assert_eq(pd2, ret);

	memmove(pd1,psrc,sizeof(int));
	ret = ft_memmove(pd2,psrc,sizeof(int));
	cr_assert_arr_eq(d1, d2, sizeof(int));
	cr_assert_eq(pd2, ret);

	memmove(pd1,psrc,4*sizeof(int));
	ret = ft_memmove(pd2,psrc,4*sizeof(int));
	cr_assert_arr_eq(d1, d2,4*sizeof(int));
	cr_assert_eq(pd2, ret);
}

Test(memmove, no_touchy, .signal = SIGSEGV)
{
	char *s1 = "read";
	char *s2 = "only";

	ft_memmove((void *)s1, (void *)s2, 4);
}


Test(memmove, bis_ass_string)
{
	char toolong[INT_MAX/1000];
	for (long i = 0; i<INT_MAX/1000; i++)
	{
		toolong[i] = 'X';
	}
	char loong[INT_MAX/1000];
	toolong[42069] = 'D';
	toolong[0] = 0;
	void *p1 = toolong;
	void *p2 = loong;
	cr_assert_arr_eq((char *)ft_memmove(p2,p1,INT_MAX/1000),toolong, INT_MAX/1000);
}

Test(memmove, its_a_trap)
{
	ft_memmove(NULL, "pas null", 0);
	ft_memmove("pas null",NULL, 0);
	ft_memmove(NULL, NULL, 0);
	cr_assert(1);
}

Test(memmove, SEGSUCCESS, .signal = SIGSEGV)
{
	ft_memmove(NULL, NULL, 1);
}

Test(memmove, lSEGSUCCESS, .signal = SIGSEGV)
{
	char * s = strdup("42");
	ft_memmove(s, NULL, 1);
}

Test(memmove, rSEGSUCCESS, .signal = SIGSEGV)
{
	char * s = strdup("42");
	ft_memmove(NULL, s, 1);
}

Test(memmove, loverlap)
{
	char *s1 = strdup("abcdefghijklmnopqrstuvwxyz");
	char *s2 = strdup("abcdefghijklmnopqrstuvwxyz");
	void *ps1 = s1;
	void *pd1 = s1 + 5;
	void *ps2 = s2;
	void *pd2 = s2 + 5;
	void *ret;

	memmove(pd1,ps1,20);
	ret = ft_memmove(pd2,ps2,20);
	cr_assert_arr_eq(s1,s2,21);
	cr_assert_eq(ret, (void*)(s2+5));
}

Test(memmove, roverlap)
{
	char *s1 = strdup("abcdefghijklmnopqrstuvwxyz");
	char *s2 = strdup("abcdefghijklmnopqrstuvwxyz");
	void *ps1 = s1 + 5;
	void *pd1 = s1;
	void *ps2 = s2 + 5;
	void *pd2 = s2;
	void *ret;

	memmove(pd1,ps1,20);
	ret = ft_memmove(pd2,ps2,20);
	cr_assert_arr_eq(s1,s2,21);
	cr_assert_eq(ret, (void*)(s2));
}
