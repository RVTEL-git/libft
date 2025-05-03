#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i] != '\0')
		i++;
	return i;
}

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char	*dup;

	i = 0;
	dup = (char *)malloc(sizeof(char) * (ft_strlen((char	*)s) + 1));
	if(!dup)
		return (NULL);
	while (s[i])
	{
		dup[i] = f(i, s[i]);
		i++;
	}
	dup[i] = '\0';
	return(dup);
}

char	func(unsigned int i, char c)
{
	(void) i;
	return (c + 1);
}

int	main()
{
	printf("%s",ft_strmapi("abc", func));
	return (0);
}