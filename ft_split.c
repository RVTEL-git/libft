/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 18:47:35 by barmarti          #+#    #+#             */
/*   Updated: 2025/05/02 17:20:49 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int word_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
			return (count);
}

char *fill_word(char const	*s, unsigned int	start, int	end)
{
	int	i;
	int	len;
	char	*sub;

	i = 0;
	len = end - start;
	if (s == NULL)
		return (NULL);
	sub = (char *)malloc(sizeof(char) * len + 1);
	if (!sub)
		return (NULL);
	while (i < len)
	{
		sub[i] = s[start];
		i++;
		start++;
	}
	sub[i] = '\0';
	return (sub);
}
void free_split(char **result)
{
	int	i;

	i = 0;
	if (!result) 
		return;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
}
char	**fill_results(char *s, char c, char **result)
{
	int	i;
	int	start;
	int	word_index;

	word_index = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			start = i;
			while (s[i] != c && s[i])
				i++;
			result[word_index] = fill_word(s, start, i);
			if (!result[word_index])
				free_split(result);
			word_index++;
		}
	}
	result[word_index] = NULL;
	return (result);
}
char **ft_split(char const *s, char c)
{
	if (!s)
		return (NULL);
	int	count;
	char	**result;

	
	count = word_count(s, c);
	result = (char**)malloc(sizeof(char *) * (count + 1));
	if (!result)
		return (NULL);
	fill_results((char *)s, c, result);
	return (result);
}

// Fonction de vérification
int check_split(char **result, const char **expected)
{
    if (!result || !expected)
        return result == expected;
    for (int i = 0; expected[i]; i++) {
        if (!result[i] || strcmp(result[i], expected[i]) != 0)
            return 0;
    }
    return result[0] == NULL || result[1] == NULL || result[2] == NULL || result[3] == NULL;
}

int main(void)
{
    // Test 1 : Séparation simple
    char **res1 = ft_split("bonjour les amis", ' ');
    const char *exp1[] = {"bonjour", "les", "amis", NULL};
    printf("Test 1 : %s\n", check_split(res1, exp1) ? "OK" : "ÉCHEC");
    free_split(res1);

    // Test 2 : Séparateur en début et fin
    char **res2 = ft_split("  test  ", ' ');
    const char *exp2[] = {"test", NULL};
    printf("Test 2 : %s\n", check_split(res2, exp2) ? "OK" : "ÉCHEC");
    free_split(res2);

    // Test 3 : Séparateur consécutif
    char **res3 = ft_split("a--b--c", '-');
    const char *exp3[] = {"a", "b", "c", NULL};
    printf("Test 3 : %s\n", check_split(res3, exp3) ? "OK" : "ÉCHEC");
    free_split(res3);

    // Test 4 : Chaîne vide
    char **res4 = ft_split("", ',');
    const char *exp4[] = {NULL};
    printf("Test 4 : %s\n", check_split(res4, exp4) ? "OK" : "ÉCHEC");
    free_split(res4);

    // Test 5 : Pas de séparateur
    char **res5 = ft_split("uniquestring", ',');
    const char *exp5[] = {"uniquestring", NULL};
    printf("Test 5 : %s\n", check_split(res5, exp5) ? "OK" : "ÉCHEC");
    free_split(res5);

    // Test 6 : Tout est séparateur
    char **res6 = ft_split(",,,,,", ',');
    const char *exp6[] = {NULL};
    printf("Test 6 : %s\n", check_split(res6, exp6) ? "OK" : "ÉCHEC");
    free_split(res6);

    // Test 7 : NULL en paramètre
    char **res7 = ft_split(NULL, ',');
    if (!res7)
        printf("Test 7 : OK\n");
    else {
        printf("Test 7 : ÉCHEC\n");
        free_split(res7);
    }

    return 0;
}