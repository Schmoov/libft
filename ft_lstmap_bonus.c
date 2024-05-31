/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 16:00:46 by parden            #+#    #+#             */
/*   Updated: 2024/05/23 13:04:53 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	*catch_alloc(t_list *lst, void (*del)(void *), void	*maybe_cont)
{
	if (maybe_cont)
		del(maybe_cont);
	ft_lstclear(&lst, del);
	return (NULL);
}

//f can allocate memory, thus it can fail, thus it is assumed to reserve
//NULL as ENOMEM error this implementation handles correctly the case
//where f fails but lstnew succeeds.
//A f that returns NULL as value is considered UB.
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	head;
	t_list	*tmp;
	void	*tmp_cont;

	if (!lst)
		return (NULL);
	head.next = NULL;
	tmp = &head;
	while (lst)
	{
		tmp_cont = f(lst->content);
		if (!tmp_cont)
			return (catch_alloc(head.next, del, NULL));
		tmp->next = ft_lstnew(tmp_cont);
		tmp = tmp->next;
		if (!tmp)
			return (catch_alloc(head.next, del, tmp_cont));
		lst = lst->next;
	}
	return (head.next);
}
//The normie version : caller has the responsability to check every
//content for NULL to ensure f didn't fail. Yuck !
/*
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	head;
	t_list	*tmp;
	void	*tmp_cont;

	if (!lst)
		return (NULL);
	head.next = NULL;
	tmp = &head;
	while (lst)
	{
		tmp_cont = f(lst->content);
		tmp->next = ft_lstnew(tmp_cont);
		tmp = tmp->next;
		if (!tmp)
		{
			del(tmp_cont);
			ft_lstclear(&head.next, del);
			return (NULL);
		}
		lst = lst->next;
	}
	return (head.next);
}
*/
