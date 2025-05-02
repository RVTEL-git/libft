#include <ctype.h>
#include <stdio.h>

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
	{	c = c + 32;
		return (c);
	}
	else
		return (c);
}

void	test_ft_tolower(int c)
{
	int	mine;
	int	real;

	mine = ft_tolower(c);
	real = tolower(c);
	if (mine == real)
		printf("PASS (%c) -> real = %d | mine = %d\n", real, real, mine);
	else
		printf("FAIL (%c)\n Expected : %d | got : %d\n", real, real, mine);
}

int	main()
{
	test_ft_tolower(65);
	test_ft_tolower(66);
	test_ft_tolower(0);
	test_ft_tolower(70);
	test_ft_tolower(76);
	test_ft_tolower(110);
	test_ft_tolower(134343);
	test_ft_tolower(123);
	test_ft_tolower(122);
	return (0);
}