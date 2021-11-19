/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: border <border@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 09:55:34 by border            #+#    #+#             */
/*   Updated: 2021/08/12 09:56:10 by border           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_all_countwords(char **s)
{
	int	w_count;

	w_count = 0;
	while (*s)
		w_count += ft_count_words((const char **)s++, ' ');
	return (w_count);
}

int	ft_atoi_i(const char *str, t_list *lst)
{
	long int	res;
	int			sign;

	res = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
		sign = 44 - *str++;
	if (ft_strlen(str) > 10)
		ft_error(1, &lst);
	while (ft_isdigit(*str))
		res = res * 10 + (*str++ - '0');
	if (res * sign > INT_MAX || res * sign < INT_MIN)
		ft_error(1, &lst);
	return ((int)(res * sign));
}

void	ft_arr_sep(char **argv, t_data *new, t_list *lst)
{
	int		i;
	int		j;
	char	**arr;

	new->len = ft_all_countwords(argv + 1);
	new->a = (int *) malloc(sizeof(int) * new->len);
	if (!new->a)
		ft_error(0, &lst);
	ft_lstadd_back(&lst, ft_lstnew(new->a));
	j = 0;
	while (*(++argv))
	{
		arr = ft_split(*argv, ' ');
		if (!arr)
			ft_error(0, &lst);
		i = -1;
		while (arr[++i] != NULL)
			new->a[j + i] = ft_atoi_i(arr[i], lst);
		ft_free_words(arr, i);
		j += i;
	}
}
