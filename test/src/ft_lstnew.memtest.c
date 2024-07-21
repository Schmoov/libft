#include <criterion/criterion.h>
#include <stdlib.h>
#include "libft.h"

Test(lstnew, basics)
{
	int	a = 42;
	t_list	*new = ft_lstnew((void *)&a);
	cr_assert_eq(*((int *)new->content), a);
	cr_assert_null(new->next);
	free(new);

	char	c = '*';
	new = ft_lstnew((void *)&c);
	cr_assert_eq(*((char *)new->content), c);
	cr_assert_null(new->next);
	free(new);

	char	*str = "prout";
	new = ft_lstnew((void *)&str);
	cr_assert_str_eq(*(char **)new->content, str);
	cr_assert_null(new->next);
	free(new);
}
