#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

char *ft_strdup(char *src)
{
	char	*dup;
	int	i;

	i = 0;
	dup = (char *)malloc(ft_strlen(src) * sizeof(char) + 1);
	while(src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int	main(void)
{
	char	*src;
	char	*copy;

	src = "test1";
	copy = ft_strdup(src);
	printf("%s", copy);
	free(copy);
	return(0);
}
