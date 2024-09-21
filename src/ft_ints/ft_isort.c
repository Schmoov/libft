/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 21:45:39 by parden            #+#    #+#             */
/*   Updated: 2024/09/21 21:45:41 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_isort(int *arr, int size)
{
	int	pivot;
	int	i;
	int	hi;

	if (size < 2)
		return ;
	pivot = arr[0];
	i = 1;
	hi = size;
	while (i < hi)
	{
		if (arr[i] < pivot)
			i++;
		else
		{
			ft_iswap(arr + i, arr + hi - 1);
			hi--;
		}
	}
	arr[0] = arr[i - 1];
	arr[i - 1] = pivot;
	ft_isort(arr, i - 1);
	ft_isort(arr + i, size - i);
}
