/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratel <ratel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:41:57 by barmarti          #+#    #+#             */
/*   Updated: 2025/05/06 20:56:28 by ratel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s);

char	*ft_dup(char const *src, int start, int end)
{
	char	*dup;
	int		i;

	i = 0;
	if (end < 0)
		end = start +1;
	dup = (char *)malloc(((end - start) * sizeof(char)) + 1);
	if (!dup)
		return (NULL);
	while (start <= end)
	{
		dup[i] = src[start];
		i++;
		start++;
	}
	dup[i] = '\0';
	return (dup);
}

int	is_set(char c, char const *set)
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

char	*ft_strtrim(char const *s1, char const *set)
{
	int		index_strt;
	int		index_end;
	char	*trim;

	if (!s1)
		return (NULL);
	if (!set)
	{
		trim = ft_dup(s1, 0, (ft_strlen(s1)));
		return (trim);
	}
	index_end = ft_strlen(s1) - 1;
	index_strt = 0;
	while (s1[index_strt] && is_set(s1[index_strt], set))
		index_strt++;
	while (index_end >= 0 && is_set(s1[index_end], set))
		index_end--;
	trim = ft_dup(s1, index_strt, index_end);
	return (trim);
}
