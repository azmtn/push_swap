/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: border <border@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 09:55:41 by border            #+#    #+#             */
/*   Updated: 2021/08/12 09:55:42 by border           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_max(t_stack *stk)
{
	int	max;

	max = stk->data;
	while (stk)
	{
		if (stk->data > max)
			max = stk->data;
		stk = stk->next;
	}
	return (max);
}

void	ft_sort3(t_stacks *stks)
{
	int	max;

	max = ft_max(stks->a);
	if (stks->a_len == 1)
		return ;
	else if (stks->a_len == 2)
	{
		if (stks->a->data > stks->a->next->data)
			cmd_add(SA, stks);
		return ;
	}
	else if (stks->a_len == 3)
	{
		if (stks->a->data == max)
			cmd_add(RA, stks);
		if (stks->a->next->data == max)
			cmd_add(RRA, stks);
		if (stks->a->data > stks->a->next->data)
			cmd_add(SA, stks);
	}
}

void	ft_sort5(t_stacks *stks)
{
	while (stks->b_len < 1)
	{
		if (stks->a->data == stks->min || stks->a->data == stks->max)
		{
			if (stks->a->data == stks->min)
				stks->sort++;
			cmd_add(PB, stks);
		}
		else
			cmd_add(RA, stks);
	}
	ft_sort4(stks);
	cmd_add(PA, stks);
	if (stks->a->data == stks->max)
		cmd_add(RA, stks);
}
