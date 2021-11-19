/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: border <border@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 14:56:39 by border            #+#    #+#             */
/*   Updated: 2021/08/08 14:56:40 by border           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;
	unsigned char		uc;

	p = (unsigned char *)s;
	uc = (unsigned char)c;
	while (n-- != 0)
	{
		if (*p++ == uc)
			return ((void *)(p - 1));
	}
	return (0);
}
