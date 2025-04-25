/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:13:12 by barmarti          #+#    #+#             */
/*   Updated: 2025/04/25 17:19:30 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	nbr;
	
	i = 0;
	sign = 1;
	nbr = 0;
	while (nptr[i] >= 9 && nptr[i] <= 13 || nptr[i] == 32)
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

int	main(int ac, char **av)
{
	printf("atoi = %d\n",atoi(av[1]));
	printf("ft_atoi = %d\n",ft_atoi(av[1]));
	return (0);
}