#include <strings.h>
#include <string.h>
#include <limits.h>
#include <signal.h>
#include <criterion/criterion.h>
#include "libft.h"

Test(memset, insert_in_char_arr)
{
	char a1[6] = {'0','1','2','3','4','5'};
	char a2[6] = {'0','1','2','3','4','5'};
	char *ret;

	ret = ft_memset((void *)(a1 + 2), 0, 2);
	memset((void *)(a2 + 2), 0, 2);
	cr_expect_arr_eq(a1, a2, 6);
	cr_expect_eq(ret,a1+2);

	ret = ft_memset((void *)(a1 + 2), -5, 2);
	memset((void *)(a2 + 2), -5, 2);
	cr_expect_arr_eq(a1, a2, 6);
	cr_expect_eq(ret,a1+2);
	
	ret = ft_memset((void *)(a1 + 2), '*', 2);
	memset((void *)(a2 + 2), '*', 2);
	cr_expect_arr_eq(a1, a2, 6);
	cr_expect_eq(ret,a1+2);
}

Test(memset, insert_in_int_arr)
{
	int a1[6] = {0,1,2,3,4,5};
	int a2[6] = {0,1,2,3,4,5};
	int expected[6] =  {0,1,0,0,4,5};
	int *ret;

	ret =ft_memset((void *)(a1 + 2),1024, 2*sizeof(int));
	memset((void *)(a2 + 2),0, 2*sizeof(int));

	cr_expect_arr_eq(a1, a2, 6*sizeof(int));
	cr_expect_arr_eq(a1, expected, 6*sizeof(int));
	cr_expect_eq(ret,a1+2);

}

Test(memset, big_ass_array)
{
	char toolong[INT_MAX/1000];
	for (long i = 0; i<INT_MAX/1000; i++)
	{
		toolong[i] = 'X';
	}
	ft_memset((void *)toolong, 'x', INT_MAX/1000);
	cr_expect_null(memchr((void *)toolong, 'X', INT_MAX/1000));
}

Test(memset, do_nothing)
{
	int a1[3] = {42,42,42};
	int a2[3] = {42,42,42};
	int *ret;

	ret = ft_memset(a2, 'r', 0);
	cr_expect_arr_eq(a1, a2, 3*sizeof(int));
	cr_expect_eq(ret,a2);
}

Test(memset, its_a_trap)
{
	char *ret;
	ret = ft_memset(NULL,42, 0);
	cr_expect_null(ret);
}

Test(memset, SEGSUCCESS, .signal = SIGSEGV)
{
	ft_memset(NULL, -1, 1);
}

