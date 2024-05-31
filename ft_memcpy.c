/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <parden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 09:14:04 by parden            #+#    #+#             */
/*   Updated: 2024/03/23 13:10:16 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*s_dest;
	unsigned char	*s_src;
	size_t			i;

	s_dest = (unsigned char *)dest;
	s_src = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		s_dest[i] = s_src[i];
		i++;
	}
	return ((void *)s_dest);
}
