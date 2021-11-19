/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: border <border@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 14:57:01 by border            #+#    #+#             */
/*   Updated: 2021/08/08 14:57:02 by border           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*dst;
	unsigned char	uc;

	dst = (unsigned char *)s;
	uc = (unsigned char)c;
	while (n-- != 0)
		*dst++ = uc;
	return (s);
}
