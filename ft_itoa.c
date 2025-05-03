/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 17:22:50 by barmarti          #+#    #+#             */
/*   Updated: 2025/05/03 17:43:41 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

char *ft_strdup(char *src)
{
	char	*dup;
	int	i;

	i = 0;
	dup = (char *)malloc(ft_strlen(src) * sizeof(char) + 1);
	while(src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int	get_baselen(int	n)
{
	int	base_len;

	base_len = 0;
	if (n <= 0)
	{
		base_len++;
		n = - n;
	}
	while (n > 0)
	{
		n = n / 10;
		base_len++;
	}
	return(base_len);
}

char	*ft_itoa(int n)
{
	char *result;
	int	base_len;

	if (n == -2147483648)
		return(ft_strdup("-2147483648"));
	base_len = get_baselen(n);
	result = (char *)malloc(sizeof(char) * (base_len + 1));
	if (!result)
		return(NULL);
	result[base_len] = '\0';
	if (n < 0)
	{
		result[0] = '-';
		n = - n;
	}
	if (n == 0)
		return(ft_strdup("0"));
	while (n > 0)
	{
		result[base_len - 1] = (n % 10) + 48;
		n = n / 10;
		base_len--;
	}
	return (result);
}

int	main()
{
	printf("============================\n");
	printf("%s\n", ft_itoa(0));
	printf("============================\n");
	printf("%s\n", ft_itoa(645));
	printf("============================\n");
	printf("%s\n", ft_itoa(-1610));
	printf("============================\n");
	printf("%s\n", ft_itoa(-0));
	printf("============================\n");
	printf("%s\n", ft_itoa(+4560));
	printf("============================\n");
	printf("%s\n", ft_itoa(+0));
	printf("============================\n");
	printf("%s\n", ft_itoa(2147483647));
	printf("============================\n");
	printf("%s\n", ft_itoa(-2147483648));
	printf("============================\n");
	printf("%s\n", ft_itoa(-6));
	printf("============================\n");
	printf("%s\n", ft_itoa(-2147483648));
	printf("FIN\n");

	return (0);
}