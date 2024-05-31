/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <parden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 11:32:44 by parden            #+#    #+#             */
/*   Updated: 2024/05/22 17:44:47 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Id rather have it crash on overflow but man hints strongly as 0 as error
/*
static int	ft_seppuku(void)
{
	int	*katana;

	katana = NULL;
	return(*katana);
}
*/
static bool	is_int(long long n)
{
	return (n <= INT_MAX && n >= INT_MIN);
}

static bool	ft_isspace(int c)
{
	return (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v');
}

int	ft_atoi(const char *nptr)
{
	long long	res;
	size_t		i;
	int			sign;

	res = 0;
	i = 0;
	sign = 1;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]) && is_int(sign * res))
	{
		res = 10 * res + nptr[i] - '0';
		i++;
	}
	res *= sign;
	if (!is_int(res))
		res = 0;
	return (res);
}
