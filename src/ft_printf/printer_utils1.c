/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:07:25 by parden            #+#    #+#             */
/*   Updated: 2024/06/05 14:11:15 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*str_filled_with_char(int len, char c)
{
	char	*res;

	res = (char *)malloc(len + 1);
	if (!res)
		return (NULL);
	ft_memset(res, c, len);
	res[len] = 0;
	return (res);
}

void	pad_with_char(char **toprint, int output_len, char c, bool leftpad)
{
	char	*prefix;
	char	*res;

	if (!*toprint)
		return ;
	prefix = str_filled_with_char(output_len - ft_strlen(*toprint), c);
	if (!prefix)
	{
		free(*toprint);
		*toprint = NULL;
		return ;
	}
	if (leftpad)
		res = ft_strjoin(prefix, *toprint);
	else
		res = ft_strjoin(*toprint, prefix);
	free(*toprint);
	free(prefix);
	*toprint = res;
}

void	add_precision_zeroes(char **toprint, t_token *tok)
{
	if (!*toprint)
		return ;
	if (tok->has_prec && (size_t)tok->precision > ft_strlen(*toprint))
		pad_with_char(toprint, tok->precision, '0', true);
}

void	add_width_zeroes(char **toprint, t_token *tok, int prefix_width)
{
	if (!*toprint)
		return ;
	if (tok->zero_flag)
	{
		tok->width -= prefix_width;
		if (tok->width >= 0 && (size_t)tok->width > ft_strlen(*toprint))
			pad_with_char(toprint, tok->width, '0', true);
	}
}

void	add_sign(char **toprint, t_token *tok)
{
	if (!*toprint)
		return ;
	if (tok->sign)
		pad_with_char(toprint, ft_strlen(*toprint) + 1, tok->sign, true);
}
