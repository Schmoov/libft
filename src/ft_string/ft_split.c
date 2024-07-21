/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <parden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:25:26 by parden            #+#    #+#             */
/*   Updated: 2024/05/25 13:50:21 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	free_res(char **res)
{
	size_t	i;

	i = 0;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
}

static size_t	count_words(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

//Returns the end of current word or 0 if alloc fails
static size_t	insert_word(char **res, char const *s, size_t start, char c)
{
	size_t	len;

	while (s[start] == c)
		start++;
	len = 0;
	while (s[start + len] && s[start + len] != c)
		len++;
	*res = ft_substr(s, start, len);
	if (!(*res))
		return (0);
	return (start + len);
}

static char	**wrap_split(char **res, char const *s, char c, size_t count)
{
	size_t	start;
	size_t	i;

	start = 0;
	i = 0;
	while (i < count)
	{
		start = insert_word(res + i, s, start, c);
		if (!start)
		{
			free_res(res);
			return (NULL);
		}
		i++;
	}
	return (res);
}

char	**ft_split(char const *s, char c)
{
	size_t	word_count;
	char	**res;

	word_count = count_words(s, c);
	res = (char **)ft_calloc(word_count + 1, sizeof(char *));
	if (!res)
		return (NULL);
	return (wrap_split(res, s, c, word_count));
}
