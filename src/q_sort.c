/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: border <border@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 09:55:27 by border            #+#    #+#             */
/*   Updated: 2021/08/12 09:55:28 by border           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_quick_sort(int *arr, int start, int end)
{
	int	q;

	if (start < end)
	{
		q = ft_partition(arr, start, end);
		ft_quick_sort(arr, start, q - 1);
		ft_quick_sort(arr, q + 1, end);
	}
}

int	ft_partition(int *arr, int start, int end)
{
	int	tmp;
	int	p;
	int	i;
	int	j;

	p = arr[end];
	i = start - 1;
	j = start;
	while (j < end)
	{
		if (arr[j] <= p)
		{
			i++;
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}
		j++;
	}
	tmp = arr[i + 1];
	arr[i + 1] = arr[end];
	arr[end] = tmp;
	return (i + 1);
}
