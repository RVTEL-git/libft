#include <ctype.h>
#include <stdio.h>

int ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return 1;
	else
		return 0;
}

void	main(int argc, char **argv)
{
	printf("%d\n", ft_isalpha(argv[1][0]));
	printf("%d\n", isalpha(argv[1][0]));
}
