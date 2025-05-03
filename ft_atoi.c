/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:08:18 by barmarti          #+#    #+#             */
/*   Updated: 2025/05/03 18:37:31 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <libft.h>

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
		sign = sign * -1;
	while (nptr[i] >= 49 && nptr[i] <= 57)
	{
		nbr = nbr * 10 + (nptr[i] - 49);
		i++;
	}
	return (nbr);
}
