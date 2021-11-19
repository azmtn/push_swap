/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: border <border@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 09:55:46 by border            #+#    #+#             */
/*   Updated: 2021/08/12 09:56:01 by border           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_sort_4_1(t_stacks *stks)
{
	if ((stks->a->next->data == stks->sort[2]) && \
				(stks->a->next->next->data == stks->sort[3]))
	{
		cmd_add(RRA, stks);
		cmd_add(SA, stks);
	}
	else if ((stks->a->next->data == stks->sort[3]) && \
				(stks->a->next->next->data == stks->sort[1]))
	{
		cmd_add(SA, stks);
		cmd_add(RA, stks);
	}
	else
	{
		cmd_add(PB, stks);
		ft_sort3(stks);
		cmd_add(PA, stks);
	}
}

void	ft_sort_4_2(t_stacks *stks)
{
	if (stks->a->next->data == stks->sort[3])
	{
		if (stks->a->next->next->data == stks->sort[0])
			cmd_add(SA, stks);
		cmd_add(RA, stks);
		cmd_add(SA, stks);
		if (stks->a->data == stks->sort[0])
			return ;
		cmd_add(RA, stks);
		cmd_add(RA, stks);
	}
	else if ((stks->a->next->data == stks->sort[0]) && \
				(stks->a->next->next->data == stks->sort[2]))
		cmd_add(SA, stks);
	else if ((stks->a->next->data == stks->sort[2]) && \
				(stks->a->next->next->data == stks->sort[3]))
		cmd_add(RRA, stks);
	else
	{
		cmd_add(PB, stks);
		ft_sort3(stks);
		cmd_add(PA, stks);
		if (stks->a->data != stks->sort[0])
			cmd_add(SA, stks);
	}
}

void	ft_sort_4_3(t_stacks *stks)
{
	if (stks->a->next->data == stks->sort[0] || \
			stks->a->next->data == stks->sort[1])
	{
		cmd_add(SA, stks);
		if (stks->a->next->next->data != stks->sort[3])
			cmd_add(RA, stks);
		else
			cmd_add(RRA, stks);
		if (stks->a->next->data != stks->sort[1] || \
			stks->a->next->next->data != stks->sort[2])
		{
			cmd_add(SA, stks);
			if (stks->a->next->next->data == stks->sort[3])
				cmd_add(RRA, stks);
			if (stks->a->data != stks->sort[0])
				cmd_add(SA, stks);
		}
	}
	else
	{
		cmd_add(RA, stks);
		cmd_add(RA, stks);
		if (stks->a->data == stks->sort[1])
			cmd_add(SA, stks);
	}
}

void	ft_sort_4_4(t_stacks *stks)
{
	if (stks->a->next->data == stks->sort[2])
	{
		cmd_add(SA, stks);
		cmd_add(RA, stks);
		cmd_add(RA, stks);
		if (stks->a->next->data == stks->sort[0])
			cmd_add(SA, stks);
		return ;
	}
	if (stks->a->next->data == stks->sort[1] && \
				stks->a->next->next->data == stks->sort[2])
		cmd_add(RRA, stks);
	else
		cmd_add(RA, stks);
	if (stks->a->next->data == stks->sort[0] || \
				stks->a->next->data == stks->sort[3])
		cmd_add(SA, stks);
	else if (stks->a->next->data == stks->sort[2])
	{
		cmd_add(RR, stks);
		cmd_add(SA, stks);
		cmd_add(RRA, stks);
	}
	if (stks->a->next->data == stks->sort[0])
		cmd_add(RA, stks);
}

void	ft_sort4(t_stacks *stks)
{
	if (stks->a->data == stks->sort[0])
		ft_sort_4_1(stks);
	else if (stks->a->data == stks->sort[1])
		ft_sort_4_2(stks);
	else if (stks->a->data == stks->sort[2])
		ft_sort_4_3(stks);
	else
		ft_sort_4_4(stks);
}
