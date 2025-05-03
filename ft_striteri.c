#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	while(s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

void	ft_to_upper(unsigned int	i, char	*c)
{
	c[i] = c[i] - 32;
}

int	main()
{
	char	test[] = "a b c";
	ft_striteri(test, ft_to_upper);
	printf("%s", test);
	return (0);
}