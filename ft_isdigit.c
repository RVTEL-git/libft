/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:32:14 by barmarti          #+#    #+#             */
/*   Updated: 2025/04/29 18:32:15 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return 1;
	else
		return 0;
}

void main(int argc, char **argv)
{
	printf("%d\n", ft_isdigit(argv[1][0]));
	printf("%d\n", isdigit(argv[1][0]));
}
