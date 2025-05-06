/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 18:40:58 by barmarti          #+#    #+#             */
/*   Updated: 2025/05/06 14:09:36 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t elem_c, size_t elem_s)
{
	size_t			i;
	size_t			total;
	unsigned char	*dest;

	i = 0;
	if (elem_s != 0 && elem_c > elem_s / (size_t)-1)
		return (NULL);
	total = elem_c * elem_s;
	dest = (unsigned char *)malloc(total);
	if (!dest)
		return (NULL);
	while (i < total)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
