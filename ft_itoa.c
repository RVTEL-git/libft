/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 17:22:50 by barmarti          #+#    #+#             */
/*   Updated: 2025/05/02 19:13:31 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	get_baselen(int	n)
{
	int	base_len;

	base_len = 0;
	while (n > 0)
	{
		n = n / 10;
		base_len++;
	}

	return(base_len);
}
int	get_sign(int n)
{
	int	sign;

	sign = 1;
	if	(n < 0)
	{
		n = n * -1;
		sign = sign * -1;
	}
	return (sign);
}
char	*get_number(char *result, int base_len, int	i, int	n)
{
	while (i < base_len)
	{
		result[i] = (n % 10)+ 48;
		n = n / 10;
		i++;
	}
	result[i] = '\0';
	return (result);
}
char	*ft_itoa(int n)
{
	char *result;
	int	base_len;
	int	sign;
	int	i;

	sign = get_sign(n);
	i = 0;
	base_len = get_baselen(n);
	if (!base_len)
		return (NULL);
	result = (char *)malloc(sizeof(char) * (base_len + 1));
	if (!result)
		return(NULL);
	if (sign < 0)
	{
		result[i] = '-';
		i++;
	}
	get_number(result, base_len, i, n);
	return (result);
}

int	main()
{
	printf("%s", ft_itoa(424212));
	return (0);
}