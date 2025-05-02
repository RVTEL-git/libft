/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 20:42:21 by rvtel             #+#    #+#             */
/*   Updated: 2025/04/29 18:32:28 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*strnstr(const char *needle, const char *haystack, size_t len)
{
	size_t	i;
	size_t	j;

	if(needle[0] == '\0')
		return (haystack);
	
	j = 0;
	while (j < len && haystack[j])
	{
		i = 0;
		while (j < len && needle[i] == haystack[j] && needle[i])
		{
			i++;
			j++;
		}
		if (needle[i] == '\0')
			return ((char *)&haystack[j-i]);
		j = j - i + 1;
	}
	return (0);
}