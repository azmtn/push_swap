/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_search.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: border <border@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 09:55:13 by border            #+#    #+#             */
/*   Updated: 2021/08/12 09:55:16 by border           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_help_finding_place(t_stacks *s, t_stack *b, int *action, int *buff)
{
	while (s->a)
	{
		*buff = s->a->data;
		if (b->data > s->a->data)
		{
			*action += 1;
			if (b->data < s->a->next->data)
				break ;
			s->a = s->a->next;
		}
		else
			break ;
	}
	if (ft_smaller_elm_detection(s->a, *buff, b->data) == 1)
	{
		while (s->a)
		{
			if (s->a->data < *buff && s->a->data > b->data)
				break ;
			*action += 1;
			s->a = s->a->next;
		}
	}
}

int	ft_place_search(t_stacks *s, t_stack *b, t_steps *steps, int min)
{
	int	action;
	int	res;
	int	buff;

	action = 0;
	buff = 0;
	ft_help_finding_place(s, b, &action, &buff);
	if (s->a->dir == -1)
		action = s->a_len - action;
	if (min == -1 || (action + b->step) < min)
	{
		steps->a_dest = s->a->dir;
		steps->b_dest = b->dir;
		steps->a_len = action;
		steps->b_len = b->step;
		res = action + b->step;
	}
	else
		res = min;
	return (res);
}

int	ft_smaller_elm_detection(t_stack *a, int buff, int src)
{
	t_stack	*save;
	int		ret;

	save = a;
	ret = 0;
	while (save && ret == 0)
	{
		if (save->data < buff && save->data > src)
			ret = 1;
		save = save->next;
	}
	return (ret);
}

int	ft_len_to_min(t_stack *a, int min)
{
	int	i;

	i = 0;
	while (a && a->data != min)
	{
		a = a->next;
		i++;
	}
	return (i);
}
