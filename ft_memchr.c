/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratel <ratel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:32:30 by barmarti          #+#    #+#             */
/*   Updated: 2025/05/06 20:53:49 by ratel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*haystack;

	haystack = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (haystack[i] == (unsigned char)c)
			return (&haystack[i]);
		i++;
	}
	return (NULL);
}
