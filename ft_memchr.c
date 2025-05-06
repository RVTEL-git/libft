/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:32:30 by barmarti          #+#    #+#             */
/*   Updated: 2025/05/06 14:11:24 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned long	i;
	unsigned char	*haystack;
	unsigned char	*find;

	haystack = (unsigned char *)s;
	i = 0;
	while (i < n && haystack[i])
	{
		if (haystack[i] == c)
			return (find = &haystack[i]);
		i++;
	}
	return (0);
}
