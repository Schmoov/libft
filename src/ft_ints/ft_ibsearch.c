/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ibsearch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 22:09:22 by parden            #+#    #+#             */
/*   Updated: 2024/09/21 22:17:01 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_ibsearch(int key, int *arr, int size)
{
	int	lo;
	int	hi;

	lo = 0;
	hi = size - 1;
	while (lo < hi)
	{
		if (arr[(lo + hi) / 2] < key)
			lo = (lo + hi) / 2 + 1;
		else if (arr[(lo + hi) / 2] > key)
			hi = (lo + hi) / 2 - 1;
		else
			return (arr + (lo + hi) / 2);
	}
	return (NULL);
}
