/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: border <border@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 09:55:05 by border            #+#    #+#             */
/*   Updated: 2021/08/12 09:55:06 by border           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_stk_back(t_stack *s)
{
	while (s->next)
		s = s->next;
	return (s->data);
}

int	ft_check_conditions(t_stacks *stks, int *start)
{
	if (stks->a->data == stks->sort[*start])
	{
		cmd_add(RA, stks);
		(*start)++;
	}
	else if (stks->a->data == stks->sort[*start + 1] && \
				stks->a->next->data == stks->sort[*start])
	{
		if (stks->b && stks->b->data > stks->b->next->data)
			cmd_add(SS, stks);
		else
			cmd_add(SA, stks);
		cmd_add(RA, stks);
		cmd_add(RA, stks);
		*start += 2;
	}
	else if (stks->a->data != stks->min && stks->a->data != stks->max)
	{
		cmd_add(PB, stks);
		if (stks->b && stks->b->data > stks->mid)
			cmd_add(RB, stks);
	}
	else
		return (0);
	return (1);
}

void	ft_initial_sort(t_stacks *stks, t_list *lst)
{
	int	start;

	start = (ft_stk_back(stks->a) == stks->sort[0]);
	while (stks->a_len > start + 1)
	{
		if (ft_check_conditions(stks, &start))
			;
		else
		{
			cmd_add(RA, stks);
			if (start > 0)
				break ;
		}
	}
	while (stks->a->data != stks->min && stks->a->data != stks->max)
	{
		cmd_add(PB, stks);
		if (stks->b->data > stks->mid)
			cmd_add(RB, stks);
	}
	if (stks->a->data == stks->min)
		cmd_add(RRA, stks);
	cmd_add(PA, stks);
	ft_basic_sort(stks, lst);
}
