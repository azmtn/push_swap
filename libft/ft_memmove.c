/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: border <border@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 14:56:57 by border            #+#    #+#             */
/*   Updated: 2021/08/08 14:56:58 by border           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (!(len == 0 || d == s))
	{
		if (d < s)
		{
			while (len-- != 0)
				*d++ = *s++;
		}
		else
		{
			d += len;
			s += len;
			while (len-- != 0)
				*--d = *--s;
		}
	}
	return (dst);
}
