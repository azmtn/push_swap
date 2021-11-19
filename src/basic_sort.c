/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: border <border@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 09:53:51 by border            #+#    #+#             */
/*   Updated: 2021/08/12 09:54:01 by border           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_basic_sort(t_stacks *stks, t_list *lst)
{
	t_steps	*step;

	step = (t_steps *)malloc(sizeof(t_steps));
	if (!step)
		ft_error(0, &lst);
	while (stks->b_len != 0)
	{
		step->a_len = -1;
		step->b_len = -1;
		step->a_dest = 0;
		step->b_dest = 0;
		ft_steps_markup(stks->a, stks->a_len);
		ft_steps_markup(stks->b, stks->b_len);
		ft_min_insertion_steps(stks, step);
		ft_spec(stks, step);
	}
	if ((ft_len_to_min(stks->a, stks->min)) > stks->a_len / 2)
		while (stks->a->data != stks->min)
			cmd_add(RRA, stks);
	else
		while (stks->a->data != stks->min)
			cmd_add(RA, stks);
	free(step);
}

void	ft_steps_markup(t_stack *b, int len)
{
	int		i;
	int		iter;
	t_stack	*buff;

	i = -1;
	iter = len / 2;
	buff = b;
	while (++i <= iter)
	{
		buff->step = i;
		buff->dir = 1;
		buff = buff->next;
	}
	if (len % 2 == 0)
		i--;
	while (--i > 0)
	{
		buff->step = i;
		buff->dir = -1;
		buff = buff->next;
	}
}

void	ft_min_insertion_steps(t_stacks *stks, t_steps *steps)
{
	int		min_action;
	t_stack	*first_a;
	t_stack	*first_b;

	min_action = -1;
	first_a = stks->a;
	first_b = stks->b;
	while (stks->b)
	{
		min_action = ft_place_search(stks, stks->b, steps, min_action);
		stks->a = first_a;
		stks->b = stks->b->next;
	}
	stks->b = first_b;
}

void	ft_spec_dop(t_stacks *stks, t_steps *steps)
{
	while (steps->a_len > 0)
	{
		if (steps->a_dest == 1)
			cmd_add(RA, stks);
		else
			cmd_add(RRA, stks);
		steps->a_len--;
	}
	while (steps->b_len > 0)
	{
		if (steps->b_dest == 1)
			cmd_add(RB, stks);
		else
			cmd_add(RRB, stks);
		steps->b_len--;
	}
}

void	ft_spec(t_stacks *stks, t_steps *steps)
{
	while (steps->a_len > 0 && steps->b_len > 0 && \
			steps->a_dest == steps->b_dest)
	{
		if (steps->a_dest == 1)
			cmd_add(RR, stks);
		else
			cmd_add(RRR, stks);
		steps->a_len--;
		steps->b_len--;
	}
	ft_spec_dop(stks, steps);
	cmd_add(PA, stks);
}
