/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: border <border@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 14:56:16 by border            #+#    #+#             */
/*   Updated: 2021/08/08 14:56:17 by border           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*elem;

	if (!lst || !f)
		return (NULL);
	elem = ft_lstnew(f(lst->content));
	if (!elem)
	{
		ft_lstclear(&elem, del);
		return (NULL);
	}
	list = elem;
	lst = lst->next;
	while (lst)
	{
		list->next = ft_lstnew(f(lst->content));
		if (!list->next)
			ft_lstclear(&elem, del);
		else
		{
			lst = lst->next;
			list = list->next;
		}
	}
	return (elem);
}
