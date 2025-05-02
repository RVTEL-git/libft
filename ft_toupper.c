#include <ctype.h>
#include <stdio.h>

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
	{	c = c - 32;
		return (c);
	}
	else
		return (c);
}

void	test_ft_toupper(int c)
{
	int	mine;
	int	real;

	mine = ft_toupper(c);
	real = toupper(c);
	if (mine == real)
		printf("PASS (%c) -> real = %d | mine = %d\n", real, real, mine);
	else
		printf("FAIL (%c)\n Expected : %d | got : %d\n", real, real, mine);
}

int	main()
{
	test_ft_toupper(97);
	test_ft_toupper(96);
	test_ft_toupper(0);
	test_ft_toupper(115);
	test_ft_toupper(76);
	test_ft_toupper(110);
	test_ft_toupper(134343);
	test_ft_toupper(123);
	test_ft_toupper(122);
	return (0);
}