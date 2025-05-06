/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratel <ratel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:32:18 by barmarti          #+#    #+#             */
/*   Updated: 2025/05/06 18:52:48 by ratel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t size)
{
	size_t				i;
	unsigned char		*dest;
	const unsigned char	*src;

	i = 0;
	dest = (unsigned char *)destination;
	src = (const unsigned char *)source;
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
	return (destination);
}
