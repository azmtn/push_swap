/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: border <border@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 09:54:21 by border            #+#    #+#             */
/*   Updated: 2021/08/12 09:54:23 by border           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_sa(t_stack *a)
{
	int		buff;

	if (a == NULL || a->next == NULL)
		return ;
	buff = a->data;
	a->data = a->next->data;
	a->next->data = buff;
}

void	ft_sb(t_stack *b)
{
	int		buff;

	if (b == NULL || b->next == NULL)
		return ;
	buff = b->data;
	b->data = b->next->data;
	b->next->data = buff;
}

void	ft_ss(t_stacks *s)
{
	ft_sa(s->a);
	ft_sb(s->b);
}

void	ft_pa(t_stacks *s)
{
	t_stack	*buff;

	if (s->b == NULL)
		return ;
	s->a_len += 1;
	s->b_len -= 1;
	buff = s->b;
	s->b = s->b->next;
	buff->next = s->a;
	s->a = buff;
}

void	ft_pb(t_stacks *s)
{
	t_stack	*buff;

	if (s->a == NULL)
		return ;
	s->a_len -= 1;
	s->b_len += 1;
	buff = s->a;
	s->a = s->a->next;
	buff->next = s->b;
	s->b = buff;
}
