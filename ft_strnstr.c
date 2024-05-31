/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <parden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 12:18:12 by parden            #+#    #+#             */
/*   Updated: 2024/05/22 18:04:49 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	is_match(char *candidate, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && candidate[i] && little[i] && candidate[i] == little[i])
		i++;
	return (!little[i]);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*candidate;

	if (!*little)
		return ((char *)big);
	candidate = ft_strchr(big, *little);
	if (!candidate || (size_t)(candidate - big) >= len)
		return (NULL);
	if (is_match(candidate, little, len - (candidate - big)))
		return (candidate);
	return (ft_strnstr(candidate + 1, little, len - (candidate - big + 1)));
}
/*
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while ((i < len) && big[i])
	{
		j = 0;
		while (big[i + j] && little[j] && (i + j < len)
			&& (big[i + j] == little[j]))
			j++;
		if (!little[j])
			return ((char *)big + i);
		i++;
	}
	if (!(*little))
		return ((char *)big);
	return (NULL);
}
*/
