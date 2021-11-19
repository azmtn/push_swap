/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: border <border@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 14:57:38 by border            #+#    #+#             */
/*   Updated: 2021/08/08 14:57:38 by border           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*p;
	char	ch;

	p = (char *)s;
	ch = (char)c;
	while (1)
	{
		if (*p == ch)
			return (p);
		if (*p++ == 0)
			return (NULL);
	}
}
