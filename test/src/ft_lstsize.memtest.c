#include <criterion/criterion.h>
#include <stdlib.h>
#include "libft.h"

Test(lstsize, basics)
{
	int	a = 42;
	int	b = 0;
	int	c = -243;
	t_list	*list = NULL;
	t_list	*node_a = ft_lstnew((void *)&a);
	t_list	*node_b = ft_lstnew((void *)&b);
	t_list	*node_c = ft_lstnew((void *)&c);

	cr_assert_eq(ft_lstsize(list), 0);

	ft_lstadd_front(&list, node_a);
	cr_assert_eq(ft_lstsize(list), 1);

	ft_lstadd_front(&list, node_b);
	cr_assert_eq(ft_lstsize(list), 2);

	ft_lstadd_front(&list, node_c);
	cr_assert_eq(ft_lstsize(list), 3);

	free(node_a);
	free(node_b);
	free(node_c);
}
