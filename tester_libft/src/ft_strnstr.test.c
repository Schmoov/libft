#include <strings.h>
#include <stdio.h>
#include <string.h>
#include <bsd/string.h>
#include <limits.h>
#include <signal.h>
#include <criterion/criterion.h>
#include "libft.h"

Test(strnstr, streustreu_la_street)
{
	char *big = "streustreu la street";
	size_t len = strlen(big);
	char *l1 = "eu la";
	char *l2 = "eu l0";
	char *l3 = "str";
	char *l4 = "";
	char l5[] = {'t', 0};

	cr_assert_eq(strnstr(big,l1,len), ft_strnstr(big,l1,len));
	cr_assert_eq(strnstr(big,l2,len), ft_strnstr(big,l2,len));
	cr_assert_eq(strnstr(big,l3,len), ft_strnstr(big,l3,len));
	cr_assert_eq(strnstr(big,l4,len), ft_strnstr(big,l4,len));
	cr_assert_eq(strnstr(big,l5,len), ft_strnstr(big,l5,len));
}

Test(strnstr, big_ass_string)
{
	char big[INT_MAX/1000];
	for (int i=0; i < INT_MAX/1000; i++)
	{
		big[i] = 'q';
	}
	big[INT_MAX/1000 - 1] = 0;
	char *little = "Blaze it";
	strcpy(big + 42069, little);
	
	cr_assert_eq(strnstr(big,little,INT_MAX/1000-1), ft_strnstr(big,little,INT_MAX/1000-1));
	cr_assert_eq(strnstr(big,little,INT_MAX/1000), ft_strnstr(big,little,INT_MAX/1000));
	cr_assert_eq(strnstr(big,"prout",INT_MAX/1000), ft_strnstr(big,"prout",INT_MAX/1000));
}

Test(strnstr, different_len)
{
	char *big = "bonjour 46 comment tu 46 avec un 46?";
	char *l = "46";
	
	cr_assert_eq(strnstr(big,l,0), ft_strnstr(big,l,0));
	cr_assert_eq(strnstr(big,l,1), ft_strnstr(big,l,1));
	cr_assert_eq(strnstr(big,l,9), ft_strnstr(big,l,9));
	cr_assert_eq(strnstr(big,l,10), ft_strnstr(big,l,10));
	cr_assert_eq(strnstr(big,l,11), ft_strnstr(big,l,11));
	cr_assert_eq(strnstr(big,l,strlen(big)), ft_strnstr(big,l,strlen(big)));
	cr_assert_eq(strnstr(big+10,l,strlen(big+10)), ft_strnstr(big+10,l,strlen(big+10)));
}

Test(strnstr, empty_haystack)
{
	cr_assert_eq(strnstr("","",0), ft_strnstr("","",0));
	cr_assert_eq(strnstr("","",1), ft_strnstr("","",1));
	cr_assert_eq(strnstr("","a",0), ft_strnstr("","a",0));
	cr_assert_eq(strnstr("","a",1), ft_strnstr("","a",1));
}

Test(strnstr, haystack_is_a_needle)
{
	char *big = "aaa";
	char *l1 = "aaa";
	char *l2 = "aab";

	cr_assert_eq(strnstr(big,l1,3), ft_strnstr(big,l1,3));
	cr_assert_eq(strnstr(big,l1,13), ft_strnstr(big,l1,13));
	cr_assert_eq(strnstr(big,l2,3), ft_strnstr(big,l2,3));
}

Test(strnstr, thats_not_even_a_char)
{
	char *big = strdup("-->X<--");
	char l1[2] = {-1,0};
	big[3]=-1;
	cr_assert_eq(strnstr(big,l1,0), ft_strnstr(big,l1,0));
	cr_assert_eq(strnstr(big,l1,3), ft_strnstr(big,l1,3));
	cr_assert_eq(strnstr(big,l1,4), ft_strnstr(big,l1,4));
	cr_assert_eq(strnstr(big,l1,40), ft_strnstr(big,l1,40));
}

Test(strnstr, little_SEGSUCESS, .signal = SIGSEGV)
{
	ft_strnstr("aaa",NULL,1);
}

Test(strnstr, big_SEGSUCESS, .signal = SIGSEGV)
{
	ft_strnstr(NULL,"aaa",1);
}
