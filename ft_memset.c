/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:32:23 by barmarti          #+#    #+#             */
/*   Updated: 2025/04/29 18:32:24 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void *ft_memset(void *p, int value, size_t len)
{
	unsigned char *u = p;

	while(len > 0)
	{
		*u = value;
		u++;
		len--;
	}
	return(p);
}

int main()
{
	char buffer1[10] = "abcdefghi";
	char buffer2[10] = "abcdefghi";
	int array1[] = { 10, 55, 9, 17, 100};
	int array2[] = { 10, 55, 9, 17, 100};
	int i = 0;
	size_t size = sizeof(int) * 5;

	printf("-Mine-\n");
	printf("buffer1 avant  : %s\n", buffer1);
	while(i < 5)
	{
		printf("array1[%d] avant  : %d\n", i, array1[i]);
		i++;
	}
	i = 0;
	ft_memset(buffer1, 'X', 5);
	ft_memset(array1, 22, size);
	printf("buffer1 après  : %s\n", buffer1);
	while(i < 5)
	{
		printf("array1[%d] après  : %d\n", i, array1[i]);
		i++;
	}
	i = 0;
	printf("-C one-\n");
	printf("buffer2 avant  : %s\n", buffer2);	
	while(i < 5)
	{
		printf("array2[%d] avant : %d\n", i, array2[i]);
		i++;
	}
	memset(buffer2, 'X', 5);
	memset(array2, 22, size);
	i = 0;
	printf("buffer2 après  : %s\n", buffer2);
	while(i < 5)
	{
		printf("array2[%d] après  : %d\n", i, array2[i]);
		i++;
	}

    return 0;
}
