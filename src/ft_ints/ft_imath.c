/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imath.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <parden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 08:37:28 by parden            #+#    #+#             */
/*   Updated: 2024/10/26 20:34:49 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_imax(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_imin(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

//Beware ft_iabs(INT_MIN) is UB !!!
int	ft_iabs(int a)
{
	if (a > 0)
		return (a);
	return (-a);
}
