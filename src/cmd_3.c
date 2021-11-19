/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: border <border@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 09:54:26 by border            #+#    #+#             */
/*   Updated: 2021/08/12 09:54:26 by border           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_only_spaces(const char *str)
{
	while (ft_isspace(*str))
		str++;
	return (*str != 0);
}

int	ft_is_sorted(t_data *new)
{
	int	*a;
	int	count;

	a = new->a;
	count = new->len - 1;
	while (count--)
	{
		if (*a > *(a + 1))
			return (TRUE);
		a++;
	}
	return (FALSE);
}

void	ft_error(int key, t_list **free_list)
{
	t_list	*n_list;

	if (key == 1)
		ft_putendl_fd("Error", 2);
	if (free_list && *free_list)
	{
		n_list = (*free_list)->next;
		ft_lstclear(&n_list, free);
		ft_lstdelone(*free_list, free);
	}
	exit(0);
}

void	ft_rrr(t_stacks *s)
{
	ft_rra(&s->a);
	ft_rrb(&s->b);
}
