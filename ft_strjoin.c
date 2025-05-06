/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratel <ratel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:22:16 by barmarti          #+#    #+#             */
/*   Updated: 2025/05/06 20:51:11 by ratel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s);

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t			s1_len;
	size_t			s2_len;
	unsigned int	i;
	char			*join;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	i = 0;
	join = (char *)malloc(sizeof(char) * (s1_len + s2_len) + 1);
	while (s1[i++])
		join[i] = s1[i];
	i = 0;
	while (i < s2_len)
	{
		join[s1_len] = s2[i];
		s1_len++;
		i++;
	}
	join[s1_len + s2_len] = '\0';
	return (join);
}
