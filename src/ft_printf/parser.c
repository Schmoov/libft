/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:44:37 by parden            #+#    #+#             */
/*   Updated: 2024/06/04 18:21:38 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*free_token_list(t_token **token_list)
{
	size_t	i;

	i = 0;
	while (token_list[i])
	{
		free(token_list[i]);
		i++;
	}
	free(token_list);
	return (NULL);
}

static t_token	*new_token(const char token_spec)
{
	t_token	*new;

	new = (t_token *)malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->spec = token_spec;
	new->minus_flag = false;
	new->zero_flag = false;
	new->sign = 0;
	new->prefix = false;
	new->width = 0;
	new->has_prec = 0;
	return (new);
}

void	parse_char(char c, t_token *parsed_token)
{
	if (c == '#')
		parsed_token->prefix = true;
	if (c == '-')
	{
		parsed_token->minus_flag = true;
		parsed_token->zero_flag = false;
	}
	if (c == '0' && !parsed_token->minus_flag)
		parsed_token->zero_flag = true;
	if (c == '+')
		parsed_token->sign = '+';
	if (c == ' ' && parsed_token->sign != '+')
		parsed_token->sign = ' ';
}

t_token	*parse_one(const char *token_str)
{
	t_token	*parsed_token;
	size_t	token_len;
	size_t	i;

	token_len = ft_strlen(token_str);
	parsed_token = new_token(token_str[token_len - 1]);
	if (!parsed_token)
		return (NULL);
	i = 0;
	while (ft_strchr(FLAGS, token_str[i]))
	{
		parse_char(token_str[i], parsed_token);
		i++;
	}
	if (token_str[i] != '.' && ft_atoi(token_str + i))
		parsed_token->width = ft_atoi(token_str + i);
	while (ft_isdigit(token_str[i]))
		i++;
	if (token_str[i] == '.' && token_str[i + 1] != '-')
	{
		parsed_token->has_prec = true;
		parsed_token->precision = ft_atoi(token_str + i + 1);
		parsed_token->zero_flag = false;
	}
	return (parsed_token);
}

t_token	**parse(const char *s)
{
	char	**token_strs;
	t_token	**token_list;
	size_t	i;

	token_strs = (char **)ft_calloc((count_tok(s) + 1), sizeof(char *));
	if (!token_strs || !tokenize(token_strs, s))
		return (NULL);
	token_list = (t_token **)ft_calloc((count_tok(s) + 1), sizeof(t_token *));
	if (!token_list)
		return ((void *)free_token_strs(token_strs));
	i = 0;
	while (token_strs[i])
	{
		token_list[i] = parse_one(token_strs[i]);
		if (!token_list[i])
		{
			free_token_strs(token_strs);
			return (free_token_list(token_list));
		}
		i++;
	}
	free_token_strs(token_strs);
	return (token_list);
}
