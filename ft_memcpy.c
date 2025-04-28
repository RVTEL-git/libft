#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void *ft_memcpy(void *destination, const void *source, size_t size)
{
	size_t i;
	unsigned char *dest;
	const unsigned char *src;

	i = 0;
	dest = (unsigned char *)destination;
	src = (const unsigned char *)source;
	while(i < size)
	{
		dest[i] = src[i];
		i++;
	}
	return(destination);
}

// Structure pour tester la copie de structures
typedef struct {
    int a;
    float b;
    char c;
} TestStruct;

int main() 
{
    printf("=== TEST ft_memcpy vs memcpy ===\n\n");

    // Test avec char
    char src_char[] = "Piscine 42!";
    char dst_char_std[50];
    char dst_char_ft[50];
    memcpy(dst_char_std, src_char, sizeof(src_char));
    ft_memcpy(dst_char_ft, src_char, sizeof(src_char));
    printf("Char - memcpy   : %s\n", dst_char_std);
    printf("Char - ft_memcpy: %s\n", dst_char_ft);
    printf("\n");

    // Test avec int
    int src_int[] = {10, 20, 30, 40, 50};
    int dst_int_std[5];
    int dst_int_ft[5];
    memcpy(dst_int_std, src_int, sizeof(src_int));
    ft_memcpy(dst_int_ft, src_int, sizeof(src_int));
    printf("Int  - memcpy   : ");
    for (int i = 0; i < 5; i++) printf("%d ", dst_int_std[i]);
    printf("\n");
    printf("Int  - ft_memcpy: ");
    for (int i = 0; i < 5; i++) printf("%d ", dst_int_ft[i]);
    printf("\n\n");

    // Test avec float
    float src_float[] = {3.14f, 2.71f, 1.61f};
    float dst_float_std[3];
    float dst_float_ft[3];
    memcpy(dst_float_std, src_float, sizeof(src_float));
    ft_memcpy(dst_float_ft, src_float, sizeof(src_float));
    printf("Float - memcpy   : ");
    for (int i = 0; i < 3; i++) printf("%.2f ", dst_float_std[i]);
    printf("\n");
    printf("Float - ft_memcpy: ");
    for (int i = 0; i < 3; i++) printf("%.2f ", dst_float_ft[i]);
    printf("\n\n");

    // Test avec double
    double src_double[] = {1.234, 5.678, 9.1011};
    double dst_double_std[3];
    double dst_double_ft[3];
    memcpy(dst_double_std, src_double, sizeof(src_double));
    ft_memcpy(dst_double_ft, src_double, sizeof(src_double));
    printf("Double - memcpy   : ");
    for (int i = 0; i < 3; i++) printf("%.4f ", dst_double_std[i]);
    printf("\n");
    printf("Double - ft_memcpy: ");
    for (int i = 0; i < 3; i++) printf("%.4f ", dst_double_ft[i]);
    printf("\n\n");

    // Test avec struct
    TestStruct src_struct = {42, 3.14f, 'Z'};
    TestStruct dst_struct_std;
    TestStruct dst_struct_ft;
    memcpy(&dst_struct_std, &src_struct, sizeof(TestStruct));
    ft_memcpy(&dst_struct_ft, &src_struct, sizeof(TestStruct));
    printf("Struct - memcpy   : {a: %d, b: %.2f, c: %c}\n",
           dst_struct_std.a, dst_struct_std.b, dst_struct_std.c);
    printf("Struct - ft_memcpy: {a: %d, b: %.2f, c: %c}\n",
           dst_struct_ft.a, dst_struct_ft.b, dst_struct_ft.c);

    return 0;
}
