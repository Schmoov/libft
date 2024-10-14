/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <parden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 11:32:44 by parden            #+#    #+#             */
/*   Updated: 2024/10/14 20:47:24 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	ft_isspace(int c)
{
	return (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v');
}

static char	*parse_base(char **nptr)
{
	if (**nptr == '0')
	{
		if (ft_tolower(*(*nptr + 1)) == 'x')
			return (*nptr += 2, LOBASE16);
		else if (*(*nptr + 1) == 'b')
			return (*nptr += 2, "01");
	}
	return (BASE10);
}

static void	strtoll_init(char **nptr, int *sign, char **base, bool **of)
{
	if (*of)
		**of = false;
	*sign = 1;
	while (ft_isspace(**nptr))
		(*nptr)++;
	if (**nptr == '+' || **nptr == '-')
	{
		if (**nptr == '-')
			*sign = -1;
		(*nptr)++;
	}
	*base = parse_base(nptr);
}

//The overflow calc is sus AF
//but tests are green =]
static bool	is_overflow(t_ll *res, int digit, int *sign, char *base)
{
	int	len;

	len = ft_strlen(base);
	if ((*sign == 1 && *res > (LLONG_MAX - digit) / len)
		|| (*sign == -1 && - *res < (LLONG_MIN + digit) / len))
	{
		if (*sign == 1)
			*res = LLONG_MAX;
		else
			*res = LLONG_MIN;
		*sign = 1;
		return (true);
	}
	return (false);
}

//handles hexa and binary when prefixed, assumes base 10 otherwise
t_ll	ft_strtoll(char *nptr, char **endptr, bool *overflow)
{
	t_ll	res;
	int		sign;
	char	*base;
	int		digit;

	res = 0;
	strtoll_init(&nptr, &sign, &base, &overflow);
	while (ft_isalnum(*nptr) && ft_strchr(base, ft_tolower(*nptr)))
	{
		digit = ft_strchr(base, ft_tolower(*nptr)) - base;
		if (is_overflow(&res, digit, &sign, base))
		{
			if (overflow)
				*overflow = true;
			break ;
		}
		res = ft_strlen(base) * res + digit;
		nptr++;
	}
	res *= sign;
	if (endptr)
		*endptr = nptr;
	return (res);
}
