/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:59:49 by parden            #+#    #+#             */
/*   Updated: 2024/06/04 17:58:57 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	percent_printer(void)
{
	ft_putchar_fd('%', 1);
	return (1);
}

void	skip_past_token(char **s)
{
	if (!**s)
		return ;
	(*s)++;
	while (**s && !ft_strchr(SPECIFIERS, **s))
		(*s)++;
	if (**s)
		(*s)++;
}

int	print_until_percent(char **s)
{
	int	i;

	i = 0;
	while ((*s)[i] && (*s)[i] != '%')
		i++;
	write(1, *s, i);
	*s = *s + i;
	skip_past_token(s);
	return (i);
}
