/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 18:47:35 by barmarti          #+#    #+#             */
/*   Updated: 2025/05/06 14:12:23 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	word_count(char const *s, char c)
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

char	*fill_word(char const *s, unsigned int start, int end)
{
	int		i;
	int		len;
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

void	free_split(char **result)
{
	int	i;

	i = 0;
	if (!result)
		return ;
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

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**result;

	if (!s)
		return (NULL);
	count = word_count(s, c);
	result = (char **)malloc(sizeof(char *) * (count + 1));
	if (!result)
		return (NULL);
	fill_results((char *)s, c, result);
	return (result);
}
