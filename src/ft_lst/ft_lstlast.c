/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:10:49 by parden            #+#    #+#             */
/*   Updated: 2024/10/26 20:34:49 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

//lst == NULL represents an empty list
t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (lst);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
