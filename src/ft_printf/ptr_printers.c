/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_printers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:05:52 by parden            #+#    #+#             */
/*   Updated: 2024/06/05 14:37:51 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*cap_strlen(void *p, t_token *tok)
{
	char	*s;
	int		cap;
	int		i;

	i = 0;
	cap = INT_MAX;
	s = p;
	if (tok->has_prec)
		cap = tok->precision;
	while (cap && s[i])
	{
		i++;
		cap--;
	}
	s = (char *)malloc(i + 1);
	if (!s)
		return (NULL);
	s[i] = 0;
	return ((char *)ft_memcpy((void *)s, p, i));
}

int	s_printer(t_token *tok, void *p)
{
	char	*toprint;
	int		ret_value;

	if (!p && (!tok->has_prec || tok->precision > 5))
		toprint = ft_strdup("(null)");
	else if (!p)
		toprint = ft_strdup("");
	else
		toprint = cap_strlen(p, tok);
	add_width_blanks(&toprint, tok);
	if (!toprint)
		return (-1);
	ret_value = ft_strlen(toprint);
	ft_putstr_fd(toprint, 1);
	free(toprint);
	return (ret_value);
}

int	p_printer(t_token *tok, void *p)
{
	char	*toprint;
	int		ret_value;

	if (p)
	{
		toprint = ptrtoa_base(p, LOBASE16);
		add_base_prefix(&toprint, tok, "0x");
	}
	else
		toprint = ft_strdup("(nil)");
	add_width_blanks(&toprint, tok);
	if (!toprint)
		return (-1);
	ret_value = ft_strlen(toprint);
	ft_putstr_fd(toprint, 1);
	free(toprint);
	return (ret_value);
}
