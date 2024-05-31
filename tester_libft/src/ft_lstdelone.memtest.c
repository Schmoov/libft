#include <criterion/criterion.h>
#include <stdlib.h>
#include "libft.h"

void	no_op(void *osef)
{
	(void) osef;
}

void	free_rubik(void *content)
{
	int ***cube = content;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			free(cube[i][j]);
	for (int i = 0; i < 3; i++)
		free(cube[i]);
	free(cube);
}

Test(lstdelone, int_on_stack)
{
	int	a = 42;
	t_list	*node_a = ft_lstnew((void *)&a);
	ft_lstdelone(node_a, no_op);
}

Test(lstdelone, string)
{
	t_list	*node_str = ft_lstnew((void *)strdup("Mammouth ecrase les prix"));
	ft_lstdelone(node_str, free);
}

Test(lstdelone, recursive_allocs)
{
	int ***cub = malloc(3*sizeof(int **));
	for (int i = 0; i < 3; i++)
		cub[i] = (int **)malloc(3*sizeof(int *));
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cub[i][j] = (int *)malloc(3*sizeof(int));
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			for (int k = 0; k < 3; k++)
				cub[i][j][k] = 9*i + 3*j + k;
	t_list	*node_cub = ft_lstnew((void *)cub);
	ft_lstdelone(node_cub, free_rubik);
}
