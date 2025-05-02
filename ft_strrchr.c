/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 20:10:16 by barmarti          #+#    #+#             */
/*   Updated: 2025/04/28 20:59:46 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	while(s[i])
	{
		if (s[i] == c)
			index = i + 1;
		i++;
	}
	if (index >= 1)
		return((char *)&s[index-1]);
	else if (c == 0)
		return((char *)&s[i]);
	else
		return(NULL);
}

void test_ft_strrchr(const char *s, int c)
{
    char *real = strrchr(s, c);
    char *mine = ft_strrchr(s, c);

    if (real == NULL && mine == NULL)
        printf("OK : \"%s\" find '%c'\n", s, c);
    else if (real != NULL && mine != NULL && strcmp(real, mine) == 0)
        printf("OK : \"%s\" find '%c'\n", s, c);
    else
        printf("FAIL : \"%s\" find '%c' -> expected \"%s\", got \"%s\"\n",
               s, c, real ? real : "NULL", mine ? mine : "NULL");
}

int main(void)
{
    test_ft_strrchr("hello world", 'o');
    test_ft_strrchr("hello world", 'h');
    test_ft_strrchr("hello world", 'd');
    test_ft_strrchr("hello world", '\0');
    test_ft_strrchr("hello world", 'z');
    test_ft_strrchr("", 'a');
    test_ft_strrchr("test", 't');
    test_ft_strrchr("banana", 'a');
    test_ft_strrchr("banana", 'b');
    test_ft_strrchr("banana", 'n');
    return 0;
}
