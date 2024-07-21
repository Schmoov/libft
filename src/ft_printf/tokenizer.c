/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:44:37 by parden            #+#    #+#             */
/*   Updated: 2024/06/04 18:23:25 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	free_token_strs(char **token_strs)
{
	size_t	i;

	i = 0;
	while (token_strs[i])
	{
		free(token_strs[i]);
		i++;
	}
	free(token_strs);
	return (0);
}

size_t	count_tok(const char *s)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] != '%')
			i++;
		if (s[i])
		{
			count++;
			i++;
		}
		while (s[i] && !ft_strchr(SPECIFIERS, s[i]))
			i++;
		if (s[i])
			i++;
	}
	return (count);
}

static size_t	insert_token(char **token_strs, const char *s, size_t start)
{
	size_t	len;

	len = 0;
	while (!ft_strchr(SPECIFIERS, s[start + len]))
			len++;
	len++;
	*token_strs = ft_substr(s, start, len);
	if (!*token_strs)
		return (0);
	return (start + len);
}

//A token_str excludes '%' and includes the specifier
int	tokenize(char **token_strs, const char *s)
{
	size_t	i_s;
	size_t	i_token_strs;

	i_s = 0;
	i_token_strs = 0;
	while (s[i_s])
	{
		while (s[i_s] && s[i_s] != '%')
			i_s++;
		if (s[i_s])
		{
			i_s = insert_token(token_strs + i_token_strs, s, i_s + 1);
			if (!i_s)
				return (free_token_strs(token_strs));
			i_token_strs++;
		}
	}
	return (1);
}
