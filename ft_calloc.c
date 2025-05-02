#include <stdlib.h> 
#include <stdio.h>
#include <string.h>

void	*ft_calloc( size_t elem_c, size_t elem_s)
{
	size_t	i;
	size_t	total;
	unsigned char	*dest;

	i = 0;
	if (elem_s != 0 && elem_c > elem_s / (size_t)-1)
		return (NULL);
	total = elem_c * elem_s;
	dest = (unsigned char *)malloc(total);
	if (!dest)
		return (NULL);
	while(i < total)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

void print_bytes(const void *ptr, size_t size) {
    const unsigned char *bytes = (const unsigned char *)ptr;
    for (size_t i = 0; i < size; i++) {
        printf("%02x ", bytes[i]);
    }
    printf("\n");
}

int main() {
   printf("=== TEST ft_calloc - Overflow ===\n\n");

    size_t count = (size_t)-1;
    size_t size = 2;

    void *ptr = ft_calloc(count, size);

    if (ptr == NULL) {
        printf("✅ ft_calloc a correctement renvoyé NULL (overflow détecté).\n");
    } else {
        printf("❌ ft_calloc n'a pas détecté l'overflow !\n");
        free(ptr); // éviter les fuites si jamais il y a une vraie alloc
    }

    return 0;
}