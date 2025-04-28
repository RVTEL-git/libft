/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 20:10:19 by barmarti          #+#    #+#             */
/*   Updated: 2025/04/28 20:10:20 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned long	i;

	i = 0;
	while(i < n && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (i == n)
		i -= 1;
	return (s1[i] - s2[i]);
}
void	test_ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int real = strncmp(s1, s2, n);
	int mine = ft_strncmp(s1, s2, n);

	if ((real == 0 && mine == 0) || (real < 0 && mine < 0) || (real > 0 && mine > 0))
		printf("PASS : %s VS %s (n = %zu)\n", s1, s2, n);
	else
		printf("FAIL : \"%s\" vs \"%s\" (n = %zu) -> expected %d, got %d\n", s1, s2, n, real, mine);
}
int main(void)
{
    test_ft_strncmp("abc", "abc", 3);
    test_ft_strncmp("abc", "abd", 3);
	test_ft_strncmp("ab", "abc", 3);
    test_ft_strncmp("abcd", "ab", 2);
    test_ft_strncmp("", "", 1);
    test_ft_strncmp("a", "", 1);
    test_ft_strncmp("", "a", 1);
    test_ft_strncmp("abcdef", "abcxyz", 0);
    test_ft_strncmp("abcdef", "abcxyz", 3);
    test_ft_strncmp("abcdef", "abcxyz", 6);

    return 0;
}