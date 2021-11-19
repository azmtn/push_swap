/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: border <border@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 14:57:47 by border            #+#    #+#             */
/*   Updated: 2021/08/08 14:57:48 by border           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	char	*r;

	if (s1 == 0 || s2 == 0)
		return (NULL);
	res = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (res)
	{
		r = res;
		while (*s1)
			*r++ = *s1++;
		while (*s2)
			*r++ = *s2++;
		*r = '\0';
	}
	return (res);
}
