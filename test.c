/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:13:12 by barmarti          #+#    #+#             */
/*   Updated: 2025/05/02 18:30:16 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	nbr;
	
	i = 0;
	sign = 1;
	nbr = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
			i++;
	if (nptr[i] == 45)
	{
		sign = -sign;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		nbr = nbr * 10 + (nptr[i] - 48);
		i++;
	}
	return(nbr*sign);
}

char	*ft_strnstr(const char *needle, const char *haystack, size_t len)
{
	size_t	i;
	size_t	j;

	if(needle[0] == '\0')
		return ((char *)haystack);
	
	j = 0;
	while (j < len && haystack[j])
	{
		i = 0;
		while (j < len && needle[i] == haystack[j] && needle[i])
		{
			i++;
			j++;
		}
		if (needle[i] == '\0')
			return ((char *)&haystack[j-i]);
		j = j - i + 1;
	}
	return (0);
}

int main(void)
{
	printf("max = %d\n", 2147483647);
	printf("min = %d\n", -2147483647);
    return (0);
}