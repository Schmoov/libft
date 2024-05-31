#include <strings.h>
#include <string.h>
#include <limits.h>
#include <signal.h>
#include <criterion/criterion.h>
#include "libft.h"

Test(bzero, insert_zeros_char_arr)
{
	char a1[6] = {'0','1','2','3','4','5'};
	char a2[6] = {'0','1','2','3','4','5'};
	
	ft_bzero((void *)(a1 + 2), 2);
	bzero((void *)(a2 + 2), 2);

	cr_assert_arr_eq(a1, a2, 6);
}

Test(bzero, insert_zero_int_arr)
{
	int a1[6] = {0,1,2,3,4,5};
	int a2[6] = {0,1,2,3,4,5};
	int expected[6] =  {0,1,0,0,4,5};
	
	ft_bzero((void *)(a1 + 2), 2*sizeof(int));
	bzero((void *)(a2 + 2), 2*sizeof(int));

	cr_assert_arr_eq(a1, a2, 6*sizeof(int));
	cr_assert_arr_eq(a1, expected, 6*sizeof(int));

}

Test(bzero, big_ass_array)
{
	char toolong[INT_MAX/1000];
	for (long i = 0; i<INT_MAX/1000; i++)
	{
		toolong[i] = 'X';
	}
	ft_bzero((void *)toolong, INT_MAX/1000);
	cr_assert_null(memchr((void *)toolong, 'X', INT_MAX/1000));
}

Test(bzero, do_nothing)
{
	int a1[3] = {42,42,42};
	int a2[3] = {42,42,42};

	ft_bzero (a2, 0);
	cr_assert_arr_eq(a1, a2, 3*sizeof(int));
}

Test(bzero, its_a_trap)
{
	ft_bzero(NULL, 0);
	cr_assert(1);
}

Test(bzero, SEGSUCCESS, .signal = SIGSEGV)
{
	ft_bzero(NULL, 1);
}
