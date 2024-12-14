#include <stdio.h>
#include "ft_printf.h"

int main()
{
    int original_printf_result;
    int ft_printf_result;

    // Test with a simple string
    original_printf_result = printf("Original printf: Hello, World!\n");
    ft_printf_result = ft_printf("ft_printf: Hello, World!\n");
    printf("Original printf returned: %d\n", original_printf_result);
    printf("ft_printf returned: %d\n", ft_printf_result);

    // Test with a character
    original_printf_result = printf("Original printf: %c\n", 'A');
    ft_printf_result = ft_printf("ft_printf: %c\n", 'A');
    printf("Original printf returned: %d\n", original_printf_result);
    printf("ft_printf returned: %d\n", ft_printf_result);

    // Test with a string
    original_printf_result = printf("Original printf: %s\n", "Test String");
    ft_printf_result = ft_printf("ft_printf: %s\n", "Test String");
    printf("Original printf returned: %d\n", original_printf_result);
    printf("ft_printf returned: %d\n", ft_printf_result);

    // Test with a pointer
    int *ptr = NULL;
    original_printf_result = printf("Original printf: %p\n", (void *)ptr);
    ft_printf_result = ft_printf("ft_printf: %p\n", (void *)ptr);
    printf("Original printf returned: %d\n", original_printf_result);
    printf("ft_printf returned: %d\n", ft_printf_result);

    // Test with an integer
    original_printf_result = printf("Original printf: %d\n", 42);
    ft_printf_result = ft_printf("ft_printf: %d\n", 42);
    printf("Original printf returned: %d\n", original_printf_result);
    printf("ft_printf returned: %d\n", ft_printf_result);

    // Test with a negative integer
    original_printf_result = printf("Original printf: %d\n", -42);
    ft_printf_result = ft_printf("ft_printf: %d\n", -42);
    printf("Original printf returned: %d\n", original_printf_result);
    printf("ft_printf returned: %d\n", ft_printf_result);

    // Test with a mix of formats
    original_printf_result = printf("Original printf: %s %d %c %p\n", "Mix", 123, 'X', (void *)ptr);
    ft_printf_result = ft_printf("ft_printf: %s %d %c %p\n", "Mix", 123, 'X', (void *)ptr);
    printf("Original printf returned: %d\n", original_printf_result);
    printf("ft_printf returned: %d\n", ft_printf_result);

    return 0;
}
