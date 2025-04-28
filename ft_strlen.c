#include <string.h>
#include <stdio.h>

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i] != '\0')
		i++;
	return i;
}

int main(int argc, char **argv)
{
	printf("strlen = %d\n", strlen(argv[1]));
	printf("ft_strlen = %d\n", ft_strlen(argv[1]));
	return 0;
}
