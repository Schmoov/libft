#include <criterion/criterion.h>
#include <stdlib.h>
#include "libft.h"

void	no_op(void *cont)
{
	(void) cont;
}

Test(lstlast, basics)
{
	int	a = 42;
	int	b = 0;
	int	c = -243;
	t_list	*list = NULL;
	t_list	*node_a = ft_lstnew((void *)&a);
	t_list	*node_b = ft_lstnew((void *)&b);
	t_list	*node_c = ft_lstnew((void *)&c);

	cr_assert_eq(ft_lstlast(list), NULL);

	ft_lstadd_back(&list, node_a);
	cr_assert_eq(ft_lstlast(list), node_a);

	ft_lstadd_back(&list, node_b);
	cr_assert_eq(ft_lstlast(list), node_b);

	ft_lstadd_back(&list, node_c);
	cr_assert_eq(ft_lstlast(list), node_c);

	ft_lstclear(&list, no_op);
}
