/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <parden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 10:40:38 by parden            #+#    #+#             */
/*   Updated: 2024/05/22 16:36:36 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	count_char(int n)
{
	size_t	count;

	count = 0;
	if (!n)
		return (1);
	if (n < 0)
		count++;
	while (n)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*itoa_wrap(long long n)
{
	size_t	len;
	char	*res;

	len = count_char(n);
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[len] = 0;
	if (!n)
		*res = '0';
	if (n < 0)
	{
		*res = '-';
		n = -n;
	}
	while (n)
	{
		res[len - 1] = (n % 10) + '0';
		len--;
		n /= 10;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	return (itoa_wrap(n));
}
