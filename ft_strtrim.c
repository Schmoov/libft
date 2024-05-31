/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <parden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:31:27 by parden            #+#    #+#             */
/*   Updated: 2024/05/22 15:42:52 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static bool	is_in(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] && set[i] != c)
		i++;
	return (set[i]);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	size_t			end;

	start = 0;
	while (is_in(s1[start], set))
		start++;
	end = ft_strlen(s1) - 1;
	while (end > start && is_in(s1[end], set))
		end--;
	return (ft_substr(s1, start, end + 1 - start));
}
