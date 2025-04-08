#include <stdio.h>
#include <ctype.h>

int ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return 1;
	else
		return 0;
}

void main(int argc, char **argv)
{
	printf("%d\n", ft_isdigit(argv[1][0]));
	printf("%d\n", isdigit(argv[1][0]));
}
