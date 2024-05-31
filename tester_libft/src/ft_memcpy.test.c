#include <strings.h>
#include <string.h>
#include <limits.h>
#include <signal.h>
#include <criterion/criterion.h>
#include "libft.h"

Test(memcpy, basic_strings)
{
	char *src = "Wesh whes les amis";
	char d1[100];
	char d2[100];
	void *psrc = src;
	void *pd1 = d1;
	void *pd2 = d2;
	void *ret;

	memcpy(pd1,psrc,0);
	ret = ft_memcpy(pd2,psrc,0);
	cr_assert_arr_eq(d1, d2, 0);
	cr_assert_eq(pd2, ret);

	memcpy(pd1,psrc,1);
	ret = ft_memcpy(pd2,psrc,1);
	cr_assert_arr_eq(d1, d2, 1);
	cr_assert_eq(pd2, ret);

	memcpy(pd1,psrc,10);
	ret = ft_memcpy(pd2,psrc,10);
	cr_assert_arr_eq(d1, d2, 10);
	cr_assert_eq(pd2, ret);

	memcpy(pd1,psrc,strlen(src + 1));
	ret = ft_memcpy(pd2,psrc,strlen(src + 1));
	cr_assert_arr_eq(d1, d2, strlen(src + 1));
	cr_assert_eq(pd2, ret);
}

Test(memcpy, int_array)
{
	int src[] = {-1,42,1,-16615};
	int d1[4];
	int d2[4];
	void *psrc = src;
	void *pd1 = d1;
	void *pd2 = d2;
	void *ret;

	memcpy(pd1,psrc,1);
	ret = ft_memcpy(pd2,psrc,1);
	cr_assert_arr_eq(d1, d2, 1);
	cr_assert_eq(pd2, ret);

	memcpy(pd1,psrc,sizeof(int));
	ret = ft_memcpy(pd2,psrc,sizeof(int));
	cr_assert_arr_eq(d1, d2, sizeof(int));
	cr_assert_eq(pd2, ret);

	memcpy(pd1,psrc,4*sizeof(int));
	ret = ft_memcpy(pd2,psrc,4*sizeof(int));
	cr_assert_arr_eq(d1, d2,4*sizeof(int));
	cr_assert_eq(pd2, ret);
}

Test(memcpy, no_touchy, .signal = SIGSEGV)
{
	char *s1 = "read";
	char *s2 = "only";

	ft_memcpy((void *)s1, (void *)s2, 4);
}


Test(memcpy, bis_ass_string)
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
	cr_assert_arr_eq((char *)ft_memcpy(p2,p1,INT_MAX/1000),toolong, INT_MAX/1000);
}

Test(memcpy, its_a_trap)
{
	ft_memcpy(NULL, "pas null", 0);
	ft_memcpy("pas null",NULL, 0);
	ft_memcpy(NULL, NULL, 0);
	cr_assert(1);
}

Test(memcpy, SEGSUCCESS, .signal = SIGSEGV)
{
	ft_memcpy(NULL, NULL, 1);
}

Test(memcpy, lSEGSUCCESS, .signal = SIGSEGV)
{
	char * s = strdup("42");
	ft_memcpy(s, NULL, 1);
}

Test(memcpy, rSEGSUCCESS, .signal = SIGSEGV)
{
	char * s = strdup("42");
	ft_memcpy(NULL, s, 1);
}
