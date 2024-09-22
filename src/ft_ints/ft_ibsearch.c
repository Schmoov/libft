/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ibsearch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 22:09:22 by parden            #+#    #+#             */
/*   Updated: 2024/09/22 15:09:53 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_ibsearch(int key, int *arr, int size)
{
	int	lo;
	int	hi;
	int	mid;

	lo = -1;
	hi = size;
	while (hi - lo > 1)
	{
		mid = lo + (hi - lo) / 2;
		if (arr[mid] > key)
			hi = mid;
		else
			lo = mid;
	}
	if (lo == -1 || arr[lo] != key)
		return (NULL);
	return (arr + lo);
}
