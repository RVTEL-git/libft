/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 20:58:27 by barmarti          #+#    #+#             */
/*   Updated: 2025/04/28 21:03:50 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while(s[i])
	{
		if (s[i] == c)
			return((char *)&s[i]);
		i++;
	}
	if (c == 0)
		return((char *)&s[i]);
	else
		return(NULL);
}

void test_ft_strchr(const char *s, int c)
{
    char *real = strchr(s, c);
    char *mine = ft_strchr(s, c);

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
    test_ft_strchr("hello world", 'o');
    test_ft_strchr("hello world", 'h');
    test_ft_strchr("hello world", 'd');
    test_ft_strchr("hello world", '\0');
    test_ft_strchr("hello world", 'z');
    test_ft_strchr("", 'a');
    test_ft_strchr("test", 't');
    test_ft_strchr("banana", 'a');
    test_ft_strchr("banana", 'b');
    test_ft_strchr("banana", 'n');
    return 0;
}