/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:32:47 by barmarti          #+#    #+#             */
/*   Updated: 2025/04/29 19:35:35 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsd/string.h>
#include <stdio.h>

size_t ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		if (i < n)
			dst[i] = src[i];
		else if (i == n && n > 0)
			dst[i] = '\0';
		i++;
	}
	return (i);
}

void	test_ft_strlcpy(char *dst, const char *src, size_t n)
{
    size_t	mine;
    size_t	real;

    mine = ft_strlcpy(dst, src, n);
    real = strlcpy(dst, src, n);
    if (mine == real)
        printf("Pass !\n");
    else
        printf("FAIL ! expected : %zu | you have : %zu\n", real, mine);
}

int	main(void)
{
    char dst[10];

    test_ft_strlcpy(dst, "world", 4);
    test_ft_strlcpy(dst, "wor", 3);
    test_ft_strlcpy(dst, "", 0);
    test_ft_strlcpy(dst, "world", 0);
    test_ft_strlcpy(dst, "world", 2);
    test_ft_strlcpy(dst, "", 4);
    return (0);
}