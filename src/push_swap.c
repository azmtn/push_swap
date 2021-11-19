/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: border <border@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 09:55:20 by border            #+#    #+#             */
/*   Updated: 2021/08/12 09:55:22 by border           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_sort(t_stacks *stks, t_list *lst)
{
	if (stks->a_len <= 3)
		ft_sort3(stks);
	else if (stks->a_len == 4)
		ft_sort4(stks);
	else if (stks->a_len == 5)
		ft_sort5(stks);
	else
		ft_initial_sort(stks, lst);
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
	if (ft_is_sorted(&all->new))
	{
		all->stks.a = ft_create_stack(all->new.a, all->new.len, all->clear);
		ft_sort(&all->stks, all->clear);
	}
	cmd_add(0, &all->stks);
	ft_error(0, &all->clear);
	return (0);
}
