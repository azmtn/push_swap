/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: border <border@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 14:57:43 by border            #+#    #+#             */
/*   Updated: 2021/08/08 14:57:44 by border           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	size;
	char	*copy;

	size = ft_strlen(s1) + 1;
	copy = (char *)ft_calloc(size, sizeof(char));
	if (copy)
		ft_memcpy(copy, s1, size);
	return (copy);
}
