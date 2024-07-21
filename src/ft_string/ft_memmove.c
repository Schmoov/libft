/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <parden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 09:21:45 by parden            #+#    #+#             */
/*   Updated: 2024/05/22 12:04:57 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//memcpy but right to left
static void	*ft_memrcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*s_dest;
	unsigned char	*s_src;
	size_t			i;

	s_dest = (unsigned char *)dest;
	s_src = (unsigned char *)src;
	if (!n)
		return (dest);
	i = n - 1;
	while (i)
	{
		s_dest[i] = s_src[i];
		i--;
	}
	s_dest[i] = s_src[i];
	return ((void *)s_dest);
}

//They can only overlap in one direction. We copy in the other.
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest < src)
		return (ft_memcpy(dest, src, n));
	return (ft_memrcpy(dest, src, n));
}
