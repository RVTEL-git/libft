#include <stdio.h>
#include <string.h>
#include <stdlib.h>

size_t strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char *ft_join(char *joined, const char *s1, const char *s2, size_t s1_len, size_t s2_len)
{
	unsigned int	i;

	i = 0;
	while (i < s1_len)
	{
		joined[i] = s1[i];
		i++;
	}	
	i = 0;
	while (i < s2_len)
	{
		joined[s1_len] = s2[i];
		s1_len++;
		i++;
	}
	joined[s1_len + s2_len] = '\0';
	return (joined);
}
char *ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1|| !s2)
		return (NULL);
	s1_len = strlen(s1);
	s2_len = strlen(s2);
	joined = (char *)malloc(sizeof(char) * (s1_len + s2_len) + 1);
	if (!joined)
		return (NULL);
	joined = ft_join(joined, s1, s2, s1_len, s2_len);
	return (joined);
}

void simple_test(const char *s1, const char *s2, const char *expected)
{
    char *result = ft_strjoin(s1, s2);

    if (result && expected && strcmp(result, expected) == 0)
        printf("OK: \"%s\" + \"%s\" -> \"%s\"\n", s1, s2, result);
    else if (!result && !expected)
        printf("OK: NULL input -> NULL output\n");
    else
        printf("FAIL: \"%s\" + \"%s\" -> expected \"%s\", got \"%s\"\n",
               s1 ? s1 : "NULL", s2 ? s2 : "NULL",
               expected ? expected : "NULL",
               result ? result : "NULL");

    free(result);
}

int main(void)
{
    simple_test("Hello", "World", "HelloWorld");
    simple_test("", "World", "World");
    simple_test("Hello", "", "Hello");
    simple_test("", "", "");
    simple_test(NULL, "test", NULL);  // Cas non défini, à adapter selon ta fonction
    simple_test("test", NULL, NULL);  // Cas non défini, à adapter selon ta fonction
    simple_test(NULL, NULL, NULL);    // Cas non défini, à adapter selon ta fonction

    return 0;
}