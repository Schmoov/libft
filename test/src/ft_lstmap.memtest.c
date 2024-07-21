#include <criterion/criterion.h>
#include <stdlib.h>
#include <ctype.h>
#include "libft.h"
/*
void	*trim_first_letter(void *val)
{
	char	*s = *(char **)val;

	if (!(s[1]))
		return NULL;
	else
		return (void *)&strdup(s + 1);
}

void	free_str(void *val)
{
	free(*(char **)val);
}

Test(lstmap, deleting_first_letters)
{
	char	*str1 = strdup("Mammouth");
	char	*str2 = strdup(" ");
	char	*str3 = strdup("Mamie");
	char	*str4 = strdup(" !");
	t_list	*node_str1 = ft_lstnew((void *)&str1);
	t_list	*node_str2 = ft_lstnew((void *)&str2);
	t_list	*node_str3 = ft_lstnew((void *)&str3);
	t_list	*node_str4 = ft_lstnew((void *)&str4);
	t_list	*lst = NULL;

	ft_lstadd_front(&lst, node_str1);
	ft_lstadd_front(&lst, node_str2);
	ft_lstadd_front(&lst, node_str3);
	ft_lstadd_front(&lst, node_str4);

	ft_lstmap(lst, trim_first_letter, free_str);
	cr_expext_str_eq(*(char **)lst->content, "ammouth");
	cr_expext_str_eq(*(char **)lst->next->content, "amie");
	cr_expext_str_eq(*(char **)lst->next->next->content, "MAMMOUTH ECRASE LES PRIX");

	ft_lstiter(lst, bob);
	cr_expext_str_eq(*(char **)lst->content, "qUe d'hUmOuR !");
	cr_expext_str_eq(*(char **)lst->next->content, "mAmIe eCrAsE LeS PrOuTs");
	cr_expext_str_eq(*(char **)lst->next->next->content, "mAmMoUtH EcRaSe lEs pRiX");


	ft_lstclear(&lst, free_str);
}
Test(lstiter, ints)
{
	int	a = 42;
	t_list	*node_a = ft_lstnew((void *)&a);
	int	b = 0;
	t_list	*node_b = ft_lstnew((void *)&b);
	int	c = -3583;
	t_list	*node_c = ft_lstnew((void *)&c);
	t_list	*lst = NULL;

	ft_lstadd_front(&lst, node_a);
	ft_lstadd_front(&lst, node_b);
	ft_lstadd_front(&lst, node_c);

	ft_lstiter(lst, change_sign);
	cr_expect_eq(*(int *)lst->content, 3583);
	cr_expect_eq(*(int *)lst->next->content, 0);
	cr_expect_eq(*(int *)lst->next->next->content, -42);

	ft_lstiter(lst, make_zero);
	cr_expect_eq(*(int *)lst->content, 0);
	cr_expect_eq(*(int *)lst->next->content, 0);
	cr_expect_eq(*(int *)lst->next->next->content, 0);

	ft_lstclear(&lst, identity);
}

#include <criterion/criterion.h>
#include <ctype.h>
#include "../../libft.h"

char f1(unsigned int i, char c)
{
	(void) i;
	return (toupper(c));
}

char f2(unsigned int i, char c)
{
	if (i%2)
		return(toupper(c));
	else
		return(tolower(c));
}

char f3(unsigned int i, char c)
{
	char *button = NULL;
	return (i + c + button[420]);
}

Test(strmapi, caps_lock)
{
	char *s = "Tu m'enTends la ?";
	char *t = ft_strmapi(s, f1);
	cr_expect_str_eq(t, "TU M'ENTENDS LA ?");
	free(t);
}

Test(strmapi, bOb)
{
	char *s = "Tu m'enTends la ?";

	char *t = ft_strmapi(s, f2);
	cr_expect_str_eq(t, "tU M'EnTeNdS La ?");
	free(t);
}

Test(strmapi, empty)
{
	char *s = "";
	
	char *t = ft_strmapi(s, f2);
	cr_expect_str_eq(t, "");
	free(t);
	t = ft_strmapi(s, f3);
	cr_expect_str_eq(t, "");
	free(t);
}*/
