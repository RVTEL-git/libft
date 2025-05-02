/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:17:05 by ratel             #+#    #+#             */
/*   Updated: 2025/04/29 18:32:21 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void *ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_b;
	const unsigned char	*src_b;
	size_t	i;

	dest_b = (unsigned char	*)dest;
	src_b = (const unsigned char	*)src;
	if (dest_b <= src_b)
	{
		i = 0;
		while (i < n)
		{
			dest_b[i] = src_b[i];
			i++;
		}
	}
	else if (dest_b > src_b)
	{
		i = n;
		while (i > 0)
		{
			i--;
			dest_b[i] = src_b[i];
		}	
	}
	return (dest);
}
int main()
{
	int	source[7] = {0, 1, 2, 3, 4, 5, 6};
	int	destination[7];
	int i = 0;
	
	memmove(destination, source, sizeof(int) *7);
	while(i < 7)
	{
		printf("destination[%d] = %d\n", i, destination[i]);
		i++;
	}
	i = 0;
	while(i < 7)
	{
		printf("source[%d] = %d\n", i, source[i]);
		i++;
	}
	return 0;
}
