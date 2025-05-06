/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratel <ratel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 17:22:50 by barmarti          #+#    #+#             */
/*   Updated: 2025/05/06 18:43:59 by ratel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src);

int	get_baselen(int n)
{
	int	base_len;

	base_len = 0;
	if (n <= 0)
	{
		base_len++;
		n = -n;
	}
	while (n > 0)
	{
		n = n / 10;
		base_len++;
	}
	return (base_len);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		base_len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	base_len = get_baselen(n);
	result = (char *)malloc(sizeof(char) * (base_len + 1));
	if (!result)
		return (NULL);
	result[base_len] = '\0';
	if (n < 0)
	{
		result[0] = '-';
		n = -n;
	}
	if (n == 0)
		return (ft_strdup("0"));
	while (n > 0)
	{
		result[base_len - 1] = (n % 10) + 48;
		n = n / 10;
		base_len--;
	}
	return (result);
}
