/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratel <ratel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:17:28 by ratel             #+#    #+#             */
/*   Updated: 2025/04/29 11:17:36 by ratel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return 1;
	else
		return 0;
}

void	main(int argc, char **argv)
{
	printf("%d\n", ft_isalpha(argv[1][0]));
	printf("%d\n", isalpha(argv[1][0]));
}
