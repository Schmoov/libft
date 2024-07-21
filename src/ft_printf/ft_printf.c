/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:59:49 by parden            #+#    #+#             */
/*   Updated: 2024/06/05 14:45:04 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ptr_dispatcher(t_token *tok, void *p)
{
	if (tok->spec == 's')
		return (s_printer(tok, p));
	return (p_printer(tok, p));
}

static int	int_dispatcher(t_token *tok, int n)
{
	if (tok->spec == 'i' || tok->spec == 'd')
		return (d_printer(tok, n));
	if (tok->spec == 'u')
		return (u_printer(tok, n));
	if (tok->spec == 'x')
		return (xlo_printer(tok, n));
	if (tok->spec == 'X')
		return (xup_printer(tok, n));
	return (c_printer(tok, n));
}

static int	wrap_ft_printf(char *s, va_list args, t_token **token_list)
{
	size_t	i;
	int		count;
	int		to_add;

	count = 0;
	i = 0;
	to_add = 0;
	while (to_add != -1 && token_list[i])
	{
		count += to_add + print_until_percent(&s);
		if (token_list[i]->spec == '%')
			to_add = percent_printer();
		else if (token_list[i]->spec == 's' || token_list[i]->spec == 'p')
			to_add = ptr_dispatcher(token_list[i], va_arg(args, void *));
		else
			to_add = int_dispatcher(token_list[i], va_arg(args, int));
		i++;
	}
	if (to_add == -1)
		return (-1);
	count += to_add + print_until_percent(&s);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	char	*s;
	t_token	**token_list;
	int		count;

	if (!format)
		return (-1);
	va_start(args, format);
	s = (char *)format;
	token_list = parse(format);
	if (!token_list)
		return (-1);
	count = wrap_ft_printf(s, args, token_list);
	va_end(args);
	free_token_list(token_list);
	return (count);
}
