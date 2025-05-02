/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 19:40:08 by barmarti          #+#    #+#             */
/*   Updated: 2025/05/01 15:33:48 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsd/string.h>
#include <stdio.h>

size_t	ft_strlcat(char  *dest, const char *src, size_t n)
{
	size_t dest_len;
	size_t	src_len;
	size_t i;

	dest_len = 0;
	src_len = 0;
	while (dest[dest_len])
		dest_len++;
	while (src[src_len])
		src_len++;
	if(dest_len > n)
		return (dest_len + 1);
	i = 0;
	while (src[i] && dest_len + i < (n - 1))
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}

void	test_ft_strlcat(char *dest, const char *src, size_t n)
{
    char    dest_copy[50];
    size_t  mine;
    size_t  real;

    // Copy the destination buffer to compare results
    strncpy(dest_copy, dest, sizeof(dest_copy));
	
 // Test standard strlcat
    real = strlcat(dest_copy, src, n);

    // Test ft_strlcat
    mine = ft_strlcat(dest, src, n);

   
    // Print results
    if (mine == real && strcmp(dest, dest_copy) == 0)
        printf("Pass: dest=\"%s\", src=\"%s\", n=%zu\n", dest, src, n);
    else
    {
        printf("FAIL: dest=\"%s\", src=\"%s\", n=%zu\n", dest, src, n);
        printf("Expected: \"%s\" (return=%zu), Got: \"%s\" (return=%zu)\n",
               dest_copy, real, dest, mine);
    }
}

int	main(void)
{
    char dest[50];
	
     // Test cases
	strcpy(dest, "Hello");
    test_ft_strlcat(dest, " world", 11); 
 
    strcpy(dest, "Hello");
    test_ft_strlcat(dest, " world", 6);

    strcpy(dest, "Hello");
    test_ft_strlcat(dest, " world", 0);

    strcpy(dest, "");
    test_ft_strlcat(dest, "world", 5);

    strcpy(dest, "Hello");
    test_ft_strlcat(dest, "", 10);

    strcpy(dest, "Hello");
    test_ft_strlcat(dest, " world", 50);

    return 0;
}