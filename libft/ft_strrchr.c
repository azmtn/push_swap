/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: border <border@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 14:58:24 by border            #+#    #+#             */
/*   Updated: 2021/08/08 14:58:25 by border           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;
	char	uc;

	p = (char *)s + ft_strlen(s);
	uc = (char)c;
	while (p >= s && *p != uc)
		p--;
	if (p >= s)
		return (p);
	return (NULL);
}
