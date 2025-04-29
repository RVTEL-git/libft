/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratel <ratel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:17:20 by ratel             #+#    #+#             */
/*   Updated: 2025/04/29 11:17:22 by ratel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>
#include <stdio.h>

void ft_bzero(void *s, size_t n)
{
	unsigned char *u = s;

	while(n > 0)
	{
		*u = '\0';
		u++;
		n--;
	}
}

int	main(void)
{
	char	buffer1[10] = "abcdefghi";
	char	buffer2[10] = "abcdefghi";
	int i = 0;

	printf("Avant ft_bzero : %s\n", buffer1);
	ft_bzero(buffer1 + 3, 4);
	printf("Après ft_bzero : ");
	while(i < 10)
	{
		if (buffer1[i] == '\0')
		{
			printf("\\0");
			i++;
		}
		else
		{
			printf("%c", buffer1[i]);
			i++;
		}
	}
	printf("\n");
	i = 0;
	printf("Avant bzero : %s\n", buffer2);
	bzero(buffer2 + 3, 4);
	printf("Après bzero : ");
	while(i < 10)
	{
		if (buffer2[i] == '\0')
		{
			printf("\\0");
			i++;
		}
		else
		{
			printf("%c", buffer2[i]);
			i++;
		}
	}
	printf("\n");

	return 0;
}
