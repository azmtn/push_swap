/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: border <border@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 09:54:55 by border            #+#    #+#             */
/*   Updated: 2021/08/12 09:54:57 by border           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_create_dop(const int *buff, int len, t_list *lst, t_stack *new_list)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if (i < len - 1)
		{
			new_list->next = (t_stack *)malloc(sizeof(t_stack));
			if (!new_list->next)
				ft_error(0, &lst);
			ft_lstadd_back(&lst, ft_lstnew(new_list->next));
		}
		new_list->data = buff[i];
		if (i == (len - 1))
			new_list->next = NULL;
		else
			new_list = new_list->next;
		i++;
	}
}

t_stack	*ft_create_stack(const int *buff, int len, t_list *lst)
{
	t_stack	*new_list;
	t_stack	*first_element;

	new_list = (t_stack *)malloc(sizeof(t_stack));
	if (!new_list)
		ft_error(0, &lst);
	ft_lstadd_back(&lst, ft_lstnew(new_list));
	first_element = new_list;
	ft_create_dop(buff, len, lst, new_list);
	return (first_element);
}
