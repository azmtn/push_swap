/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: border <border@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 14:58:34 by border            #+#    #+#             */
/*   Updated: 2021/08/08 14:58:34 by border           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	return ((char *)malloc(sizeof(char) * (size + 1)));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	char	*r;
	size_t	len_s;

	if (s == 0)
		return (NULL);
	res = ft_strnew(len);
	if (res)
	{
		r = res;
		len_s = ft_strlen(s);
		while (len-- && start < len_s)
			*r++ = *(s + start++);
		*r = '\0';
	}
	return (res);
}
