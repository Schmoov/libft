/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:21:24 by parden            #+#    #+#             */
/*   Updated: 2024/05/21 12:31:10 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*curr;
	t_list	*nxt;

	curr = *lst;
	while (curr)
	{
		nxt = curr->next;
		ft_lstdelone(curr, del);
		curr = nxt;
	}
	*lst = NULL;
}
