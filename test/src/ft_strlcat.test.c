#include <strings.h>
#include <stdio.h>
#include <bsd/string.h>
#include <string.h>
#include <limits.h>
#include <signal.h>
#include <criterion/criterion.h>
#include "libft.h"

Test(strlcat, basic)
{
	char dst1[100];
	char dst2[100];
	char *str = "J'adoooore les";
	strcpy(dst1,str);
	strcpy(dst2,str);

	char *src=strdup(" bananes.");

	size_t l1 = strlcat(dst1,src,100);
	size_t l2 = ft_strlcat(dst2,src,100);
	cr_assert_str_eq(dst1,dst2);
	cr_assert_eq(l1,l2);
}

Test(strlcat, just_enough_room)
{
	char dst1[11] = {'0','1','2','3',0};
	char dst2[11] = {'0','1','2','3',0};

	char *src = "456789";

	size_t l1 = strlcat(dst1,src,sizeof(dst1));
	size_t l2 = ft_strlcat(dst2,src,sizeof(dst2));
	cr_assert_str_eq(dst1,dst2);
	cr_assert_eq(l1,l2);
}

Test(strlcat, missing_one)
{
	char dst1[11] = {'0','1','2','3',0};
	char dst2[11] = {'0','1','2','3',0};

	char *src = "456789";

	size_t l1 = strlcat(dst1,src,sizeof(dst1)-1);
	size_t l2 = ft_strlcat(dst2,src,sizeof(dst2)-1);
	cr_assert_str_eq(dst1,dst2);
	cr_assert_eq(l1,l2);
}

Test(strlcat, truncation)
{
	char dst1[10]= {'O','k',0};
	char dst2[10]= {'O','k',0};

	char *src = "I mean like huuuh you know liiiike...";
	size_t l1 = strlcat(dst1,src,sizeof(dst1));
	size_t l2 = ft_strlcat(dst2,src,sizeof(dst2));
	cr_assert_str_eq(dst1,dst2);
	cr_assert_eq(l1,l2);
}

Test(strlcat, empty_dst)
{
	char dst1[100] = {0,'1','2','3',0};
	char dst2[100] = {0,'1','2','3',0};

	char *src = "C'est juste strlcpy du coup ...";

	size_t l1 = strlcat(dst1,src,100);
	size_t l2 = ft_strlcat(dst2,src,100);
	cr_assert_str_eq(dst1,dst2);
	cr_assert_eq(l1,l2);
}

Test(strlcat, empty_src)
{
	char dst1[100] = {'0','1','2','3',0};
	char dst2[100] = {'0','1','2','3',0};

	char *src = "";

	size_t l1 = strlcat(dst1,src,100);
	size_t l2 = ft_strlcat(dst2,src,100);
	cr_assert_str_eq(dst1,dst2);
	cr_assert_eq(l1,l2);
}

Test(strlcat, all_empty)
{
	char d1[1] = {0};
	char d2[1] = {0};

	char *src = "";

	size_t l1 = strlcat(d1,src,100);
	size_t l2 = ft_strlcat(d2,src,100);
	cr_assert_str_eq(d1,d2);
	cr_assert_eq(l1,l2);

	char dst1[100];
	char dst2[100];
	char *str = "J'adoooore les";
	strcpy(dst1,str);
	strcpy(dst2,str);

	size_t ll1 = strlcat(dst1,src,100);
	size_t ll2 = ft_strlcat(dst2,src,100);
	cr_assert_str_eq(dst1,dst2);
	cr_assert_eq(ll1,ll2);
}

Test(strlcat, size_is_zero)
{
	char dst1[100];
	char dst2[100];
	char *str = "J'adoooore les";
	strcpy(dst1,str);
	strcpy(dst2,str);

	char *empty = "";
	char *src=" bananes.";

	size_t l1 = strlcat(dst1,src,0);
	size_t l2 = ft_strlcat(dst2,src,0);
	cr_assert_str_eq(dst1,dst2);
	cr_assert_eq(l1,l2);

	l1 = strlcat(dst1,empty,0);
	l2 = ft_strlcat(dst2,empty,0);
	cr_assert_str_eq(dst1,dst2);
	cr_assert_eq(l1,l2);
	
	dst1[0]=0;
	dst2[0]=0;

	l1 = strlcat(dst1,src,0);
	l2 = ft_strlcat(dst2,src,0);
	cr_assert_str_eq(dst1,dst2);
	cr_assert_eq(l1,l2);

	l1 = strlcat(dst1,empty,0);
	l2 = ft_strlcat(dst2,empty,0);
	cr_assert_str_eq(dst1,dst2);
	cr_assert_eq(l1,l2);
}

Test(strlcat, dstlen_bigger_than_size)
{
	char *dst1 = strdup("0123456789");
	char *dst2 = strdup("0123456789");
	char *src = "abcde";

	size_t l1 = strlcat(dst1,src,0);
	size_t l2 = ft_strlcat(dst2,src,0);
	cr_assert_str_eq(dst1,dst2);
	cr_assert_eq(l1,l2);
	
	l1 = strlcat(dst1,src,1);
	l2 = ft_strlcat(dst2,src,1);
	cr_assert_str_eq(dst1,dst2);
	cr_assert_eq(l1,l2);
	
	l1 = strlcat(dst1,src,2);
	l2 = ft_strlcat(dst2,src,2);
	cr_assert_str_eq(dst1,dst2);
	cr_assert_eq(l1,l2);
	
	l1 = strlcat(dst1,src,7);
	l2 = ft_strlcat(dst2,src,7);
	cr_assert_str_eq(dst1,dst2);
	cr_assert_eq(l1,l2);
}

Test(strlcat, big_ass_string)
{
	char dst1[INT_MAX/1000];
	dst1[0] = 0;
	char dst2[INT_MAX/1000];
	dst2[0] = 0;
	strcpy(dst1,"I LOVE ");
	strcpy(dst2,"I LOVE ");

	char *src="Xavier NIEL";
	for (int i=0; i < 5000; i++)
	{
		strlcat(dst1, src, INT_MAX/1000);
		ft_strlcat(dst2, src, INT_MAX/1000);
	}
	size_t l1 = strlcat(dst1, src, INT_MAX/1000);
	size_t l2 = ft_strlcat(dst2, src, INT_MAX/1000);
	cr_assert_str_eq(dst1,dst2);
	cr_assert_eq(l1,l2);
}

Test(strlcat, SEGSUCCESS, .signal = SIGSEGV)
{
	char *dst ="Cant\0 Touch this";
	char *src="1";

	strlcat(dst,src,6);
}
