#include <string.h>
#include <stdio.h>

//void *ft_memmove(void *dest, const void *src, size_t n)

int main()
{
	int	source[7] = {0, 1, 2, 3, 4, 5, 6};
	int	destination[7];
	int i = 0;
	
	memmove(destination, source, sizeof(int) *7);
	while(i < 7)
	{
		printf("destination[%d] = %d\n", i, destination[i]);
		i++;
	}
	i = 0;
	while(i < 7)
	{
		printf("source[%d] = %d\n", i, source[i]);
		i++;
	}
	return 0;
}
