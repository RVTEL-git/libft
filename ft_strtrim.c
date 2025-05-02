/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:41:57 by barmarti          #+#    #+#             */
/*   Updated: 2025/05/01 19:03:48 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	ft_strlen(char const *str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

char *ft_strdup(char const *src, int start, int end)
{
	char	*dup;
	int	i;

	i = 0;
	if (end < 0)
		end = start +1;
	dup = (char *)malloc(((end - start) * sizeof(char)) + 1);
	if (!dup)
		return (NULL);
	while(start <= end)
	{
		dup[i] = src[start];
		i++;
		start++;
	}
	dup[i] = '\0';
	return (dup);
}

int	is_set(char	c, char const	*set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char *ft_strtrim(char const *s1, char const *set)
{
	int	index_strt;
	int	index_end;
	char	*trim;

	if (!s1)
		return (NULL);
	if (!set)
	{
		trim = ft_strdup(s1, 0, (ft_strlen(s1)));
		return (trim);
	}
	index_end = ft_strlen(s1) - 1;
	index_strt = 0;
	while (s1[index_strt] && is_set(s1[index_strt], set))
		index_strt++;
	while (index_end >= 0 && is_set(s1[index_end], set))
		index_end--;
	trim = ft_strdup(s1, index_strt, index_end);
	return (trim);
}

int main(void)
{
    // Jeu de caractères varié
    const char *set = " \n\t\r\v\f";

    // Test 1 : Trim sur chaîne avec caractères invisibles variés
    const char *input1 = "\t\n  Hello World \r\n";
    const char *expected1 = "Hello World";
    char *result1 = ft_strtrim(input1, set);
    if (result1 && strcmp(result1, expected1) == 0)
        printf("Test 1 OK\n");
    else
        printf("Test 1 ÉCHEC: attendu \"%s\", obtenu \"%s\"\n", expected1, result1);
    free(result1);

    // Test 2 : La chaîne ne contient que des caractères à retirer
    const char *input2 = "\n\t\r";
    const char *expected2 = "";
    char *result2 = ft_strtrim(input2, set);
    if (result2 && strcmp(result2, expected2) == 0)
        printf("Test 2 OK\n");
    else
        printf("Test 2 ÉCHEC: attendu \"%s\", obtenu \"%s\"\n", expected2, result2);
    free(result2);

    // Test 3 : Aucun caractère à retirer
    const char *input3 = "Texte intact";
    const char *expected3 = "Texte intact";
    char *result3 = ft_strtrim(input3, set);
    if (result3 && strcmp(result3, expected3) == 0)
        printf("Test 3 OK\n");
    else
        printf("Test 3 ÉCHEC: attendu \"%s\", obtenu \"%s\"\n", expected3, result3);
    free(result3);

    // Test 4 : Caractères à l’intérieur non retirés
    const char *input4 = "   abc   def   ";
    const char *expected4 = "abc   def";
    char *result4 = ft_strtrim(input4, set);
    if (result4 && strcmp(result4, expected4) == 0)
        printf("Test 4 OK\n");
    else
        printf("Test 4 ÉCHEC: attendu \"%s\", obtenu \"%s\"\n", expected4, result4);
    free(result4);

    // Test 5 : Chaîne vide en entrée
    const char *input5 = "";
    const char *expected5 = "";
    char *result5 = ft_strtrim(input5, set);
    if (result5 && strcmp(result5, expected5) == 0)
        printf("Test 5 OK\n");
    else
        printf("Test 5 ÉCHEC: attendu \"%s\", obtenu \"%s\"\n", expected5, result5);
    free(result5);

    // Test 6 : Trim de symboles (ex: '*', '#')
    const char *input6 = "***bonjour***";
    const char *expected6 = "bonjour";
    char *result6 = ft_strtrim(input6, "*");
    if (result6 && strcmp(result6, expected6) == 0)
        printf("Test 6 OK\n");
    else
        printf("Test 6 ÉCHEC: attendu \"%s\", obtenu \"%s\"\n", expected6, result6);
    free(result6);

    // Test 7 : `set` vide → rien ne doit être retiré
    const char *input7 = "   test  ";
    const char *expected7 = "   test  ";
    char *result7 = ft_strtrim(input7, "");
    if (result7 && strcmp(result7, expected7) == 0)
        printf("Test 7 OK\n");
    else
        printf("Test 7 ÉCHEC: attendu \"%s\", obtenu \"%s\"\n", expected7, result7);
    free(result7);

    // Test 8 : `s1` est NULL (comportement non défini, mais à tester si tu gères le cas)
    char *result8 = ft_strtrim(NULL, set);
    if (result8 == NULL)
        printf("Test 8 OK (NULL correctement géré)\n");
    else
        printf("Test 8 ÉCHEC: attendu NULL, obtenu \"%s\"\n", result8);
    free(result8);

    // Test 9 : `set` est NULL (à gérer selon ton choix, ici on suppose que ça renvoie une copie)
    const char *input9 = "   hello  ";
    const char *expected9 = "   hello  ";
    char *result9 = ft_strtrim(input9, NULL);
    if (result9 && strcmp(result9, expected9) == 0)
        printf("Test 9 OK (set NULL => pas de trim)\n");
    else
        printf("Test 9 ÉCHEC: attendu \"%s\", obtenu \"%s\"\n", expected9, result9);
    free(result9);

    return 0;
}
