/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <parden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 11:16:12 by parden            #+#    #+#             */
/*   Updated: 2024/05/25 12:47:38 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

//Normie edition : Just add the errno line under the SIZE_MAX
//check to upgrade to POSIX compliancy
//#include <errno.h>
//errno = ENOMEM;
void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*ret;

	if (elsize && SIZE_MAX / elsize < nelem)
	{
		return (NULL);
	}
	ret = (void *)malloc(nelem * elsize);
	if (!ret)
		return (NULL);
	ft_bzero(ret, nelem * elsize);
	return (ret);
}
