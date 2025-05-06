/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratel <ratel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 20:10:16 by barmarti          #+#    #+#             */
/*   Updated: 2025/05/06 20:56:38 by ratel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	while (s[i])
	{
		if (s[i] == c)
			index = i + 1;
		i++;
	}
	if (index >= 1)
		return ((char *)&s[index - 1]);
	else if (c == 0)
		return ((char *)&s[i]);
	else
		return (NULL);
}
