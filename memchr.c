#include <string.h>
#include <stdio.h>

void *ft_memchr(const void *s, int c, size_t n)
{
	unsigned long	i;
	unsigned char *haystack;
	unsigned char *find;

	haystack = (unsigned char *)s;
	i = 0;
	while (i < n && haystack[i])
	{
		if (haystack[i] == c)
			return (find = &haystack[i]);
		i++;
	}
	return(0);
}

int main() 
{
	char data[] = {'q', 'r', 's', 't', 'p', 'a', 'x'};
	char *pos = ft_memchr(data, 't',7);

	printf("pos[0] = %c\n", pos[0]);
	printf("pos[1] = %c\n", pos[1]);

	return 0;
 }