/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratel <ratel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:17:24 by ratel             #+#    #+#             */
/*   Updated: 2025/04/29 11:17:25 by ratel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int ft_isalnum(int c)
{
	if((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return 1;
	else
		return 0;
}

void main(int argc, char **argv)
{
	printf("%d\n", ft_isalnum(argv[1][0]));
	printf("%d\n", isalnum(argv[1][0]));
}
