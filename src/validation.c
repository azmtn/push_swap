/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: border <border@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 09:55:55 by border            #+#    #+#             */
/*   Updated: 2021/08/12 09:55:57 by border           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_is_valid_str(char **argv)
{
	int	is_valid;

	is_valid = TRUE;
	while (*(++argv) && is_valid)
	{
		if (ft_only_spaces(*argv))
			is_valid = (ft_num_avail(*argv) && ft_str_valid(*argv));
	}
	return (is_valid);
}

int	ft_num_avail(const char *str)
{
	while (*str)
	{
		if (ft_isdigit(*str))
			return (TRUE);
		str++;
	}
	return (FALSE);
}

int	ft_str_valid(char *str)
{
	int		num;
	int		sign;

	num = 0;
	sign = 0;
	while (*str)
	{
		if (ft_isdigit(*str))
			num++;
		else if (ft_isspace(*str))
		{
			*str = ' ';
			if (sign != 0 && num == 0)
				return (FALSE);
			sign = 0;
			num = 0;
		}
		else if (((*str == '+' || *str == '-') && \
					(sign == 0 && num == 0)) && *(str + 1))
			sign++;
		else
			return (FALSE);
		str++;
	}
	return (TRUE);
}

void	ft_arr_dup_search(const int *dup, int len, t_list *lst)
{
	while (len--)
	{
		if (*dup == *(dup + 1))
			ft_error(1, &lst);
		dup++;
	}
}

void	ft_dup_check(t_all *all)
{
	int			*p;

	p = (int *)malloc(sizeof(int) * (all->new.len));
	if (!p)
		ft_error(0, &all->clear);
	ft_lstadd_back(&all->clear, ft_lstnew(p));
	p = ft_memcpy(p, all->new.a, sizeof(int) * all->new.len);
	ft_quick_sort(p, 0, all->new.len - 1);
	ft_arr_dup_search(p, all->new.len - 1, all->clear);
	all->stks.a_len = all->new.len;
	all->stks.b_len = 0;
	all->stks.min = p[0];
	all->stks.mid = p[all->new.len / 2];
	all->stks.max = p[all->new.len - 1];
	all->stks.sort = p;
}
