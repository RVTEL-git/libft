#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;

	i = 0;
	if (s == NULL)
		return (NULL);
	sub = (char *)malloc(sizeof(char) * len);
	if (!sub)
		return (NULL);
	while (i < len)
	{
		sub[i] = s[start];
		i++;
		start++;
	}
	sub[i] = '\0';
	return (sub);
}

void simple_test(const char *s, unsigned int start, size_t len, const char *expected)
{
    char *result = ft_substr(s, start, len);

    if (result && expected && strcmp(result, expected) == 0)
        printf("OK: \"%s\" [%u:%zu] -> \"%s\"\n", s, start, len, result);
    else if (!result && !expected)
        printf("OK: NULL input -> NULL output\n");
    else
        printf("FAIL: \"%s\" [%u:%zu] -> \"%s\" (got \"%s\")\n",
               s ? s : "NULL", start, len, expected ? expected : "NULL", result ? result : "NULL");

    free(result);
}

int main(void)
{
    simple_test("hello world", 0, 5, "hello");
    simple_test("hello world", 6, 5, "world");
    simple_test("hello", 2, 10, "llo");
    simple_test("hello", 0, 0, "");
    simple_test("hello", 5, 1, "");
    simple_test("hello", 6, 2, "");
    simple_test("", 0, 10, "");
    simple_test(NULL, 0, 5, NULL);

    return 0;
}