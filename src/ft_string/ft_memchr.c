/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <parden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 08:32:42 by parden            #+#    #+#             */
/*   Updated: 2024/03/23 13:10:41 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	tofind;

	str = (unsigned char *)s;
	tofind = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == tofind)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}
