/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: border <border@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 09:54:08 by border            #+#    #+#             */
/*   Updated: 2021/08/12 09:54:09 by border           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_stack_sorted(t_stacks *stks)
{
	t_stack	*p;

	p = stks->a;
	while (p && p->next)
	{
		if (p->next->data < p->data)
			return (FALSE);
		p = p->next;
	}
	return (TRUE);
}

void	ft_cmd_processing(char *line, t_stacks *s, t_list **lst)
{
	if (ft_strncmp(line, "sa", 3) == 0)
		ft_sa(s->a);
	else if (ft_strncmp(line, "sb", 3) == 0)
		ft_sb(s->b);
	else if (ft_strncmp(line, "ss", 3) == 0)
		ft_ss(s);
	else if (ft_strncmp(line, "pa", 3) == 0)
		ft_pa(s);
	else if (ft_strncmp(line, "pb", 3) == 0)
		ft_pb(s);
	else if (ft_strncmp(line, "ra", 3) == 0)
		ft_ra(&s->a);
	else if (ft_strncmp(line, "rb", 3) == 0)
		ft_rb(&s->b);
	else if (ft_strncmp(line, "rr", 3) == 0)
		ft_rr(s);
	else if (ft_strncmp(line, "rra", 4) == 0)
		ft_rra(&s->a);
	else if (ft_strncmp(line, "rrb", 4) == 0)
		ft_rrb(&s->b);
	else if (ft_strncmp(line, "rrr", 4) == 0)
		ft_rrr(s);
	else
		ft_error(1, lst);
}

void	ft_read_cmd(t_stacks *stks, t_list **lst)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line))
	{
		ft_cmd_processing(line, stks, lst);
		free(line);
		line = NULL;
	}
	if (line)
	{
		free(line);
		line = NULL;
	}
}

int	main(int argc, char **argv)
{
	t_all	*all;

	if (argc < 2)
		exit(1);
	all = (t_all *)ft_calloc(1, sizeof(t_all));
	if (!all)
		exit(1);
	ft_lstadd_back(&all->clear, ft_lstnew(all));
	if (!ft_is_valid_str(argv))
		ft_error(1, &all->clear);
	ft_arr_sep(argv, &all->new, all->clear);
	ft_dup_check(all);
	all->stks.a = ft_create_stack(all->new.a, all->new.len, all->clear);
	ft_read_cmd(&all->stks, &all->clear);
	if (ft_stack_sorted(&all->stks) && all->stks.b_len == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_error(0, &all->clear);
	return (0);
}
